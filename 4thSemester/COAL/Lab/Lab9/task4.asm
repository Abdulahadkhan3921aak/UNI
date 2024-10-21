.model small
.stack 100h

.data 

size db ?  
str1 db 255 dup(?) 
msg db "The length of the string is :$"  

.code

main proc
    mov ax , @data
    mov ds , ax
    mov ax , 0
    mov bx , 0
    mov bl , size
    lea dx , str1
    push dx
    push bx
    call take_input
    call new_line
    lea dx , str1
    push dx
    call length
    call new_line
    lea dx , msg
    mov ah , 09h
    int 21h
    mov ax , 0
    mov al , size
    AAM
    mov ch , al
    mov dl , ah
    add dl , 30h
    mov ah , 02h
    int 21h
    mov dl , ch
    add dl , 30h
    int 21h
    call exit
    main endp  
  

take_input proc
    mov cx , 0
    pop di
    pop bx
    mov cl , bl
    dec cx
    mov ah , 01h
    pop bx
    mov si , bx
    loop1:
    int 21h
    mov dx , 0
    mov dl , al
    cmp dl , 13
    je stop
    mov [si] , dx
    inc si
    loop loop1
    stop:
    mov [si] , '$'
    push di     
    ret
    take_input endp       

exit proc
    mov ah , 4ch
    int 21h
    ret
    exit endp  


new_line proc
    mov dl , 10
    mov ah , 02
    int 21h
    mov dl , 13
    int 21h
    ret
    new_line endp  



length proc
    pop di
    pop ax
    mov si , ax
    mov cx , 0
    length_loop:
    cmp [si] , '$'
    je j_ret
    inc si
    inc cx
    jmp length_loop    
    j_ret:
    mov size , cl
    push di
    ret
    length endp     


                   