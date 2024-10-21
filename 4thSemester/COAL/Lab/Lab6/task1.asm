mov bl , 0
mov bh , 100
main_loop:
    mov ax , 0
    mov al , bl
    jmp find_odd
    inc_loop:  
        mov cx , 0
        mov cl , bh
        inc bl
        dec bh
        loopnz main_loop 
find_odd:
    mov cl , 2
    div cl
    cmp ah , 1
    je is_odd 
    jmp inc_loop: 
is_odd:
    mov ax , 0
    mov al , bl
    AAM
    mov dh , al
    mov dl , ah
    mov ah , 02h
    add dl , 48
    int 21h     
    mov dl , dh
    add dl , 48
    int 21h    
    mov dl , 2ch
    int 21h
    jmp inc_loop:
    

