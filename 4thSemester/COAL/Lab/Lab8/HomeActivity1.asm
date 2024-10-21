.model small
.stack 100h
.data
    messg1 db "Enter number 1 to add ( max 2 digits )  : $"
    messg2 db "Enter number 2 to add ( max 2 digits )  : $"
    messg3 db "The Sum of the numbers is : $"
    sum dw ?
    greatest db ?
    digit db ?
    num1 dw ?
    num2 dw ?    
    size db 2
    
.code                  
mov ax , @data
mov ds , ax

mov ah , 09h
lea dx , messg1
int 21h

mov cx , 0
mov cl , size 
mov bl , 10
mov dx , 0
gets1:
    mov ah , 01h
    int 21h
    cmp al , 13
    je nummber2
    sub al , 30h
    mov offset digit , al
    mov ax , num1
    mul bl
    add al , digit
    mov offset num1 , ax
    inc dl
    loop gets1

nummber2:
    mov offset greatest , dl
    mov ah , 02h
    mov dl , 13
    int 21h
    mov dl , 10
    int 21h
 
    mov ah , 09h
    lea dx , messg2
    int 21h     
    mov cl , size 
    mov ah , 01h
    mov dx , 0
    
gets2:
    mov ah , 01h
    int 21h
    cmp al , 13
    je stopS
    sub al , 30h
    mov offset digit , al
    mov ax , num2
    mul bl
    add al , digit
    mov offset num2 , ax
    inc dl
    loop gets2    
     
stopS:
    cmp dl , greatest
    jg great
    mov ah , 02h
    mov dl , 13
    int 21h
    mov dl , 10
    int 21h
    
    mov ax , num1
    mov bx , num2
    mul bx
    mov bx , ax
    mov offset sum , bx
    mov ax , 1
    mov bl , 10       
    mov cx , 0
    mov cl , greatest
    cmp cl , 1
    jg decrees
    adjust:
        mul bl
        loop adjust
    mov bx , ax
    mov ax , sum
    div bl
    mov cl , al
    mov al , ah
    AAM
    mov bx , ax
    mov al , cl
    AAM
    mov cx , ax 
    
    mov ah , 09h
    lea dx , messg3
    int 21h        
    mov ah , 02h
    mov dl , ch
    add dl , 30h
    int 21h
    mov dl , cl
    add dl , 30h
    int 21h
    mov dl , bh
    add dl , 30h 
    int 21h
    mov dl , bl
    add dl , 30h
    int 21h

mov ah , 4ch
int 21h

great:
    mov offset greatest , dl
    jmp stopS 
decrees:
    dec cl
    jmp adjust   