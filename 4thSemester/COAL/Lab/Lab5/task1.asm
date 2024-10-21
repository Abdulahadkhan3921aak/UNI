.model small
.stack 100h
.data
    msg1 db 10, 13, "Enter the first number: $"
    msg2 db 10, 13, "Enter the second number: $"
    result_and db 10, 13, "Result of AND operation: $"
    result_or db 10, 13, "Result of OR operation: $"
    result_xor db 10, 13, "Result of XOR operation: $"
    input1 db ?
    input2 db ?
.code
main proc
    mov ax, @data
    mov ds, ax

    ; Input first number
    lea dx, msg1
    mov ah, 09h
    int 21h
    mov ah, 01h
    int 21h
    sub al, 30h ; Convert ASCII to binary
    mov input1, al

    ; Input second number
    lea dx, msg2
    mov ah, 09h
    int 21h
    mov ah, 01h
    int 21h
    sub al, 30h ; Convert ASCII to binary
    mov input2, al

    ; Perform AND operation
    lea dx, result_and
    mov ah, 09h
    int 21h
    mov al, input1
    and al, input2
    AAM
    mov dx, 00h
    mov bh, ah
    mov bl, al 
    mov ah, 02h
    mov dl, bh 
    add dl, 30h
    int 21h
    mov dl, bl
    add dl, 30h
    int 21h
    ; Perform OR operation
    lea dx, result_or
    mov ah, 09h
    int 21h
    mov al, input1
    or al, input2
    AAM
    mov dx, 00h
    mov bh, ah
    mov bl, al 
    mov ah, 02h
    mov dl, bh 
    add dl, 30h
    int 21h
    mov dl, bl
    add dl, 30h
    int 21h

    ; Perform XOR operation
    lea dx, result_xor
    mov ah, 09h
    int 21h
    mov al, input1
    xor al, input2                         
    AAM
    mov dx, 00h
    mov bh, ah
    mov bl, al 
    mov ah, 02h
    mov dl, bh 
    add dl, 30h
    int 21h
    mov dl, bl
    add dl, 30h
    int 21h

    mov ah, 4ch
    int 21h
main endp
end main
