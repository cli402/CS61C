# CS61C Sp14 Project 1-2
# Task A: The Collatz conjecture

.globl main
.include "collatz_common.s"

main:
	jal read_input			# Get the number we wish to try the Collatz conjecture on
	move $a0, $v0			# Set $a0 to the value read
	la $a1, collatz_recursive	# Set $a1 as ptr to the function we want to execute
	jal execute_function		# Execute the function
	li $v0, 10			# Exit
	syscall
	

collatz_recursive:
	li $v0 ,0
	li $t1 ,1
	bne $a0 ,$t1,continue
	jr $ra
continue:
	add $t2,$a0,$0
	li $t3,2
mod_2:blt $t2,$t3,end
	  addiu $t2,$t2,-2
	  j mod_2
end:bne $t2,$0,odd
	srl $a0,$a0,1
	j after
odd:    add $t2,$a0,$a0
	add $a0,$t2,$a0
	addiu $a0,$a0,1
after: 	addiu $sp,$sp,-4
        sw $ra,0($sp)
    	jal collatz_recursive
	lw $ra,0($sp)
	addiu $sp,$sp,4
	addiu $v0,$v0,1
	jr $ra
