.model small

.stack 100h

.data
file_name db "test.txt",0
buffer db 5 dup(?)
nums db 10 dup("$")
handle dw ?
.code

main proc
  call data_segment
  lea dx , nums
  push dx
  call take_input 
  lea dx , file_name
  push dx 
  call open_file_to_write
  jc create_file_on_error
write_to_file_lable:
  lea dx , nums
  push dx
  call write_to_file
  call close_file 
  call exit
create_file_on_error:
  lea dx , file_name
  push dx
  call create_file
  jmp write_to_file_lable
  main endp

take_input proc
    pop di
    pop si
    mov cx , 5
    mov ah , 01h
    loop_lable:
        int 21h
        mov [si] , al
        add si , 2       
        loop loop_lable
    push di
    ret
    take_input endp

data_segment proc
  mov ax , @data
  mov ds , ax
  ret
  data_segment endp

create_file proc
  pop di
  pop dx        
  mov ah , 3ch
  int 21h
  mov handle , ax
  push di
  ret
  create_file endp 

close_file proc
  mov ah , 3eh
  int 21h
  ret
  close_file endp 

open_file_to_write proc 
  pop di
  pop dx
  mov ah , 3dh
  mov al , 2
  int 21h
  mov handle , ax
  push di
  ret
  open_file_to_write endp 

write_to_file proc
  pop di
  pop si
  mov cx , 6
  mov es , cx
  loop_lable2:
  mov cx, 0 
  mov dx, 0 
  mov al, 2 
  mov ah, 42h 
  int 21h
  mov dx , 0
  mov dx , si
  mov cx , 1
  mov ax , 0
  mov ah , 40h
  mov bx , handle
  int 21h
  add si , 2
  mov cx , es
  dec cx
  mov es , cx
  loop loop_lable2
  push di
  ret
  write_to_file endp

exit proc
  mov ah , 4ch
  int 21h
  ret
  exit endp