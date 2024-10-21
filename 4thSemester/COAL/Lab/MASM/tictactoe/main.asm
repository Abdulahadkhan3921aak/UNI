INCLUDE Irvine32.inc

.data
board  db  '.', '.', '.'   ; Initialize the board with empty cells
       db  '.', '.', '.'
       db  '.', '.', '.'

player1 db 'X'
player2 db 'O'

inputMsg    db "Enter row and column (1-3): ", 0
drawMsg     db "It's a draw!", 0

.code
main PROC
    call    Clrscr              ; Clear the screen
    
    ; Display the initial board
    call    DisplayBoard
    
    mov     ebx, 0              ; Initialize player turn counter
    
    ; Main game loop
GameLoop:
    ; Get player input
    cmp     ebx, 0              ; Check whose turn it is
    je      Player1Input
    jmp     Player2Input

Player1Input:
    mov     edx, OFFSET player1
    call    GetInput
    mov     eax , 0
    mov     al , 'X'
    mov     [esi], eax
    inc     ebx
    jmp     CheckWinner

Player2Input:
    mov     edx, OFFSET player2
    call    GetInput
    mov     eax , 0
    mov     al , 'O'
    mov     [esi], eax
    dec     ebx
    jmp     CheckWinner

CheckWinner:
    ; Check for a winner
    ; Implement winner check logic here
    ; If a winner is found, jump to Player1Wins or Player2Wins
    CheckWinner:
        ; Check for a winner
        ; Horizontal check
        mov     esi, OFFSET board
        cmp     [esi], 'X'         ; Check the first cell
        je      Player1Wins        ; If it's 'X', Player 1 wins
        cmp     [esi], 'O'         ; Check the first cell
        je      Player2Wins        ; If it's 'O', Player 2 wins

        ; Check horizontally for each row
        mov     esi, OFFSET board  ; Reset the pointer to the beginning of the board
        mov     ecx, 0             ; Initialize row counter
    CheckHorizontal:
        mov     edi, esi           ; Store the current position
        mov     edx, 0             ; Initialize counter for cells in a row
    HorizontalLoop:
        cmp     [esi], 'X'         ; Check the current cell
        je      CheckHorizontalX   ; If it's 'X', check for consecutive Xs
        cmp     [esi], 'O'         ; Check the current cell
        je      CheckHorizontalO   ; If it's 'O', check for consecutive Os
        add     esi, 1             ; Move to the next cell
        inc     edx                ; Increment the counter
        cmp     edx, 3             ; Check if we've checked all cells in the row
        jl      HorizontalLoop     ; If not, continue checking
        inc     ecx                ; Move to the next row
        cmp     ecx, 3             ; Check if we've checked all rows
        jge     NoWinner           ; If we've checked all rows and found no winner, continue the game loop
        mov     esi, edi           ; Move to the next row
        add     esi, 3             ; Adjust pointer to the beginning of the next row
        jmp     CheckHorizontal    ; Check horizontally for the next row

    CheckHorizontalX:
        ; Implement logic to check for three consecutive Xs horizontally
        ; If found, jump to Player1Wins
        ; If not found, continue checking for other winning conditions
        jmp     CheckHorizontal

    CheckHorizontalO:
        ; Implement logic to check for three consecutive Os horizontally
        ; If found, jump to Player2Wins
        ; If not found, continue checking for other winning conditions
        jmp     CheckHorizontal

    NoWinner:
        ; If no winner is found, continue the game loop
        jmp     GameLoop

    ; If no winner is found, continue the game loop
    jmp     GameLoop

Player1Wins:
    ; Display message for Player 1 wins
    
    jmp     EndGame

Player2Wins:
    ; Display message for Player 2 wins
    jmp     EndGame

EndGame:
    ; Display message for draw if no winner
    ; End the game
    jmp     ExitProgram

GetInput PROC
    mov     edx, OFFSET inputMsg
    call    WriteString
    call    ReadChar          ; Read row input
    sub     al, '1'           ; Convert character to number
    imul    al, 3             ; Multiply by 3 (3 cells per row)
    mov     ecx, OFFSET board ; Point to the beginning of the board
    add     ecx, eax          ; Move to the correct row
    call    ReadChar          ; Read column input
    sub     al, '1'           ; Convert character to number
    add     ecx, eax          ; Move to the correct column
    mov     esi, ecx          ; Store the address of the selected cell
    ret
GetInput ENDP

DisplayBoard PROC
    mov     ecx, 0              ; Initialize loop counter
    mov     esi, OFFSET board   ; Point to the beginning of the board array
    
    ; Loop through each row
    DisplayRow:
        mov     edx, 0          ; Initialize inner loop counter
        
        ; Loop through each column
        DisplayColumn:
            mov     al, [esi]    ; Load the current cell value
            call    WriteChar    ; Display the character
            inc     edx          ; Move to the next column
            inc     esi          ; Move to the next cell in the array
            cmp     edx, 3       ; Check if we've reached the end of the row
            jl      DisplayColumn
            call    Crlf         ; Move to the next line
            inc     ecx          ; Move to the next row
            cmp     ecx, 3       ; Check if we've displayed all rows
            jl      DisplayRow
    ret
DisplayBoard ENDP

ExitProgram PROC
    invoke  ExitProcess, 0
ExitProgram ENDP

END main
