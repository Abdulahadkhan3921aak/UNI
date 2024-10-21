.386
.model flat, stdcall
option casemap:none
include \masm32\include\masm32rt.inc 
includelib \masm32\lib\masm32rt.lib
.data
float1 REAL4 10.5
float2 REAL4 5.25
result REAL4 ?
caption db "Result", 0
addition db "The Addition of 10.5 and 5.25 is: ", 0
subtraction db "The Subtraction of 10.5 and 5.25 is: ", 0
multiplication db "The Multiplication of 10.5 and 5.25 is: ", 0
division db "The Division of 10.5 and 5.25 is: ", 0
new_line db 13 , 10 , 0

.code
main:
    ; Addition
    fld float1
    fadd float2
    fstp result
    ; result = float1 + float2
    invoke StdOut , addr addition 
    print real4$(result) , 13 , 10
    ; Subtraction
    fld float1
    fsub float2
    fstp result
    invoke StdOut , addr (subtraction)
    print real4$(result) , 13 , 10
    ; Multiplication
    fld float1
    fmul float2
    fstp result
    invoke StdOut , addr multiplication
    print real4$(result), 13, 10
    ; Division
    fld float1
    fdiv float2
    fstp result
    invoke StdOut , addr division
    print real4$(result), 13, 10
    ; Exit
    invoke ExitProcess, 0
end main
