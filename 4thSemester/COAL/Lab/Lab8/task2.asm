.model small
.stack 100h
.data
    messg1 db "Enter a string : $"
    messg2 db "You entered 'a' this many time's : $"   
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
     cmp al , 'a'
     je entered_a
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
    mov dl , bl
    add dl , 30h
    int 21h

mov ah , 4ch
int 21h 

entered_a:  
    inc bl
    jmp gets
    