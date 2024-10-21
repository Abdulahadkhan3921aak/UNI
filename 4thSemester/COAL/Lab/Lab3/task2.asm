mov ah , 01h
int 21h   
sub al , 30h
mov cl , al  
mov ah , 02h
mov dl , 0Ah
int 21h      
mov ah , 01h
int 21h    
sub al , 30h
add cl , al  
mov ah , 02h
mov dl , 0Ah
int 21h   
mov ah , 01h
int 21h   
sub al , 30h
add cl , al 
mov ah , 02h
mov dl , 0Ah
int 21h
mov ax , 0 
mov ax , cx     
AAM   
mov cl , al
mov dl , ah
add dl,48
mov ah,2
int 21h
mov dl,cl
add dl,48
int 21h