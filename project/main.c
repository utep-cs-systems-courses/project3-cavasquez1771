//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"

#define LED BIT6/* note that bit zero req'd for display */
short redrawScreen = 1;

char state1=1;


void wdt_c_handler(){
  static int secCount = 0;
  secCount++;

  if (secCount == 250) {
    redrawScreen=1;
    secCount=0;
    switch(state1){
    case 1: moveLeft(10);  state1++; break;
    case 2: moveDown(10);  state1++; break;
    case 3: moveRight(10); state1++; break;
    case 4: moveUp(10);    state1++; break;
    default: state1=1; break;
    }
  }
}

int main(void) {
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  led_init();
  switch_init();
  buzzer_init();
  lcd_init();
  enableWDTInterrupts();	/* enable periodic interrupt */
  or_sr(0x8);   // Enable interrupts

  P1DIR |= LED;            // Green led on when CPU on
  P1OUT |= LED;

  while(1){
    if(redrawScreen){
      buzzer_set_period(0);
      redrawScreen=0;
      and_sr(~8);          // Disable interrupts
      clearScreen(COLOR_WHITE);
      myShape(myColor);
      or_sr(8);            // Enable interrupts
    }

    P1OUT &= ~LED;         // led off
    or_sr(0x10);           // CPU OFF
    P1OUT |= LED;
  }
}
