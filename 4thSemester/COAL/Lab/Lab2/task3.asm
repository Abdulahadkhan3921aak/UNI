mov ah , 1
int 21h

mov ah , 2
sub al , 20h
mov dl , al   
int 21h