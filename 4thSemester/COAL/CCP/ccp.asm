.386
.model flat, stdcall
option casemap:none

include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\masm32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\masm32.lib

.data
    filename db "database.txt", 0
    menu db "1. Add Record", 0dh, 0ah, "2. Display Records", 0dh, 0ah, "3. Exit", 0dh, 0ah, "$"
    prompt_choice db "Enter your choice: $"
    prompt_sr db "Enter Sr#: $"
    prompt_name db "Enter Name: $"
    prompt_family db "Enter Family Members: $"
    prompt_water db "Enter Water Consumption: $"
    prompt_floor db "Enter Floor Consumption: $"
    prompt_pulses db "Enter Pulses Consumption: $"
    newline db 0dh, 0ah, "$"
    record_format db "%d,%s,%d,%d,%d,%d", 0
    buffer db 256 dup(0)

.data?
hStdOut HANDLE ?
hFile HANDLE ?
bytesWritten DWORD ?
bytesRead DWORD ?
arr_record db 256 dup(0)

.code
start:
    invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hStdOut, eax

menu_loop:
    ; Display menu
    lea edx, menu
    call print_text

    ; Get user choice
    lea edx, prompt_choice
    call print_text
    call get_input
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
    lea edx, prompt_sr
    call print_text
    call get_integer
    mov di, ax
    movzx edx, di
    invoke dwtoa, edx, addr buffer
    invoke lstrcat, addr arr_record, addr buffer
    invoke lstrcat, addr arr_record, addr ","

    ; Prompt for Name
    lea edx, prompt_name
    call print_text
    call get_string
    invoke lstrcat, addr arr_record, addr buffer
    invoke lstrcat, addr arr_record, addr ","

    ; Prompt for Family Members
    lea edx, prompt_family
    call print_text
    call get_integer
    movzx edx, ax
    invoke dwtoa, edx, addr buffer
    invoke lstrcat, addr arr_record, addr buffer
    invoke lstrcat, addr arr_record, addr ","

    ; Prompt for Water Consumption
    lea edx, prompt_water
    call print_text
    call get_integer
    movzx edx, ax
    invoke dwtoa, edx, addr buffer
    invoke lstrcat, addr arr_record, addr buffer
    invoke lstrcat, addr arr_record, addr ","

    ; Prompt for Floor Consumption
    lea edx, prompt_floor
    call print_text
    call get_integer
    movzx edx, ax
    invoke dwtoa, edx, addr buffer
    invoke lstrcat, addr arr_record, addr buffer
    invoke lstrcat, addr arr_record, addr ","

    ; Prompt for Pulses Consumption
    lea edx, prompt_pulses
    call print_text
    call get_integer
    movzx edx, ax
    invoke dwtoa, edx, addr buffer
    invoke lstrcat, addr arr_record, addr buffer
    invoke lstrcat, addr arr_record, addr newline

    ; Open file for appending
    invoke CreateFile, addr filename, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL
    mov hFile, eax

    ; Move to the end of the file
    invoke SetFilePointer, hFile, 0, NULL, FILE_END

    ; Write record to file
    invoke WriteFile, hFile, addr arr_record, lstrlen(addr arr_record), addr bytesWritten, NULL

    ; Close file
    invoke CloseHandle, hFile

    ; Clear record buffer
    invoke lstrcpy, addr arr_record, addr ""
    jmp menu_loop

display_records:
    ; Open file for reading
    invoke CreateFile, addr filename, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
    mov hFile, eax

    ; Check if file was opened successfully
    cmp hFile, INVALID_HANDLE_VALUE
    je display_end

    ; Read and display records
    .repeat
        lea edx, buffer
        invoke ReadFile, hFile, edx, 256, addr bytesRead, NULL
        test eax, eax
        jz display_end

        ; Display record
        lea edx, buffer
        call print_text
    .until bytesRead == 0

display_end:
    ; Close file
    invoke CloseHandle, hFile
    jmp menu_loop

exit_program:
    invoke ExitProcess, 0

get_input PROC
    ; Get single character input from user
    invoke StdIn, addr buffer, 1
    mov al, byte ptr buffer
    ret
get_input ENDP

get_integer PROC
    ; Get integer input from user
    invoke StdIn, addr buffer, 10
    invoke atodw, addr buffer
    mov ax, cx
    ret
get_integer ENDP

get_string PROC
    ; Get string input from user
    invoke StdIn, addr buffer, 100
    ret
get_string ENDP

print_text PROC
    ; Print text to console
    invoke lstrlen, edx
    mov ecx, eax
    invoke WriteConsole, hStdOut, edx, ecx, addr bytesWritten, NULL
    ret
print_text ENDP

END start
