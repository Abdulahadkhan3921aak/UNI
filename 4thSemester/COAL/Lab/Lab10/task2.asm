.model small

.stack 100h

.data
file_name db "testing.txt",0
buffer db 5000 dup('$')
text db "This is the text to write" 
error_msg db "There is an error opening the file$"
handle dw ?
.code

main proc
  call data_segment 
  lea dx , file_name
  push dx 
  call open_file_to_read
  jc error
  push 4999
  call read_from_file
  call close_file
  call print_to_console 
  call exit
error:
  lea dx , error_msg
  mov ah , 09h
  int 21h
  call exit
  main endp

data_segment proc
  mov ax , @data
  mov ds , ax
  ret
  data_segment endp

close_file proc
  mov ah , 3eh
  int 21h
  ret
  close_file endp 

open_file_to_read proc 
  pop di
  pop dx
  mov ah , 3dh
  mov al , 2
  int 21h
  mov handle , ax
  push di
  ret
  open_file_to_read endp 

read_from_file proc
  pop di
  pop cx
  lea dx , buffer
  mov ax , 0
  mov ah , 3fh
  mov bx , handle
  int 21h
  push di
  ret
  read_from_file endp  

print_to_console proc
    pop di
    mov ah , 09h
    lea dx , buffer
    int 21h  
    push di  
    ret
    print_to_console endp

exit proc
  mov ah , 4ch
  int 21h
  ret
  exit endp