.model small   
.data
    prompt db "Enter an integer: $"
    positive_msg db "The number is positive.$"
    negative_msg db "The number is negative.$"
    zero_msg db "The number is zero.$"
    num db 0
.code
main:
    mov ah, 9
    lea dx, prompt
    int 21h       
    mov dx , 0000h
    mov ah, 1
    int 21h
    cmp al , '-'
    je negative
    cmp al , 0
    je zero
    jmp positive
positive:                           
    mov ah, 9
    lea dx, positive_msg
    int 21h
    jmp exit_program
negative:    
    int 21h
    mov ah, 9
    lea dx, negative_msg
    int 21h
    jmp exit_program
zero:
    mov ah, 9
    lea dx, zero_msg
    int 21h
exit_program:
    mov ah, 4Ch
    int 21h
end main
