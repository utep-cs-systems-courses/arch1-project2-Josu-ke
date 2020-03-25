#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "songs.h"
#include "switches.h"
#include "led.h"

int main() {
    configureClocks();
 
    buzzer_init();
     switch_init();
     led_init();

     enableWDTInterrupts();
    // while(1){
    // play();
    // }
     or_sr(0x18); // CPU off, GIE on             
}


