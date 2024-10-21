.model small
.stack 100h
.data
    messg1 db "Enter a string : $"
    messg2 db "You entered : $"   
    size db 255  
.code                  
mov ax , @data
mov ds , ax
mov ah , 09h
lea dx , messg1
int 21h
mov cl , size 
mov ah , 01h
gets:
     int 21h
     cmp al , 13
     je stopS
     mov bl , al
     push bx
     loop gets
stopS:
    mov ah , 02h
    mov dl , 13
    int 21h
    mov dl , 10
    int 21h
    lea dx , messg2
    mov ah , 09h
    int 21h
    mov ah , 02h
    mov bx , cx
    mov cl , size
    sub cx , bx
putS:
    pop bx
    mov dl , bl
    int 21h
    loop putS

mov ah , 4ch
int 21h
    