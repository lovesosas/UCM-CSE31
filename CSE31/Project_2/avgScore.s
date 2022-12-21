#MIPS Assembly Project 2 by Luis Ornelas & Ryan Zhou

.data 

orig: .space 100	# In terms of bytes (25 elements * 4 bytes each)
sorted: .space 100

str0: .asciiz "Enter the number of assignments (between 1 and 25): "
str1: .asciiz "Enter score: "
str2: .asciiz "Original scores: "
str3: .asciiz "Sorted scores (in descending order): "
str4: .asciiz "Enter the number of (lowest) scores to drop: "
str5: .asciiz "Average (rounded down) with dropped scores removed: "
newLine: .asciiz "\n"
space: .asciiz " "
test: .asciiz " TEST \n"

.text 

# This is the main program.
# It first asks user to enter the number of assignments.
# It then asks user to input the scores, one at a time.
# It then calls selSort to perform selection sort.
# It then calls printArray twice to print out contents of the original and sorted scores.
# It then asks user to enter the number of (lowest) scores to drop.
# It then calls calcSum on the sorted array with the adjusted length (to account for dropped scores).
# It then prints out average score with the specified number of (lowest) scores dropped from the calculation.
main: 
	addi $sp, $sp -4
	sw $ra, 0($sp)
	li $v0, 4 
	la $a0, str0 
	syscall 
	li $v0, 5	# Read the number of scores from user
	syscall
	move $s0, $v0	# $s0 = numScores
	move $t0, $0
	la $s1, orig	# $s1 = orig
	la $s2, sorted	# $s2 = sorted
loop_in:
	li $v0, 4 
	la $a0, str1 
	syscall 
	sll $t1, $t0, 2
	add $t1, $t1, $s1
	li $v0, 5	# Read elements from user
	syscall
	sw $v0, 0($t1)
	addi $t0, $t0, 1
	bne $t0, $s0, loop_in
	
	move $a0, $s0
	jal selSort	# Call selSort to perform selection sort in original array
	
	li $v0, 4 
	la $a0, str2 
	syscall
	move $a0, $s1	# More efficient than la $a0, orig
	move $a1, $s0
	jal printArray	# Print original scores
	li $v0, 4 
	la $a0, str3 
	syscall 
	move $a0, $s2	# More efficient than la $a0, sorted
	jal printArray	# Print sorted scores
	
	li $v0, 4 
	la $a0, str4 
	syscall 
	li $v0, 5	# Read the number of (lowest) scores to drop
	syscall
	move $a1, $v0
	sub $a1, $s0, $a1	# numScores - drop
	move $a0, $s2
	jal calcSum	# Call calcSum to RECURSIVELY compute the sum of scores that are not dropped
	
	# Your code here to compute average and print it
	
	div $v0, $a1 # Sum / number of scores not dropped
	mflo $t1 # get access to the division result
	
	li $v0, 4 #prepare to print string
	la $a0, str5  #print strig
	syscall
	
	li $v0, 1 #prapre to print number
    	la $a0, 0($t1) #print average
   	syscall
	
	
	lw $ra, 0($sp)
	addi $sp, $sp 4
	li $v0, 10 
	syscall
	
	
# printList takes in an array and its size as arguments. 
# It prints all the elements in one line with a newline at the end.
printArray:

	#$a0 = original Array
	#$a1 = user input (number of scores)
 	# Your implementation of printList here
	addi $s0, $zero, 0 #int i = 0
	addi $sp, $sp, -4 #create space to store our array
	sw $a0, 0($sp) #store our array into the first 4 bytes
	move $t0, $a0 #move array into t0
	move $t1, $a1 #move user input into t1

while:
	beq $s0, $a1, endWhile #if i = to user input go to endWhile
	li $v0, 1 #prepare to print number
	lw $a0, 0($t0) #print out current index (address of the array)
	syscall

	li $v0, 4 #prepare to print string
	la $a0, space #print a space character
	syscall

	addi $t0, $t0, 4 #increment by 4 bytes to move to next index
	addi $s0, $s0, 1 #incremnt counter to check once we reach the end
	j while #repeat
endWhile:
 	li $v0, 4 #prepare to print string
 	la $a0, newLine #print new line
	syscall

	lw $a0, 0($sp) #load the array
	addi $sp, $sp, 4 #remove the stack back

	jr $ra #return to main fucntion
	
# selSort takes in the number of scores as argument. 
# It performs SELECTION sort in descending order and populates the sorted array
selSort:
	# Your implementation of selSort here
	
	add $t2, $zero, $zero #t2 = i = 0
	add $t3, $a0, $zero #t3 = userInput
	copy_array_loop:
		sll $t1, $t2, 2 # t2 

		add $t4, $t1, $s2 #sorted
		
		add $t5, $t1, $s1 #orig
		
		lw $t6, 0($t5) #load orignal array from memory into t6
		sw $t6, 0($t4) #store t6 into t4 memory (copy the value)
		
		addi $t2, $t2, 1 #increment i
		bne $t2, $t3, copy_array_loop #if i != userInput keep looping
	
	addi $t0, $zero, 1 # t0 = 1
	beq $a0,$t0, back # if userInput == t0 go to back (basically start the sorting)
	#if num = 1 doesnt need to be sorted
	
	#creating our conditions and intitiliazer for the sorting part
	add $t2, $zero, $zero #t2 = i = 0
	addi $t3, $a0, -1 #t3 = n - 1
	sort_array_loop:
		
		
		add $t0, $t2, $zero #t0 = maxindex = i
		
		addi $t4, $t2, 1 #t4 = j = i + 1
		add $t5, $a0, $zero #t5 = n
		sort_inner: #
			
			
			sll $t1, $t4, 2 #$t4 * 2^2
			add $t1, $t1, $s2 #sorted
			lw $t6, 0($t1) #sorted[j]
			
			sll $t1, $t0, 2
			add $t1, $t1, $s2 
			lw $t7, 0($t1) #sorted[maxIndex]
			
			bgt $t6, $t7, newMaxIndex #if(sorted[j] > sorted[maxIndex) maxindex = j
			If:
			addi $t4, $t4, 1 #j+1
			bne $t4, $t5, sort_inner #if j != n loop
		
		#swap
		sll $t1, $t0, 2 # maxindex by 4
		add $t1, $t1, $s2  #s2 is sorted array and then we move along the index by 4 bytes
		lw $t7, 0($t1) #sorted[maxIndex] loaded into t7
		
		sll $t1, $t2, 2 #i = 0, go to each index 4 bytes
		add $t1, $t1, $s2 #s2 is sorted array and then we move aong the index by 4 bytes
		lw $t6, 0($t1) #sorted[i] = sorted[maxindex] 
		sw $t7, 0($t1) #  = sorted[maxIndex
		
		sll $t1, $t0, 2 # increment maxIndex by 4 
		add $t1, $t1, $s2 #s2 is sorted array and then we move along the index
		sw $t6, 0($t1) # sorted[i] = temp
		
		
		##
		addi $t2, $t2, 1 #increment i
		bne $t2, $t3, sort_array_loop #if i != n loop
	back:
	jr $ra #return to caller
		
newMaxIndex:
	add $t0, $t4, $zero #upate the MaxIndex
	j If #repeat loop
	
# calcSum takes in an array and its size as arguments.
# It RECURSIVELY computes and returns the sum of elements in the array.
# Note: you MUST NOT use iterative approach in this function.
calcSum:
	# Your implementation of calcSum here
	#lw $t0, $a0 #t0 = memory address of sorted array
	#move $t1, $a1 #user input - lowest scores dropped

	addi $sp, $sp, -12 #stack allocation
	sw $ra, 0($sp) # store return address into first 4
	sw $a1, -4($sp) # numbers not dropped store inside stack to update each time for recursion
	sw $t0, -8($sp) # result of calcum(arr, len -1)

	ble $a1, $zero, returnZero # if(len <= 0) go to returnZero
	
	add $a1, $a1, -1 #, len -1 
	jal calcSum # loop 
	move $t0, $v0 # result of each recursive call of calcsum v0 is the output register (left side of recurion)

	sll $t1, $a1, 2 #remaing scores^2 the end of the array - 1
	add $t1, $t1, $a0 #arr[length - 1] of the sorted array
	lw $t2, 0($t1) #address of t1 load into t2 (right side of the recursion saved into t2)

	add $v0, $t0, $t2 #left side and right side added
	j end

returnZero:
	add $v0, $zero, $zero # return 0
	j end # go to End

end:
	lw $ra, 0($sp) #restore the stack and return to main
	lw $a1, -4($sp)
	lw $t0, -8($sp)
	addi $sp, $sp, 12
	jr $ra
	
	
