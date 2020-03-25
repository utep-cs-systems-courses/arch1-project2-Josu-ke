#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "songs.h"


//Method will play song when button is pressed

void state_advance() {
  static char currentState = 0;
  switch (currentState) {

  case 0:
    currentState = 1;
    play();
    break;
  case 1:
    currentState = 2;
    // buzzer_set_period(2217.46);
    break;
  case 2:
    currentState = 3;
    // buzzer_set_period(2217.46);
    break;
  case 3:
    currentState = 4;
    // buzzer_set_period(2217.46);
    break;
  case 4:
    currentState = 0;
    // buzzer_set_period(2217.46);
    break;
  }
}

//stops the current state
void stop(){
  buzzer_set_period(0);
}

char turn_red() {
  static char state = 0;

  switch(state){
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;
}

char turn_green(){
  char changed = 0;
  if(red_on){
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

//Method will blink lights by using a switch we will goo
//from case to case to trigger a blink
void state_blink(){
  char changed = 0;
  static enum {RED=0, GREEN=1}
  color = GREEN;
  switch(color){
  case RED:
    changed = turn_red();
    color = GREEN;
    break;
  case GREEN:
    changed = turn_green();
    color = RED;
    break;
  }
  led_changed = changed;
  led_update();
}

