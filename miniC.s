############################
.data

# STRINGS ##################
$str1:	.asciiz "Test 1\n" 
$str2:	.asciiz "Fin test1\n" 

# IDENTIFIERS ##############
_a:	.word 0
_b:	.word 0
_c:	.word 0
###################
# Seccion de codigo
	.text
	.globl main
main:
	li $t0,3
	sw $t0,_b
	li $t0,0
	sw $t0,_c
	la $a0,$str1
	li $v0,4
	syscall
	li $t0,1
	lw $t1,_b
	add $t2,$t0,$t1
	sw $t2,_a
	li $v0,5
	syscall
	sw $v0,_a
	la $a0,$str2
	li $v0,4
	syscall
##################
# Fin
	li $v0, 10
	syscall
