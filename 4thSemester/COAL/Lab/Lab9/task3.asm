.model small
.stack 100h

.data 

size db 255  
str1 db 255 dup(?)
str2 db 255 dup(?) 
msg db "The copied string is :$"  

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
    lea dx , str2
    push dx
    mov bx , 0
    mov bl , size
    push bx
    call take_input
    call new_line
    lea dx , str1
    push dx
    lea dx , str2
    push dx
    call copy_str
    call new_line
    lea dx , msg
    mov ah , 09h
    int 21h
    lea dx , str1
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



copy_str proc
    pop di
    pop ax
    pop bx
    mov cx , 0
    mov si , bx
    cmp_loop:
    cmp [si] , '$'
    je copy
    inc si
    jmp cmp_loop
    copy: 
    mov bx , si
    copy_loop:
    mov si , ax
    cmp [si] , '$'
    je j_ret
    mov dl , [si]
    inc si
    mov ax , si
    mov si , bx
    mov [si] , dl
    inc si
    mov bx , si    
    jmp copy_loop
    j_ret:
    mov si , bx
    mov [si] , '$'
    push di
    ret
    copy_str endp