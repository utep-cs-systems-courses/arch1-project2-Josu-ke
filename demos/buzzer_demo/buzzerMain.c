#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#define a 2217.46
#define f 349
#define asix 1108.73
#define gS 415
#define b 1975.53
#define d 1661.22
#define csix 1864.66
#define g 2489.02
int main() {
    configureClocks();
 
    buzzer_init();
    // buzzer_set_period(440);
    while(1){
      // play();
     delay_ms(2000);
    }
    //  buzzer_set_period(1000);
    // buzzer_set_period(900);/* start buzzing!!! */
    or_sr(0x18);          // CPU off, GIE on
}

void delay_ms(unsigned int ms){
  unsigned int i;
  for (i = 0; i<= ms; i++){
       __delay_cycles(6000);
    }  //Built-in function that suspends the execution for 500 cicles
}

void delay_us(unsigned int us){
  unsigned int i;
  for (i = 0; i<= us/2; i++){
     __delay_cycles(100);
  }
}

void beep(unsigned int note, unsigned int duration){
  int i;

  long delay = (long)(10000/note);  //This is the semiperiod of each note.

  long time = (long)((duration*100)/(delay*2));  //This is how much time we need to spend on the note .
  

  for (i=0;i<time;i++)

    {

      P2OUT |= BIT6;
      buzzer_set_period(note);//Set P1.2...

        delay_us(delay);
	//buzzer_set_period(note);//...for a semiperiod...

      P2OUT &= ~BIT6;    //...then reset it...

       delay_us(delay);   //...for the other semiperiod.

    }

    delay_ms(2000); //Add a little delay to separate the single notes
}

void play(){
   beep(b,50000);
   beep(d,1);
   beep(a,50000);

   beep(g,1);
   beep(a,1);
   
   beep(b,50000);
   beep(d,1);
   beep(a,50000);

   delay_ms(20);
   
   beep(b,50000);
   beep(d,1);
   beep(asix,50000);

   beep(1244.51,1);
   beep(d,5000);

   beep(csix,1);
   beep(b,1);
   beep(a,1);


}

