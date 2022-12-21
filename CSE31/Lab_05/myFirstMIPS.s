.data
.text
add $t0, $s0, $zero
add $t1, $t0, -7
add $t2, $t1, $t0
add $t3, $t2, 2
add $t4, $t3, $t2
add $t5, $t4, -28
sub $t6, $t4, $t5
add $t7, $t6, 12

li $v0, 10
syscall