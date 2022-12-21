        .data
#n:      .wird 13
str0: 	.asciiz "Please enter a number: "


        .text
main: 	
	li $v0, 4 #print string out
	la $a0, str0
	syscall
	
	li $v0, 5 #ask for input
	syscall
	
	move $t3, $v0 #move user input into t3
	
	add $t0, $0, $zero #make t0 = 0
	addi $t1, $zero, 1 #make t1 = 1
	
	#la $t3, n
	#lw $t3, 0($t3)
	
		
fib: 	beq     $t3, $0, finish #if t3 = 0 go to finish
	add     $t2,$t1,$t0 #add t1 and t0 to t2
	move    $t0, $t1 #move t1 to t0
	move    $t1, $t2 #move t2 to t1
	subi    $t3, $t3, 1 #subtract user input by 1
	j       fib
		
finish: addi    $a0, $t0, 0 #print our result
	li      $v0, 1		
	syscall	
	
					
	li      $v0, 10		#end program
	syscall			

