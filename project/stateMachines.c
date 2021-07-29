#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "../lcdLib/lcdutils.h"
#include "../lcdLib/lcddraw.h"

void state_advance() {

  if(state==1){
    myColor=COLOR_LIME_GREEN;
  }

  else if(state==2){
    myColor=COLOR_FIREBRICK;
  }

  else if (state==3){
    myColor=COLOR_DARK_ORANGE;
  }

  else if (state==4){
    myColor=COLOR_SIENNA;
  }
 
}


void toggle_green()
{
  green_on ^= 1;
  led_changed = 1;
  led_update();
}

void toggle_red()
{
  red_on ^= 1;
  led_changed = 1;
  led_update();
}

void turn_off_rg()
{
  green_on = 0;
  red_on = 0;
  led_changed = 1;
  led_update();
}

