##### Variables #####
.data
# Header for dense matrix
head:		.asciiz	"  -----0----------1----------2----------3----------4----------5----------6----------7----------8----------9-----\n"

##### print_dense function code #####
.text
# print_dense will have 3 arguments: $a0 = address of dense matrix, $a1 = matrix width, $a2 = matrix height
print_dense:
	      add $s0,$a0,$0   #element pointer
	      add $s1,$a1,$0
	      add $s2,$a2,$0
	      li $t0,0         #row counter
	      la $a0,head
	      jal print_str
	      jal print_newline
Row_loop: beq $t0,$a2,Row_end
		  add $a0,$t0,$0
		  jal print_int
		  jal print_space
		  addiu $t0,$t0,1
		  li $t1,0         #colum counter
coloum_loop:
		  beq $t1,$a1,colum_end
		  add $a0,$0,$s0
		  jal print_intx
		  jal print_space
		  addiu $t1,$t1,1 
		  addiu $s0,$s0,4
		  j coloum_loop
colum_end:
		  jal print_newline
		  j Row_loop
Row_end:
	      jr $ra

	
	

