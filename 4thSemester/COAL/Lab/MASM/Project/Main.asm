.model flat
.stack 100h
.data
board DB '1','2','3','4','5','6','7','8','9','$'
player DB 'X'
message DB 'Enter a number (1-9): $',0
newline DB 13,10,'$'
win_message DB 'Player X wins!$'

.CODE
main PROC
    ; Initialize data segment
    MOV AX, @DATA
    MOV DS, AX

    ; Main game loop
game_loop:
    CALL display_board
    CALL get_input
    CALL check_win
    ; Switch player
    CMP player, 'X'
    JNE switch_to_x
    MOV player, 'O'
    JMP game_loop
switch_to_x:
    MOV player, 'X'
    JMP game_loop

    ; Exit program
    MOV AX, 4C00h
    INT 21h
main ENDP

display_board PROC
    MOV SI, OFFSET board

    ; Display the board in 3x3 format
    MOV CX, 3
    PRINT_ROW:
        MOV DX, SI
        MOV AH, 09h
        INT 21h
        ADD SI, 1
        MOV DX, OFFSET newline
        MOV AH, 09h
        INT 21h
        LOOP PRINT_ROW

    RET
display_board ENDP

get_input PROC
    MOV DX, OFFSET message
    MOV AH, 09h
    INT 21h

    MOV AH, 01h
    INT 21h
    SUB AL, '0'   ; Convert ASCII to integer
    MOV BL, AL
    DEC BL        ; Convert 1-9 to 0-8
    MOV SI, OFFSET board
    ADD SI, BX

    MOV AL, player
    MOV [SI], AL

    RET
get_input ENDP

check_win PROC
    ; Check rows, columns, and diagonals for a win
    ; Example for rows:
    MOV SI, OFFSET board
    MOV CX, 3
    CHECK_ROW:
        MOV AL, [SI]
        CMP AL, [SI+1]
        JNE NEXT_ROW
        CMP AL, [SI+2]
        JNE NEXT_ROW
        ; If all three are the same
        MOV DX, OFFSET win_message
        MOV AH, 09h
        INT 21h
        MOV AX, 4C00h
        INT 21h
    NEXT_ROW:
        ADD SI, 3
        LOOP CHECK_ROW

    ; Check columns and diagonals similarly...

    RET
check_win ENDP

END main
