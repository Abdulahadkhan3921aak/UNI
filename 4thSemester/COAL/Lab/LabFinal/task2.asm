.org 100h

jmp start

source db '00', 0     
result db '000', 0
temp   dw ?

start:
mov ah, 09h
lea dx, prompt
int 21h

mov ah, 0Ah           
lea dx, buffer
int 21h

mov al, buffer+2     
mov source[0], al
mov al, buffer+3     
mov source[1], al


mov al, source[0]
cmp al, '0'
jae  f1

f1:
cmp al, '9'
ja f2     

sub al, 30h  
jmp num1_ready

f2:

or al, 00100000b   
sub al, 57h  

num1_ready:
mov bl, 16
mul bl      

mov temp, ax

mov al, source[1]
cmp al, '0'
jae  g1

g1:
cmp al, '9'
ja g2     

sub al, 30h  
jmp num2_ready

g2:

or al, 00100000b  
sub al, 57h  

num2_ready:
xor ah, ah 
add temp, ax  


push temp 

mov di, 2  

next_digit:

cmp temp, 0
je stop

mov ax, temp
mov bl, 10
div bl 
mov result[di], ah
add result[di], 30h

xor ah, ah
mov temp, ax

dec di 
jmp next_digit

stop:
pop temp .

mov di, offset result
print_decimal:
mov ah, 2   
mov dl, [di]
cmp dl, 0
je end_print
int 21h
inc di
jmp print_decimal

end_print:

mov ah, 0
int 16h

ret

prompt db 'Enter a 2-digit hex number: $'
buffer db 4, ?, '00', 0  
