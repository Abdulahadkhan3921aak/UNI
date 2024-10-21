.model small

.stack 100h

.data
file_name db "testing.txt",0
buffer db 5000 dup(?)
text db "This is the text to write"
handle dw ?
.code

main proc
  call data_segment 
  ;lea dx , file_name
  ;push dx
  ;call create_file
  ;call close_file        
  lea dx , file_name
  push dx 
  call open_file_to_write
  lea dx , text
  push dx
  call write_to_file
  call close_file 
  call exit
  main endp


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
  pop dx
  mov cx , 25
  mov ax , 0
  mov ah , 40h
  mov bx , handle
  int 21h
  push di
  ret
  write_to_file endp

exit proc
  mov ah , 4ch
  int 21h
  ret
  exit endp