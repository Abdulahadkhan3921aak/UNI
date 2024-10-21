mov dx , 32767 ; 7fff (hexa) => 32767 (decimal)
mov bx , 24542 ; 5fde (hexa) => 24542 (decimal)
mov ax , dx 
add ax , bx    ; 7fff + 5fde => dfdd (hexa) , 57309(un signed) , -8227(signed)
mov ax , dx
sub ax , bx    ; => 8225 (decimal signed)



