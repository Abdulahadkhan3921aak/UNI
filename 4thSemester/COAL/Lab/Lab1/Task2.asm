.model small
.stack 100h

.code
main proc      
    
MOV ah, 1
int 21h
MOV bl, al

MOV ah , 2
MOV dl , bl
int 21h

mov ah , 4ch 

end main