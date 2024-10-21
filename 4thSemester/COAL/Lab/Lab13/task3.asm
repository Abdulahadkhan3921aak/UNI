.386
.model flat, stdcall
option casemap:none

include \masm32\include\masm32rt.inc 
includelib \masm32\lib\masm32rt.lib

.data
floatNum REAL4   16.0
result   REAL4   ?
msg db "The Square root of the number 16.0 is : " , 13 , 10 , 0

.code
main:
    ; Square root of floating-point number
    fld     floatNum
    fsqrt
    fstp    result
    ; result = square root of floatNum

    ; Display or further operations with result
    invoke  StdOut, addr msg
    print real4$(result),13 , 10
    ; Exit
    invoke  ExitProcess, 0
end main
