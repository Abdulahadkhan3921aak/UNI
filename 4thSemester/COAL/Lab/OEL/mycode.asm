.model small
.stack 100h
.data
scores db 100 dup(?)
scoresCount db 0
AStu db 0
BStu db 0
CStu db 0
DStu db 0
FStu db 0
AStudents db "A Student : $"
BStudents db "B Student : $"
CStudents db "C Student : $"
DStudents db "D Student : $"
FStudents db "F Student : $"
input_msg db "Enter test scores from 0 to 100, or -1 to terminate input :$"
error_msg db "The input is in valid$"
input_buffer db 5 , 0 , 5 dup(?)
input_number db ?    
sorted_msg db "Sorted Test Scores:$" 
space db " $"


.code
    mov ax , @data
    mov ds , ax
    call take_input
    call print_end
    call exit


take_input proc 
    mov cx , 100
    lea si , scores
    inputing:
    mov ah , 09h
    lea dx , input_msg
    int 21h
    lea dx, input_buffer
    mov ah, 0Ah                 
    int 21h 
    lea di , input_buffer
    add di , 2
    cmp [di] , '-'
    je stop_input
    sub [di] , '0'
    cmp [di] , 0
    jl invalid_input
    cmp [di] , 100
    jg invalid_input
    mov al , [di]
    mov dl , 10
    inc di
    sub [di] , '0'
    cmp [di] , 0
    jl invalid_input
    cmp [di] , 100
    jg invalid_input
    mul dl
    add al , [di]
    inc di
    cmp [di] , 13
    je input_done
    sub [di] , '0'
    cmp [di] , 0
    jl invalid_input
    cmp [di] , 100
    jg invalid_input
    mul dl
    add al , [di]
    input_done:
    mov ah , 0
    push ax
    mov [si] , ax
    inc si 
    inc scoresCount
    call map_score
    call new_line
    loop inputing
    invalid_input:
    lea dx , error_msg
    mov ah , 09h
    int 21h
    jmp inputing
    
    
    stop_input:
    call new_line
    ret
    take_input endp       
        
sort_scores proc
    ; Bubble sort algorithm
    mov cx , 0
    mov cl, scoresCount
    dec cx                      ; CX = scoresCount - 1
    lea si, scores
sort_outer:
    mov di, si
    mov bx, cx
sort_inner:
    mov al, [di]
    mov ah, [di+1]
    cmp al, ah
    jbe no_swap
    xchg al, ah
    mov [di], al
    mov [di+1], ah
no_swap:
    inc di
    dec bx
    jnz sort_inner
    dec cx
    jnz sort_outer
    ret
sort_scores endp

display_scores proc
    mov ah, 09h
    lea dx, sorted_msg
    int 21h
    call new_line
    lea si, scores
    mov cl, scoresCount
display_loop:
    lodsb
    aam
    add ax, 3030h               ; Convert number to ASCII
    mov dl, ah
    mov ah, 02h
    int 21h
    mov dl, al
    int 21h
    lea dx, space
    mov ah, 09h
    int 21h
    loop display_loop
    call new_line
    ret
display_scores endp
        
 
exit proc
    mov ah , 4ch
    int 21h
    ret
    exit endp  


new_line proc
    mov dl , 10
    mov ah , 02
    int 21h
    mov dl , 13
    int 21h
    ret
    new_line endp

map_score proc
    pop di
    pop bx
    cmp bl , 90
    jge incement_A
    cmp bl , 80
    jge incement_B
    cmp bl , 70
    jge incement_C
    cmp bl , 60
    jge incement_D
    cmp bl , 0
    jge incement_F
    
    incement_A:
    inc AStu
    jmp quit
    incement_B:
    inc BStu
    jmp quit
    incement_C:
    inc CStu
    jmp quit
    incement_D:
    inc DStu
    jmp quit   
    incement_F:
    inc FStu
    jmp quit
    
    quit:
    push di
    ret
    map_score endp
    

print_end proc 
    
    call sort_scores
    call display_scores
    mov ax , 0
    lea dx , AStudents
    mov ah , 09h
    int 21h 
    
    mov ah , 02h
    mov dl , AStu
    add dl , '0'
    int 21h
    
    call new_line
    
    mov ax , 0
    lea dx , BStudents
    mov ah , 09h
    int 21h
           
    mov ah , 02h
    mov dl , BStu
    add dl , '0'
    int 21h
    
    call new_line 
    
    mov ax , 0
    lea dx , CStudents
    mov ah , 09h
    int 21h
    
    mov ah , 02h
    mov dl , CStu
    add dl , '0'
    int 21h
    
    call new_line 
    
    mov ax , 0
    lea dx , DStudents
    mov ah , 09h
    int 21h
    
    mov ah , 02h
    mov dl , DStu
    add dl , '0'
    int 21h
    
    call new_line 
    
    mov ax , 0
    lea dx , FStudents
    mov ah , 09h
    int 21h
    
    mov ah , 02h
    mov dl , DStu
    add dl , '0'
    int 21h
    
    ret
    print_end endp 
    
    