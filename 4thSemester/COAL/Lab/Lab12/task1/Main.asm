.386
.model flat, stdcall
.stack 4096

ExitProcess PROTO, dwExitCode:DWORD
WriteConsoleA PROTO, hConsoleOutput:DWORD, lpBuffer:PTR BYTE, nNumberOfCharsToWrite:DWORD, lpNumberOfCharsWritten:PTR DWORD, lpReserved:DWORD
ReadConsoleA PROTO, hConsoleInput:DWORD, lpBuffer:PTR BYTE, nNumberOfCharsToRead:DWORD, lpNumberOfCharsRead:PTR DWORD, lpReserved:DWORD
GetStdHandle PROTO, nStdHandle:DWORD

STD_OUTPUT_HANDLE equ -11
STD_INPUT_HANDLE equ -10

.data
myList DWORD 2, 3, 5, 8
sometext BYTE "Hello, World!", 0
singleChar BYTE ?
inputBuffer BYTE 128 dup(?)
outputBuffer BYTE 128 dup(?)
hConsoleOutput DWORD ?
hConsoleInput DWORD ?
charsWritten DWORD ?
charsRead DWORD ?

number1 BYTE ?
number2 BYTE ?
sum BYTE 0

.code
stdOut PROC uses ebx ecx edx, pText:PTR BYTE
    invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConsoleOutput, eax

    mov ecx, pText
    mov edx, 0
    ; Find length of string
    find_length:
        mov al, BYTE PTR [ecx+edx]
        cmp al, 0
        je length_found
        inc edx
        jmp find_length
    length_found:

    invoke WriteConsoleA, hConsoleOutput, pText, edx, addr charsWritten, 0
    ret
stdOut ENDP

printChar PROC uses eax edx, pChar:PTR BYTE
    invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConsoleOutput, eax

    mov edx, 1
    invoke WriteConsoleA, hConsoleOutput, pChar, edx, addr charsWritten, 0
    ret
printChar ENDP

readChar PROC uses eax edx, pChar:PTR BYTE
    invoke GetStdHandle, STD_INPUT_HANDLE
    mov hConsoleInput, eax

    invoke ReadConsoleA, hConsoleInput, pChar, 3, addr charsRead, 0
    ret
readChar ENDP

readLine PROC uses eax edx, pBuffer:PTR BYTE
    invoke GetStdHandle, STD_INPUT_HANDLE
    mov hConsoleInput, eax

    invoke ReadConsoleA, hConsoleInput, pBuffer, 128, addr charsRead, 0
    ; Replace the CRLF with null terminator
    mov eax, charsRead
    dec eax
    mov BYTE PTR [pBuffer+eax-1], 0
    ret
readLine ENDP

; Procedure to convert a DWORD to string
dwtoa PROC uses eax ebx ecx edx, value:DWORD, pBuffer:PTR BYTE
    mov eax, value
    mov ecx, 10
    lea ebx, [pBuffer+128] ; End of buffer
    mov BYTE PTR [ebx], 0 ; Null-terminate the string
    dec ebx
convert_loop:
    xor edx, edx
    div ecx
    add dl, '0'
    mov BYTE PTR [ebx], dl
    dec ebx
    test eax, eax
    jnz convert_loop
    inc ebx
    ret
dwtoa ENDP

printReg PROC uses eax edx, regValue:DWORD
    lea edx, outputBuffer
    invoke dwtoa, regValue, edx
    invoke stdOut, edx
    ret
printReg ENDP

printVal PROC uses eax edx, regValue:DWORD
    lea edx, outputBuffer
    invoke stdOut, edx
    ret
printVal ENDP

main PROC
    
    ;; this is task 1
    ;
    ;; Print whole text
    ;;invoke stdOut, addr sometext
    ;  
    ;; this is task 2
    ;
    ;; Read a line of input from the user
    ;invoke readLine, addr inputBuffer
    ;; Print the line of input
    ;invoke stdOut, addr inputBuffer
    
    
    
    ; this is task 3


    invoke readChar , addr number1
    invoke readChar , addr number2
    sub number1 , '0'
    sub number2 , '0'
    mov ebx , 0
    mov bh , number1
    add bh , number2
    cmp bh , 10
    jl printbh
    mov bl , bh
    sub bh , 10
    cmp bh , 0
    jl set_bhToZero
    bl_digit:
    sub bl , bh
    sub bl , 9
    cmp bl , 0
    jl set_blToZero
    afterbl:
    add bh , '0'
    add bl , '0'
    mov number1 , bh
    mov number2 , bl
    invoke printChar , addr number2
    invoke printChar , addr number1
    jmp quit
    
    
    set_bhToZero:
    mov bh , 0
    jmp bl_digit
    
    set_blToZero:
    mov bl , 0
    jmp afterbl
    
    printbh:
    add bh , '0'
    mov sum , bh
    invoke printChar , addr sum
    
    quit:
    invoke ExitProcess, 0
main ENDP

END main
