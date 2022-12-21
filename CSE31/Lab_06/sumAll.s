.data
number: .asciiz "Please enter a number: "
even: .asciiz "\nSum of even number is: "
odd: .asciiz "\nSum of odd number is: "

.text
main:
li $v0, 4 #ask for input number
la $a0, number #save input into $a0
syscall
la $v0, 5 #read our input from $v0
syscall
add $t0, $v0, $zero




loop: #to keep on asking for inputs
beqz $v0, print #if input is 0 to go to print
srl 	$t1, $t0, 1 # shifts to the right one bit  EX.so 20 becomes 21
sll 	$t1, $t1, 1 #shit back to left one bit EX. so 21 becomes back to 20
bne 	$t1, $t0, odds # if input is odd go to odds so 20 and 21 does not equal so its a odd
beq 	$t1, $t0, evens # if input is even go to evens so 


#repeat asking for input again just like in main
li $v0, 4 #ask for input
la $a0, number #save input into $a0
syscall
la $v0, 5 #read our input from $v0
syscall
add $t0, $v0, $zero




odds:
add $t3, $t3, $v0 #add input and save to $t3
j main #return to main


evens:
add $t2, $t2, $v0 #add input and save to $t2
j main #return to main



print:
li $v0, 4
la $a0, even #print out even string from .data
syscall
li $v0, 1 #print out our even sum
la $a0, 0($t2)
syscall


li $v0, 4 
la $a0, odd #print out even string from .data
syscall
li $v0, 1 #print out our even sum
la $a0, 0($t3)
syscall

