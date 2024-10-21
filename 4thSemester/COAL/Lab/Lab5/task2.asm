.model small
.stack 100h
.data
    msg db 10, 13, "Enter a decimal number: $"
    result db 10, 13, "ASCII value: $"
    input db ?
.code
main proc
    mov ax, @data
    mov ds, ax

    ; Display message to enter a decimal number
    lea dx, msg
    mov ah, 09h
    int 21h

    ; Read decimal number input from the user
    mov ah, 01h
    int 21h
    sub al, 30h ; Convert ASCII to binary
    mov input, al

    ; Convert decimal to ASCII using logical operators

    ; Using AND operation
    mov al, input
    and al, 00001111b ; Mask out the higher 4 bits
    add al, 30h ; Convert binary to ASCII
    mov dl, al

    ; Display the ASCII value for the first digit
    lea dx, result
    mov ah, 09h
    int 21h

    ; Using XOR operation
    mov al, input
    xor al, al ; Clear AL register
    or al, 00110000b ; Set higher 4 bits to ASCII '0'
    mov dl, al

    ; Display the ASCII value for the second digit
    mov dx, 00h
    mov dl, al
    mov ah, 02h
    int 21h

    mov ah, 4ch
    int 21h
main endp
end main
