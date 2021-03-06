#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "led.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count == 125) { //Every half a second
    if(switch_state == 1){ //Music is played
      state_advance();
    }

    if(switch_state == 2){
      stop();
    }

    if(switch_state == 3){
      state_blink();
    }

    blink_count = 0;
  }
}
