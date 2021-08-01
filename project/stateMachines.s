#include <msp430.h>
#include "lcddraw.h"
#include "switches.h"
#include "lcdutils.h"
#include "stateMachines.h"
#include "buzzer.h"

	.arch msp430g2553
	.p2alighn 1,0

	.text
	.global state_advance
	.extern state
	.extern COLOR_LIME_GREEN
	.extern COLOR_FIREBRICK
	.extern COLOR_DARK_ORANGE
	.extern COLOR_SIENNA
	.extern COLOR_BLACK

	.data
	.extern myColor

state:
	.word 0

jt:
	.word case_1		;jt[0]
	.word case_2
	.word case_3
	.word case_4
	.word default		;jt[5]

state_advance:
	cmp #5, &s		;range check
	jc default		;jmp if s>4

	mov &state, r12		;move selector
	add r12, r12		;double for size
	mov jt(r12), r0		;mov selection into pc
case_1:
	mov &COLOR_LIME_GREEN, &myCOLOR
	jmp end

case_2:
	mov &COLOR_FIREBRICK, &myColor
	jmp end

case_3:
	mov &COLOR_DARK_ORANGE, &myColor
	jmp end

case_4:
	mov &COLOR_SIENNA, &myColor
	jmp end

default:
	mov &COLOR_BLACK, &myColor

end:
	pop r0			;return






	
