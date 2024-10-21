.model small
.data
    prompt1 db 'Enter the first number: $'
    prompt2 db 'Enter the second number: $'
    prompt3 db 'Enter the third number: $'
    max_msg db 'The maximum number is: $'
    num1 db 0
    num2 db 0
    num3 db 0

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

    ; Prompt user for the third number
    mov ah, 9
    lea dx, prompt3
    int 21h

    ; Read user input for the third number
    mov ah, 1
    int 21h
    sub al, '0'
    mov num3, al

    ; Compare the first two numbers  
    mov cl , num1
    cmp cl , num2
    jg first_two_greater

    ; If not greater, compare the third number   
    mov cl , num2
    cmp cl , num3
    jg print_max
    jmp print_max

first_two_greater:
    ; Compare the first two numbers
    mov cl , num1
    cmp cl , num3
    jg print_max
    jmp print_max

print_max:
    ; Print the maximum number
    mov ah, 9
    lea dx, max_msg
    int 21h

    ; Print the maximum number
    mov ah, 1
    mov al, num1
    int 21h

    ; Exit program
    mov ah, 4Ch
    int 21h
end main
