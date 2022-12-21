.data
n: .word 25
str1: .asciiz "Less than\n"
str2: .asciiz "Less than or equal to\n"
str3: .asciiz "Greater than\n"
str4: .asciiz "Greater than or equal to\n"

.text
main: 	
li  $v0, 5  #li = load imeddiate and save input into register $v0 (store result in function). 5 is to read integer.
syscall #end input and output 
addi $s1, $v0, 0 #saved in s1 = v0 + 0
lw $s2, n #save our comparision (25) into register $s2

#ble $s1, $s2, lessThan
#bgt $s1, $s2, greatequal
bgt $s1, $s2, greaterThan #if sl (input) is greater than s2 to go greterThan
ble   $s1, $s2, lessThanEqual #if sl is less than s2 go to less thanequal

greaterThan:  
la $a0, str3 
j end

greatThanEqual:
la $a0, str4
j end

lessThan:
la $a0, str1
j end

lessThanEqual:
la $a0, str2
j end

end:
li $v0, 4
syscall
