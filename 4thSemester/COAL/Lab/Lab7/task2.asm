.model small
.stack 100h
.data
sum dw ? 
msg_sum db "Sum: $"
.code
Main proc
mov ax, @data
mov ds, ax
push 5
push 4
push 7
push 12
push 9
call CalculateSum
mov sum, ax
mov ah, 09h
lea dx, msg_sum
int 21h
mov ax, sum
call print_number
mov ax, 4c00h
int 21h
Main endp
CalculateSum proc
mov bp, sp
mov ax, 0
mov cx, 5
calc_sum_loop:
add ax, [bp+2]
add bp, 2
loop calc_sum_loop
ret
CalculateSum endp
print_number proc
push ax
push bx
push cx
mov bx, 10
mov cx, 0
divide_loop:
xor dx, dx
div bx
push dx
inc cx
or ax, ax
jnz divide_loop
print_loop:
pop dx
add dl, '0'
mov ah, 02h
int 21h
loop print_loop
pop cx
pop bx
pop ax
ret
print_number endp

end Main