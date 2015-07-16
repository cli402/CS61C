# CS61C Sp14 Project 1-2
# Task A: The Collatz conjecture

.globl main
.include "collatz_common.s"

main:
	jal read_input			# Get the number we wish to try the Collatz conjecture on
	move $a0, $v0			# Set $a0 to the value read
	la $a1, collatz_iterative	# Set $a1 as ptr to the function we want to execute
	jal execute_function		# Execute the function
	li $v0, 10			# Exit
	syscall




collatz_iterative:
	li $t0,1
	li $v0,0
loop: beq $a0,$t0,return_to_main
	  addiu $v0,$v0,1
	  add  $t1,$a0,$0
	  li $t2,2
mod_2: blt $t1,$t2,end
	   addiu $t1,$t1,-2
 	   j mod_2
end:  beq $t1,$0,even
odd:  add $t1,$a0,$a0
	  add $a0,$a0,$t1
	  addiu $a0,$a0,1
even: srl $a0,$a0,1
	  j loop
return_to_main:
	jr $ra
