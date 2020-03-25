#include "songs.h"
#include "buzzer.h"
#include "libTimer.h"
#include <msp430.h>

void delay_m(unsigned int ms){
  unsigned int i;
  for (i = 0; i<= ms; i++){
       __delay_cycles(500);
    }  //Built-in function that suspends the execution for 500 cycles
}

void delay_u(unsigned int us){
  unsigned int i;
  for (i = 0; i<= us/2; i++){
     __delay_cycles(1);
  }
}

void sound(unsigned int note, unsigned int duration){
  int i;
  long delay = (long)(10000/note); 
  long time = (long)((duration*100)/(delay*2));
  
  for (i=0;i<time;i++)
    {
       buzzer_set_period(note);//plays note at pitch
       delay_u(delay);
    }
    delay_m(2000000); //Add a delay
}
//instructions of the song 
void play(){
   sound(b,50000);
   sound(d,1);
   sound(a,50000);

   sound(g,1);
   sound(a,1);
   
   sound(b,50000);
   sound(d,1);
   sound(a,50000);

   delay_m(20);
   
   sound(b,50000);
   sound(d,1);
   sound(asix,50000);

   sound(gsix,1);
   sound(d,5000);

   sound(csix,1);
   sound(b,1);
   sound(a,1);


}
