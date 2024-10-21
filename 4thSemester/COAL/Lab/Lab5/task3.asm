.model small
.stack 100h
.data
    msg db 10, 13, "Enter a number: $"
    result_odd db 10, 13, "The number is odd.$"
    result_even db 10, 13, "The number is even.$"
    input db ?
.code
main proc
    mov ax, @data
    mov ds, ax

    ; Display message to enter a number
    lea dx, msg
    mov ah, 09h
    int 21h

    ; Read number input from the user
    mov ah, 01h
    int 21h
    sub al, 30h ; Convert ASCII to binary
    mov input, al

    ; Check if the number is odd or even
    mov al, input
    and al, 00000001b ; Use AND operation with binary 00000001 to check the LSB
    cmp al, 0 ; Compare with 0 to check if LSB is 0 (even) or 1 (odd)
    je even
    jmp odd

even:
    ; Display result for even number
    lea dx, result_even
    mov ah, 09h
    int 21h
    jmp end_prog

odd:
    ; Display result for odd number
    lea dx, result_odd
    mov ah, 09h
    int 21h

end_prog:
    mov ah, 4ch
    int 21h
main endp
end main
