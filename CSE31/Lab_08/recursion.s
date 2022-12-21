.data

# TPS 2 #3 (statement to be displayed)

str1:	.asciiz "Please enter a number: "				#register a0 for input and v0 for output



        .text
main: 		addi $sp, $sp, -4	# Moving stack pointer to make room for storing local variables (push the stack frame) by 4its (byt
		
		# TPS 2 #3 (display statement)
		
		li $v0, 4
		la $a0, str1   #add $v0, $zero, 4
		syscall
	
		# TPS 2 #4 (read user input)	
		li $v0, 5
		syscall
		add $a0, $v0, $zero   #a0 will be used as input argument for recursion
		
		jal recursion	# Call recursion(x)
	
		# TPS 2 #6 (return the answer)
		move $a0, $v0
		li $v0, 1		#print our result
		syscall
		
		
		j end		# Jump to end of program


# Implementing recursion
recursion:	addi $sp, $sp, -12	# Push stack frame for local storage (hold 12 bytes) 3 numbers

		# TPS 2 #7 
		sw $ra, 0($sp)		#backs up $ra to be able to jump to next recursion call
		
		addi $t0, $a0, 1			#t0 = user input +1
		bne $t0, $zero, not_minus_one		#if t0 != 0 go to not_minus_one
		
		# TPS 2 #8 (update returned value)
		addi $v0, $zero, 1		 #returns 1
		
		
		j end_recur
			
			
not_minus_one:    bne $a0, $zero, not_zero #if user input != 0 go to not_zero

		# TPS 2 #9 (update returned value)
		addi $v0, $zero, 3			#will return 3 if branch statement is equal to 0
		
		j end_recur		

not_zero:	
		
		sw $a0, 4($sp) 	#stores input argument in stack

		# TPS 2 #11 (Prepare new input argument, i.e. m - 2)
		addi $a0, $a0, -2  #user input = userinput - 2
		jal recursion	# Call recursion(m - 2)

		# TPS 2 #12 
		#return value is stored at $v0 = recursion(m-2)
		sw $v0, 8($sp)		#backs up return value of a0 into the stack
		
	
		# TPS 2 #13 (Prepare new input argument, i.e. m - 1)
		lw $a0, 4($sp)		#new argument (a0 - 1)
		addi $a0, $a0, -1  
		jal recursion	# Call recursion(m - 1)
			
		# TPS 2 #14 (update returned value)
		lw $t0, 8($sp)		#retrievs value into temp register
		add $v0, $v0, $t0	#adds the main register of recursion with the temp register to get total
		
		j end_recur
		

# End of recursion function	
end_recur:	# TPS 2 #15 
		lw $ra, 0($sp)

		addi $sp, $sp, 12	# Pop stack frame 
		jr $ra

# Terminating the program
end:	addi $sp, $sp 4	# Moving stack pointer back (pop the stack frame)
		li $v0, 10 
		syscall