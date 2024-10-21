.model small
.stack 100h

.data
    inputFile db 'input.txt', 0
    outputFile db 'output.txt', 0
    decryptedFile db 'decrypted.txt', 0
    key db 55h 
    buffer db 512 dup('$')
    successMsg db 'Operation completed successfully$'
    menuMsg db 'Choose an option:', 0Dh, 0Ah, '1. Encrypt File', 0Dh, 0Ah, '2. Decrypt File', 0Dh, 0Ah, '$'
    errMsg db 'Error: Invalid option$'

.code

start:
                
    mov ax, @data
    mov ds, ax


    mov ah, 09h
    lea dx, menuMsg
    int 21h

input_loop:
    
    mov ah, 01h
    int 21h

    cmp al, 'Q'
    je terminate

    
    cmp al, '1'
    je encrypt_file
    cmp al, '2'
    je decrypt_file

   
    mov ah, 09h
    lea dx, errMsg
    int 21h
    jmp input_loop



encrypt_file:
    
    mov ah, 3Dh          
    mov al, 0       
    lea dx, inputFile
    int 21h
    jc file_open_error
    mov bx, ax          

    
    mov ah, 3Fh         
    mov cx, 128         
    lea dx, buffer       
    int 21h
    jc file_read_error
    mov cx, ax           


    lea si, buffer
    mov al, key
    mov di, si          
    mov cx, 512         
xor_loop:
    mov al , [si]     
    xor al, key         
    mov [si] , al
    inc si              
    loop xor_loop

   
    mov ah, 3Eh         
    int 21h

    
    mov ah, 3Ch          
    mov cx, 0            
    lea dx, outputFile
    int 21h
    jc file_create_error
    mov bx, ax          


    mov ah, 40h          
    lea dx, buffer  
    mov cx, 128  
    int 21h
    jc file_write_error


    mov ah, 3Eh          
    int 21h


    mov ah, 09h
    lea dx, successMsg
    int 21h
    jmp terminate

decrypt_file:
    
    mov ah, 3Dh         
    mov al, 0           
    lea dx, inputFile   
    int 21h
    jc file_open_error
    mov bx, ax          

    
    mov ah, 3Fh         
    mov cx, 512         
    lea dx, buffer      
    int 21h
    jc file_read_error
    mov cx, ax          
    cmp cx, 0           
    je no_data_read


    lea si, buffer 
    mov cx , 128
    mov di, si           
xor_loop_decryption:
    mov al , [si]        
    xor al, key          
    mov [si] , al
    inc si               
    loop xor_loop_decryption


    mov ah, 09h
    lea dx, buffer
    int 21h 



    mov ah, 3Eh          
    int 21h

    
    mov ah, 3Ch          
    mov cx, 0            
    lea dx, decryptedFile
    int 21h
    jc file_create_error
    mov bx, ax           ;


    mov ah, 40h          
    lea dx, buffer     
    mov cx, 128          
    int 21h
    jc file_write_error

    mov ah, 3Eh          
    int 21h


    mov ah, 09h
    lea dx, successMsg
    int 21h
    jmp terminate

no_data_read:
    mov ah, 09h
    lea dx, errMsg5
    int 21h
    jmp terminate

file_open_error:
    mov ah, 09h
    lea dx, errMsg1
    int 21h
    jmp terminate

file_read_error:
    mov ah, 09h
    lea dx, errMsg2
    int 21h
    jmp terminate

file_create_error:
    mov ah, 09h
    lea dx, errMsg3
    int 21h
    jmp terminate

file_write_error:
    mov ah, 09h
    lea dx, errMsg4
    int 21h
    jmp terminate

terminate:
    mov ah, 4Ch
    int 21h

errMsg1 db 'Error: Cannot open file$', 0
errMsg2 db 'Error: Cannot read file$', 0
errMsg3 db 'Error: Cannot create file$', 0
errMsg4 db 'Error: Cannot write to file$', 0
errMsg5 db 'Error: No data read from input file$', 0

end start
