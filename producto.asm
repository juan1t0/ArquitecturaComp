.text 
.globl __start
__start:
	la $a0,punto1
	la $a1,punto2
	
	lw $t0,tam

loop1:	l.d $f2,($a0)
	l.d $f4,($a1)
	mul.d $f6,$f2,$f4
	add.d $f8,$f8,$f6
	add $a0,$a0,8
	add $a1,$a1,8
	add $t0,$t0,-1
	bnez $t0,loop1
	
	mov.d $f12,$f8
	li $v0,3
	syscall
	li $v0,10
	syscall
	
	

.data
	punto1: .double 5.2,4.5,6.2
	punto2: .double 2.6,6.7,1.8
	
	vector1: .double 1.4,3.5,5.7
	vector2: .double 2.2,4.3,6.9
	
	tam:	.word 3
