		.data
x:		.word 5
y:		.word 10
m:		.word 15
b:		.word 2

		.text
MAIN:	la $t0, x
		lw $s0, 0($t0)		# s0 = x
		la $t0, y
		lw $s1, 0($t0)		# s1 = y
		
		# Prepare to call sum(x)
		add $a0, $zero, $s0	# Set a0 as input argument for SUM
		jal SUM
		
		add $t0, $s1, $s0 #t0 = y + x
		add $s1, $t0, $v0 #y = t0 + returnValue
		addi $a0, $s1, 0 #a0 = y + 0
		li $v0, 1		 
		syscall	
		j END

		
SUM: 		la $t0, m 
		addi $sp, $sp -12 #create 12 bytes on stack
		sw $s0, 0($sp) #save s0 to first 4 bytes
		sw $ra, 4($sp) #save ra to next 4 bytes
		sw $a0, 8($sp) #save a0 to next 4 bytes
		lw $s0, 0($t0)		# s0 = m
		add $a0, $s0, $a0	# Update a0 as new argument for SUB
		
		jal SUB
		
		lw $s0, 0($sp)
		lw $ra, 4($sp)
		lw $a0, 8($sp)
		add $v0, $a0, $v0
		addi $sp, $sp, 12
		jr $ra		
		
SUB:		la $t0, b
		addi $sp, $sp -4
		sw $s0, 0($sp)		# Backup s0 from SUM
		lw $s0, 0($t0)		# s0 = b
		sub $v0, $a0, $s0
		lw $s0, 0($sp)		# Restore s0 from SUM
		addi $sp, $sp 4
		jr $ra

		
END:
