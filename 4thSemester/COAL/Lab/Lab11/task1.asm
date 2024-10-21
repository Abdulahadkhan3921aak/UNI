.model small
.stack 100h
.data
file db "testing.txt", 0
msg db "This text is appended to the file$"
.code
mov ax, @data
mov ds, ax
mov dx, offset file 
mov al, 2 
mov ah, 3dh
int 21h      

jc file_error
 
mov bx, ax
mov cx, 0 
mov dx, 0 
mov al, 2
mov ah, 42h
int 21h
mov cx, 33 
mov dx, offset msg 
mov ah, 40h 
int 21h          

mov ah, 3eh 
int 21h
mov ah, 4ch 
int 21h
file_error:                                                 

mov ah, 4ch 
int 21h       

end