include 'functions.inc'
org 100h
  first:
    print "Enter real part of first number:"
    call scan_num
    mov r1,cx
    gotoxy 0,y
    add y,2 
    print "Enter imaginary part of first number:"
    call scan_num
    mov i1,cx
    
    gotoxy 0,y
    inc y
    
    print "Enter real part of second number:"
    call scan_num
    mov r2,cx
    gotoxy 0,y 
    print "Enter imaginary part of second number:"
    call scan_num
    mov i2,cx
    
    menu:
        
        mov r3,0
        mov i3,0
        mov r4,0
        mov i4,0
        
        call clear_screen
        mov y,1
        gotoxy 0,y
        add y,2
        
        print "First complex number: "
        mov ax,r1
        call print_num
        print "+("
        mov ax,i1
        call print_num
        print ")i        Second complex number: "
        mov ax,r2
        call print_num
        print "+("
        mov ax,i2
        call print_num
        print ")i"
        
        gotoxy 0,y
        add y,10        
        
        printn "1. ADDITION"
        printn "2. SUBTRACTION"
        printn "3. MULTIPLICATION"  
        printn "4. DIVISION"
        printn "5. CONJUGATE"
        printn "6. ABSOLUTE VALUE"
        printn "7. POWER TO"
        printn "8. POLAR FORM"
        
        gotoxy 0,y
        
        print "Enter your choice:"
        call scan_num
        call clear_screen
        printn ""
        mov choice,cl
        
        cmp choice,1
        jne a
         addition r1,r2,i1,i2 
        
        a:
        cmp choice,2
        jne b
        subtraction r1,r2,i1,i2
        
        b:
        cmp choice,3
        jne c
        multiplication r1,r2,i1,i2
        
        c:
        cmp choice,4
        jne d
        division r1,r2,i1,i2
        
        d:
        cmp choice,5
        jne e
        conjugate r1,r2,i1,i2
        
        e:
        cmp choice,6
        jne f
        abs_val r1,r2,i1,i2
        
        f: 
        cmp choice,7
        jne n_pow 
        
        printn ""
        print "Enter k:"
        call scan_num
        mov k,cx
       
        printn ""
        print "Power to which number?"
        call scan_num
        cmp cl,1
        jne pow_r2
        
        mov bx,r1
        mov r3,bx
        mov bx,i1
        mov i3,bx
        pow r1,r3,i1,i3
        
        pow_r2:
        
        mov bx,r2
        mov r3,bx
        mov bx,i2
        mov i3,bx
        pow r2,r3,i2,i3 
        
        n_pow:
        
        cmp choice,8
        jne n_polar
        
        print "Enter the value of theta: " 
        call scan_num
        mov theta,cx  
        print "Enter the value of r: "
        call scan_num
        mov r,cx
        polar r,theta 
        
        n_polar:
        
        gotoxy 0,y
        print "Wrong choice entered, please try again (press any key to continue)"
        
        mov ah,00h
        int 16h
        
        jmp menu
        
        
        
ret  

k dw ?
  
