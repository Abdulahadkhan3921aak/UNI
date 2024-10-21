.model small
.stack 100h
.data
    filename db "database.txt", 0
    record_format db "%d %s %d %d %d", 0
    menu db "1. Add Record", 0dh, 0ah
         db "2. Display Records", 0dh, 0ah
         db "3. Exit", 0dh, 0ah, "$"
    prompt_choice db "Enter your choice: $"
    prompt_sr db "Enter Sr#: $"
    prompt_name db "Enter Name: $"
    prompt_family db "Enter Family Members: $"
    prompt_water db "Enter Water Consumption: $"
    prompt_floor db "Enter Floor Consumption: $"
    prompt_pulses db "Enter Pulses Consumption: $"
    record db 100 dup(0)

.code
main proc
    mov ax, @data
    mov ds, ax

    ; Display menu
menu_loop:
    mov ah, 09h
    lea dx, menu
    int 21h

    ; Get user choice
    mov ah, 09h
    lea dx, prompt_choice
    int 21h
    mov ah, 01h
    int 21h
    sub al, '0'
    mov bl, al

    ; Handle user choice
    cmp bl, 1
    je add_record
    cmp bl, 2
    je display_records
    cmp bl, 3
    je exit_program
    jmp menu_loop

add_record:
    ; Prompt for Sr#
    mov ah, 09h
    lea dx, prompt_sr
    int 21h
    call get_integer
    mov di, ax

    ; Prompt for Name
    mov ah, 09h
    lea dx, prompt_name
    int 21h
    call get_string
    lea si, record
    mov cx, di
    mov di, ax
    call copy_string

    ; Prompt for Family Members
    mov ah, 09h
    lea dx, prompt_family
    int 21h
    call get_integer
    mov di, ax

    ; Prompt for Water Consumption
    mov ah, 09h
    lea dx, prompt_water
    int 21h
    call get_integer
    mov di, ax

    ; Prompt for Floor Consumption
    mov ah, 09h
    lea dx, prompt_floor
    int 21h
    call get_integer
    mov di, ax

    ; Prompt for Pulses Consumption
    mov ah, 09h
    lea dx, prompt_pulses
    int 21h
    call get_integer
    mov di, ax

    ; Open file for appending
    mov ah, 3Ch
    mov cx, 0
    lea dx, filename
    int 21h
    mov bx, ax

    ; Write record to file
    lea dx, record
    mov cx, 100
    mov ah, 40h
    int 21h

    ; Close file
    mov ah, 3Eh
    int 21h
    jmp menu_loop

display_records:
    ; Open file for reading
    mov ah, 3Dh
    mov al, 0
    lea dx, filename
    int 21h
    mov bx, ax

    ; Read and display records
    mov ah, 3Fh
    lea dx, record
    mov cx, 100
    int 21h

    ; Display record
    mov ah, 09h
    lea dx, record
    int 21h

    ; Close file
    mov ah, 3Eh
    int 21h
    jmp menu_loop

exit_program:
    mov ah, 4Ch
    int 21h

get_integer proc
    ; Get integer input from user
    xor ax, ax
    mov ah, 01h
    int 21h
    sub al, '0'
    mov ah, 0
    ret
get_integer endp

get_string proc
    ; Get string input from user
    xor ax, ax
    mov ah, 0Ah
    lea dx, record
    int 21h
    ret
get_string endp

copy_string proc
    ; Copy string to record
    push di
    push si
    mov cx, 100
copy_loop:
    lodsb
    stosb
    loop copy_loop
    pop si
    pop di
    ret
copy_string endp

main endp
end main
