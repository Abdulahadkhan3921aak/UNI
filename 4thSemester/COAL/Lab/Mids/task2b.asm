.model small
.stack 100h
.data
msg1 db "Enter a number : $" 
msg2 db "The result is : $"
num1 db ?
num2 db ?
num3 db ?
answer db ?

sign db ?

.code 

main proc
    mov ax , @data
    mov ds , ax
    call take_input 
    call calculate
    call new_line
    call print_output  
    call exit
    main endp


take_input proc
    mov ah , 09h
    lea dx , msg1
    int 21h
    mov ah , 01h
    int 21h
    sub al , 30h
    mov num1 , al
    call new_line
    mov ah , 09h
    lea dx , msg1
    int 21h
    mov ah , 01h
    int 21h
    sub al , 30h
    mov num2 , al
    call new_line
    mov ah , 09h
    lea dx , msg1
    int 21h
    mov ah , 01h
    int 21h
    sub al , 30h
    mov num3 , al
    ret
    take_input endp  


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


print_string proc
    mov ah , 09h
    int 21h
    ret
    print_string endp

print_char proc
    mov ah , 02h
    int 21h
    ret
    print_char endp
                    
               
calculate proc    
    mov al , num1
    mov bl , num3
    mov cl , num3
    xor al , bl
    xor al , cl
    mov answer , al
    ret
    calculate endp    

print_output proc
    lea dx , msg2
    call print_string
    mov al , answer
    AAM
    mov cx , ax
    mov dl , ch
    add dl , 30h
    call print_char
    mov dl , cl
    add dl , 30h
    call print_char
    ret
    print_output endp