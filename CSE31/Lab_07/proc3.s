.data
x:	.word 1
y:	.word 2
z:	.word 3

.text

main:
	la $t0, x
	lw $s0, 0($t0) #s0 = 1
	la $t0, y
	lw $s1, 0($t0) #s1 = 2
	la $t0, z
	lw $s2, 0($t0) #s2 = 3
	jal foo
	
	
	
	add $s2, $s2, $v0 # s2 = s2 + foo(x,y,z)
	lw $s0, 4($sp)
	lw $s1, 0($sp)
	add $s2, $s1, $s2
	add $s2, $s0, $s2
	addi $a0, $s2, 0
	li $v0, 1
	syscall
	j END
	
foo:
	add $a2, $s0, $s2 #a2 = m+o
	add $a1, $s1, $s2 #a1 =  n+o
	add $a0, $s0, $s2 #a0 =  m+n
	addi $sp, $sp, -4
	sw $ra , 0($sp) #storing ra sp = [ra(of main)]
	
	jal bar
	addi $sp, $sp, -4
	sw $v1 , 0($sp) #storing v1 sp = [ra(of main), 128]
	
	sub $a0, $s0, $s2 #a0 = m-o
	sub $a1, $s1, $s0 #a1 = n-m
	add $a2, $s1, $s1 #s2 = n+n
	
	jal bar
	addi $sp, $sp, -4
	sw $s0 , 0($sp) #storing s0 sp = [ra(of main), 128, 2]
	
	addi $sp, $sp, -4
	sw $s1 , 0($sp) #storing s1 sp = [ra(of main), 128, 2, 3]
	lw $s0, 8($sp)  #s0 = 128
	add $s1, $zero, $v1 #s1 = 16
	add $v0, $s0, $s1
	lw $ra, 12($sp)
	jr $ra 
	
	
	
bar:
	sub $v1, $a1, $a0 # v1 = a2 - a0
	sllv $v1, $v1, $a2 # v1 = v1 * (2)^a0
	jr $ra
	
END: