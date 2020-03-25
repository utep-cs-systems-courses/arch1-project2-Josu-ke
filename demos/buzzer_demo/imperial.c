#include "buzzer.h"
#include <msp430.h>
#define a 440
#define f 349
#define cH 150

void delay_ms(unsigned int ms){
  unsigned int i;
  for (i = 0; i<= ms; i++){
    //   __delay_cycles(500);
    }  //Built-in function that suspends the execution for 500 cicles
}

void delay_us(unsigned int us){
  unsigned int i;
  for (i = 0; i<= us/2; i++){
    // __delay_cycles(1);
  }
}

void beep(unsigned int note, unsigned int duration){
  int i;

  long delay = (long)(10000/note);  //This is the semiperiod of each note.

  long time = (long)((duration*100)/(delay*2));  //This is how much time we need to spend on the note.

  for (i=0;i<time;i++)

    {

      P1OUT |= 0x02;     //Set P1.2...

      //  delay_us(delay);   //...for a semiperiod...

      P1OUT &= ~0x02;    //...then reset it...

      //  delay_us(delay);   //...for the other semiperiod.

    }

  //  delay_ms(20); //Add a little delay to separate the single notes
}

void play(){
  beep(a, 500);

  beep(a, 500);

  beep(a, 500);

  beep(f, 350);

  beep(cH, 150);

  beep(a, 500);

  beep(f, 350);

  beep(cH, 150);

  beep(a, 650);

}

int main(void){
  //  WDTCTL = WDTPW + WDTHOLD; //Disable Watchdog Timer

  // P1DIR|=BIT2;              // P1.2 output

  while(1){
    play();// delay_ms(2000);
    }

}

