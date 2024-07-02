#include<lpc214x.h>
#include"TIMER.H"
#include"ULTRASONIC.H"
unsigned int range=0,i;
int main()
{
 PINSEL0 &= 0xFCFFFFFF; //P0.12
 IODIR0 |= 0x00001000; //P0.12 as O/P
 ultrasonic_init();
 while(1) 
 {
 range=get_range();
 if(range > 50) 
 {
 IOSET0 |= 0x00001000;
 timer0delay(1000);
 //set line low
 IOCLR0 |= 0x00001000;
 timer0delay(1000);
 }
 }
}
