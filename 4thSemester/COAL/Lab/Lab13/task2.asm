.386
.model flat, stdcall
option casemap:none

include \masm32\include\masm32rt.inc
includelib \masm32\lib\masm32rt.lib


.data
Num   DWORD   42
floatNum REAL4   ?
intNum DWORD   ?
msg db "The number 42 from int is converted into float and back into int : " ,10 , 13 , 0

.code
main:
    ; Convert integer to float
    mov     eax, Num
    mov     floatNum, eax
    fild    floatNum
    fstp    floatNum
    ; floatNum now holds the floating-point representation of intNum

    ; Convert float to integer
    fld     floatNum
    fistp   intNum
    ; intNum now holds the integer representation of floatNum

    invoke StdOut , addr msg
    print real4$(floatNum),13,10
    print str$(intNum),13,10
    ; Display or further operations with intNum and floatNum

    ; Exit
    invoke  ExitProcess, 0
end main
