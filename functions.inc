include 'emu8086.inc'
org 100h
jmp first
addition macro r1,r2,i1,i2
        mov dx,r1
        add dx,r2
        mov r3,dx
        mov dx,i1
        add dx,i2
        mov i3,dx
        
        mov dl,43
        
        print_all r1,r2,i1,i2
	jmp menu              
addition endm                  

subtraction macro r1,r2,i1,i2
    mov dx,r1
    sub dx,r2
    mov r3,dx
    mov dx,i1
    sub dx,i2
    mov i3,dx
    
    mov dl,45
    
    print_all r1,r2,i1,i2
    jmp menu
subtraction endm               
        
multiplication macro r1,r2,i1,i2
    local exit1
     
    mov ax,r1
    imul r2
    
    mov temp1,ax
    
    mov ax,i1
    imul i2
    
    mov temp2,ax
    
    mov bx,temp1
    sub bx,temp2
    
    mov r3,bx
             
    mov ax,r1
    imul i2
    
    mov temp1,ax
    
    mov ax,i1
    imul r2
    
    mov temp2,ax
    
    mov bx,temp1
    add bx,temp2
    
    mov i3,bx
    
    cmp cx,1
    je exit1

    mov dl,42
    print_all r1,r2,i1,i2
    
    jmp menu
   exit1:
	ret
    
multiplication endm    
        
division macro r1,r2,i1,i2

    mov ax,1
    conjugate r1,r2,i1,i2
    

    mov cx,1 
    multiplication r1,r2,i1,i2
    
    mov ax,r2
    imul r2
    
    mov temp1,ax
    
    mov ax,i2
    imul i2
    
    mov temp2,ax
    add ax,temp1
    
    mov temp1,ax
    
    mov ax,r3
    idiv temp1
    
    mov r3,ax
    mov ax,i3
    idiv temp1
    mov i3,ax 
    
    mov dl,47
    print_all r1,r2,i1,i2
    
division endm    
                
conjugate macro r1,r2,i1,i2
    local label1
    local conjugate_div
    cmp ax,1
    je conjugate_div
    
    print "Conjugate of which number?"            
    call scan_num
    
    cmp cl,1
     jne label1
       mov ax,i1
       mov cx,-1
       imul cx
      
       mov i3,ax
       print "conjugate of"
       mov ax,r1
       call print_num
       print "+ ("
       mov ax,i1
       call print_num
       print ")i = "
      
       mov ax,r1
       call print_num
       print "+ ("
       mov ax,i3
       call print_num
       printn ")i"  
       
       printn ""
       print "Press any key to continue" 
       
       mov ah,00h
       int 16h
       
       jmp menu
     
     
     label1:
       mov ax,i2 
       mov cx,-1
       imul cx
      
       mov i3,ax
       print "Conjugate of"
       mov ax,r2
       call print_num
       print "+ ("
       mov ax,i2
       call print_num
       print ")i = "
      
       mov ax,r2
       call print_num
       print "+ ("
       mov ax,i3
       call print_num
       printn ")i"
       
       printn ""
       print "Press any key to continue" 
       
       mov ah,00h
       int 16h
       
        jmp menu
   
   
    conjugate_div:
        
        mov ax,i2
        mov cx,-1
        imul cx
        
        mov i2,ax 
	ret
              
conjugate endm                  
        
abs_val macro r1,r2,i1,i2
	local label2
	
	print "Absolute value of which number?"            
    	call scan_num   
	cmp cl,1
	jne label2      
        
	mov ax,r1
        imul r1
        mov z,ax
        
        mov ax,i1
        imul i1
	add ax,z
	jmp abs
    
    label2:
	mov ax,r2
        imul r2
        mov z,ax
        
        mov ax,i2
        imul i2
        add ax,z    

     abs:                   
        mov cx,0000
        mov bx,0ffffh
        sqrt:
            add bx,0002
            inc cx
            sub ax,bx
            jnz sqrt
            
        mov ax,cx
        print "Absolute value:"
        call print_num

	printn ""
       print "Press any key to continue" 
       
       mov ah,00h
       int 16h
       
        jmp menu    
        ret
abs_val endm      

pow macro r1,r2,i1,i2
	local output
	
	cmp cx,1
    	je output
   
    	dec cx
    	mov bx,1
    	multiplication r1,r2,i1,i2
    	

	output:
	print_all r1,r2,i1,i2	

pow endm
    
polar macro r,theta
    mov ax,r
    printn ""
    printn ""
    print "The polar form is: "
    call print_num
    mov ax,theta
    print "(cos"
    call print_num
    print " + i sin"
    call print_num
    printn ") "   
    cmp bx,1
    je conv_pol1
    conv_pol1:
        ret
    printn ""
    print "Press any key to continue"
    mov ah,00h
    int 16h
    
    jmp menu
    ret
polar endm


print_all macro r1,r2,i1,i2
    local here
    mov ax,r1
    call print_num
    mov ax,i1
    print " + ("
    call print_num
    
    print ")i  "
    mov ah,2
    int 21h
    
    print "  "
    
    mov ax,r2
    call print_num
    mov ax,i2
    print " + ("
    call print_num
    print ")i  =  "
    cmp bx,1
    jne here
    ret
    here:
    mov ax,r3
    call print_num
    mov ax,i3
    print "+("
    call print_num
    printn ")i"
    printn ""
    print "Press any key to conitnue"
    mov ah,00h
    int 16h
    jmp menu
    ret
print_all endm  

define_clear_screen
define_scan_num
define_print_num
define_print_num_uns

y db 1
r1 dw 0
r2 dw 0
i1 dw 0
i2 dw 0
r3 dw 0
i3 dw 0
r4 dw 0
i4 dw 0 
z dw 0 
r dw 0
theta dw 0
temp1 dw 0
temp2 dw 0
temp3 dw 0
temp4 dw 0
choice db 0

ret




