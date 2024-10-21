.model small
.stack 100h
.data
msg1 db "Enter a number : $" 
msg2 db "The product of the 2 numbers is : $"
msg3 db "The Sum of the 2 numbers is : $"
msg4 db "The Differience of the 2 numbers is : $"
msg5 db "The quotient and remainder of the division of the numbers is : $"
num1 db ?
num2 db ?
sum db ?
dif db ?
pro db ?
q db ?
r db ?
sign db ?

.code 

main proc
    mov ax , @data
    mov ds , ax
    call take_input 
    mov bx , 0
    mov bl , num1
    push bx
    mov bx , 0
    mov bl , num2
    push bx
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
    ret
    take_input endp  

calculate proc
    pop bx
    mov si , bx
    pop bx
    mov dx , bx
    pop bx
    mov cx , bx
    mov al , cl
    mul dl
    mov pro , al
    mov al , cl
    add al , dl
    mov sum , al
    mov al , dl
    div cl
    mov r , ah
    mov q , al
    cmp cl , dl
    jl negative
    mov al , cl
    sub al , dl
    mov dif , al
    mov sign , '0'
    mov bx , si
    push bx
    ret
    negative:
    mov sign , '-'
    mov al , dl
    sub al , cl
    mov dif , al
    mov bx , si
    push bx    
    ret
    calculate endp 

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


print_output proc
    lea dx , msg2
    call print_string
    mov al , pro
    AAM
    mov dl , ah
    mov dh , al
    add dl , 30h
    call print_char
    mov dl , dh
    add dl , 30h 
    call print_char 
    call new_line
    lea dx , msg3
    call print_string
    mov al , sum
    AAM
    mov dl , ah
    mov dh , al
    add dl , 30h
    call print_char
    mov dl , dh
    add dl , 30h
    call print_char 
    call new_line
    lea dx , msg4
    call print_string
    mov dl , sign
    call print_char
    mov dl , dif
    add dl , 30h
    call print_char 
    call new_line
    lea dx , msg5
    call print_string
    mov dl , q
    add dl , 30h 
    call print_char
    mov dl , ' '
    call print_char
    mov dl , ','
    call print_char
    mov dl , ' '
    call print_char
    mov dl , r 
    add dl , 30h
    call print_char
    ret
    print_output endp

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
