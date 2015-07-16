##### sparse2dense function code #####
.text
# sparse2dense will have 2 arguments: $a0 = address of sparse matrix data, $a1 = address of dense matrix, $a2 = matrix width
# Recall that sparse matrix representation uses the following format:
# Row r<y> {int row#, Elem *node, Row *nextrow}
# Elem e<y><x> {int col#, int value, Elem *nextelem}
sparse2dense:
		add	$a2, $a2, $a2		# a2 = a2 + a2
		add	$a2, $a2, $a2	
row_loop:
 		beq $a0, $0,row_end
 		lw $t0,0($a0)          #row_number
 		lw $t1,4($a0)          #element pointer
element_loop:
		beq $t1,$0,element_end
		lw  $s0,0($t1)         #colunm number
		lw  $s1,4($t1)         #value
		lw  $t1,8($t1)
		
		mult $t0,$a2
		mflo $t3
		
		add	$s0, $s0, $s0		# a2 = a2 + a2
		add	$s0, $s0, $s0
		
		add $t3,$s0,$t3
		add $t3,$t3,$a1
		sw 	$s1,($t3)
		j element_loop
element_end:
 		lw $a0,8($a0)   #proceed to next row
		j row_loop
row_end:
		jr $ra