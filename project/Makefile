# makfile configuration
#COMMON_OBJECTS  = #main.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as -mmcu=${CPU} -c

all: run.elf

run.elf: ${COMMON_OBJECTS} wdt_handler.o p1_interrupt_handler.o main.o buzzer.o switches.o stateMachines.o led.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

load: run.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf *~


led.o: led.c led.h
#wdInterruptHandler.o: stateMachines.h
stateMachines.o: led.h stateMachines.h stateMachines.s
switches.o: switches.h
buzzer.o: buzzer.h 
