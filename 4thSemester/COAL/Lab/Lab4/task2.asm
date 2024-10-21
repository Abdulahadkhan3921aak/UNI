.model small
.data
    prompt1 db 'Enter the first number: $'
    prompt2 db 'Enter the second number: $'
    greater_msg db 'Number 1 is greater.$'
    not_greater_msg db 'Number 2 is greater.$'
    num1 db 0
    num2 db 0

.code
main:
    ; Prompt user for the first number
    mov ah, 9
    lea dx, prompt1
    int 21h

    ; Read user input for the first number
    mov ah, 1
    int 21h
    sub al, '0'
    mov num1, al

    ; Prompt user for the second number
    mov ah, 9
    lea dx, prompt2
    int 21h

    ; Read user input for the second number
    mov ah, 1
    int 21h
    sub al, '0'
    mov num2, al

    ; Compare the two numbers
    mov cl , num1
    cmp cl, num2
    jg number1_greater

    ; Print message if number 2 is greater
    mov ah, 9
    lea dx, not_greater_msg
    int 21h
    jmp exit_program

number1_greater:
    ; Print message if number 1 is greater
    mov ah, 9
    lea dx, greater_msg
    int 21h

exit_program:
    ; Exit program
    mov ah, 4Ch
    int 21h
end main
