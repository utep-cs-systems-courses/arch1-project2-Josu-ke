.arch msp430g2553
	.p2align 1,0
	.data
jt:
	.word default
	.word case1
	.word case2
	.word case3


	.text
	.global state_advance_switch

state_advance_switch:
	cmp #4, r12
	jc default
	add r12,r12
	mov jt(r12),r0
case1:
	call #state_advance
	jmp end
	
case2:	call #stop
	jmp end
	
case3:	call #state_blink
	jmp end

default:
	jmp end

end:
	ret
