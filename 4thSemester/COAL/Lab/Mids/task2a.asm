.model small
.stack 100h
.data
msg1 db "Enter a string : $" 
msg2 db "The reverse string is : $"
msg3 db "The string is palindrome$"
msg4 db "The string is not palindrome$"
palindrome db 1
off db 0
size db 60
SSize db ?
string db size dup('$')
loc1 dw ?
loc2 dw ?


.code 
main proc
    mov ax , @data
    mov ds , ax
    call take_input
    call new_line
    call print_reverse_string
    call new_line  
    call check_palindrom 
    call exit
    main endp


take_input proc
    mov ah , 09h
    lea dx , msg1
    int 21h
    mov cx , 0
    mov cl , size
    dec cx
    mov ah , 01h
    mov si , offset String
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
    mov al , size
    mov bl , cl
    sub al , cl
    sub al , 2
    mov SSize , al     
    ret
    take_input endp  


check_palindrom proc
    cmp palindrome , 1
    je yes
    lea dx , msg4
    jmp print
    yes:
    lea dx , msg3    
    print:
    mov ah , 09h
    int 21h 
    ret
    check_palindrom endp 

exit proc
    mov ah , 4ch
    int 21h
    ret
    exit endp

new_line proc 
    mov dl , 10
    call print_char
    mov dl , 13
    call print_char
    ret
    new_line endp

print_reverse_string proc
    mov ah , 09h
    lea dx , msg2
    int 21h
    mov si , offset String
    mov loc1 , si
    mov ax , 0
    mov al , SSize
    add si , ax
    mov loc2 , si
    mov cx , 0
    mov cl , SSize
    inc cx
    mov ah , 02h
    loop2:
    mov si , loc1
    mov bl , [si]
    mov si , loc2
    mov dl , [si]
    int 21h
    dec loc2
    inc loc1
    cmp dl , bl
    jne not_palindrom    
    loop loop2
    ret
    not_palindrom:
        mov palindrome , 0
        dec cx
        cmp cl , 0
        jg loop2
    ret
    print_reverse_string endp

print_char proc
    mov ah , 02h
    int 21h
    ret
    print_char endp
