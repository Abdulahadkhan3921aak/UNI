.data
a db ?
b db ?

mov ah , 1

int 21h
mov a , al 

mov ah , 2
mov dl , 0Ah 
int 21h

mov ah , 1
int 21h
mov b , al

mov ah , 2
mov dl , 0Ah  
int 21h

mov al , a
sub al , b
add al , 48

mov dl , al
int 21h