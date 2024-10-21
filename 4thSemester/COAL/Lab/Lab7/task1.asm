.data
time_message db "The current time is (HH : MM) : $" 
date_message db "The current date is (DD : MM : YYYY , week_day)  : $"
monday db "monday$"
tuesday db "tuesday$"
wednesday db "wednesday$"
thursday db "thursday$"
friday db "friday$"
saturday db "saturday$"
sunday db "sunday$"
day db ?
week_day db ?
month db ?
year dw ?
hour db ?
min db ?

.code
main proc
    mov ax , @data
    mov ds , ax
    call print_time
    mov ah , 4ch
    int 21h
    main endp

print_time proc
    lea dx , time_message
    call print_string
    mov ah , 2ch
    int 21h
    mov offset hour , ch 
    mov offset min  , cl 
    mov al , hour
    AAM
    mov cx , ax
    mov dl , ch
    add dl , 30h
    call print_char
    mov dl , cl
    add dl , 30h
    call print_char
    call print_seperator
    mov al , min
    AAM
    mov cx , ax
    mov dl , ch
    add dl , 30h
    call print_char
    mov dl , cl
    add dl , 30h
    call print_char
    call print_newline
    mov ah , 09h
    lea dx , date_message
    call print_string
    mov ah , 2ah
    int 21h
    mov offset year , cx
    mov offset day , dl
    mov offset month , dh
    mov offset week_day , al
    mov al , day
    AAM
    mov cx , ax
    mov ah , 02h
    mov dl , ch
    add dl , 30h
    int 21h
    mov dl , cl
    add dl , 30h
    int 21h
    call print_seperator
    mov al , month
    AAM
    mov cx , ax
    mov dl , ch
    add dl , 30h
    call print_char
    mov dl , cl
    add dl , 30h
    call print_char
    call print_seperator
    mov bx , year
    mov ax , bx
    mov cl , 100
    div cl
    mov bx , ax
    mov ax , 0
    mov al , bl
    AAM
    mov cx , ax
    mov dl , ch
    add dl , 30h
    call print_char
    mov dl , cl
    add dl , 30h
    call print_char
    mov al , bh
    AAM
    mov cx , ax
    mov dl , ch
    add dl , 30h
    call print_char
    mov dl , cl
    add dl , 30h
    call print_char
    call print_comma
    call print_weekday
    ret
    print_time endp
                   
                   
    print_char proc
        mov ah , 02h
        int 21h
        ret
        print_char endp
                       
                       
    print_string proc
        mov ah , 09h
        int 21h
        ret
        print_string endp
    
    print_newline proc
        mov ah , 02h
        mov dl , 0ah
        int 21h
        mov dl , 0dh
        int 21h
        ret
        print_newline endp
    
    print_seperator proc
        mov dl , ' '
        call print_char
        mov dl , ':'
        call print_char
        mov dl , ' '
        call print_char
        ret
        print_seperator endp
    
    print_comma proc
        mov dl , ' '
        call print_char
        mov dl , ','
        call print_char
        mov dl , ' '
        call print_char
        ret
        print_comma endp
    
    print_weekday proc
        mov al , week_day
        cmp al , 0
        jpe Psunday
        cmp al , 1
        jpe Pmonday
        cmp al , 3
        jpe Pwednesday
        cmp al , 4
        jpe Pthursday
        cmp al , 5
        jpe Pfriday
        cmp al , 6
        jpe Psaturday
        cmp al , 2
        jpe Ptuesday
        Pmonday:
            lea dx , monday
            call print_string
            ret
        Ptuesday:
            lea dx , tuesday
            call print_string
            ret
        Pwednesday:
            lea dx , wednesday
            call print_string
            ret
        Pthursday:
            lea dx , thursday
            call print_string
            ret
        Pfriday:
            lea dx , friday
            call print_string
            ret
        Psaturday:
            lea dx , saturday
            call print_string
            ret
        Psunday:
            lea dx , sunday
            call print_string
            ret
        print_weekday endp
         
stop:
end main