#define trig (1<<8) //P0.8
#define echo (IO0PIN&(1<<9)) //P0.9 as EINT3
void ultrasonic_init();
void send_pulse();
unsigned int get_range();
void ultrasonic_init()
{
 IO0DIR|=(1<<8); //Configures pin P0.8 as an output pin
 T0CTCR=0; // Setting T0CTCR to 0 configures the 
timer in Timer Mode.
 T0PR=59; //allowing the timer to generate 
delays in microseconds
}
void send_pulse() //function to transmit an 
ultrasonic pulse.
{
 T0TC=T0PC=0;
 IO0SET=trig; //trig=1
 timer1delay(10); //10us delay
 IO0CLR=trig; //trig=0
//First set the timer value to zero. Then we are giving high to 
trigger pin (1). We have to wait for 10u Seconds. So I’m using 
generating a 10us delay using timer 1. Then make the trigger 
pin to low (0).
}
unsigned int get_range() //function for obtaining 
the distance measured by an ultrasonic sensor 
6
{
 unsigned int get=0;
 send_pulse();
 while(!echo); //Waits until the echo signal is 
received. This is to ensure the ultrasonic pulse has been 
transmitted and the sensor is ready to receive the echo.
 T0TCR=0x01; //Starts Timer 0 to measure the 
time.
 while(echo); //Waits until the echo signal ends, 
indicating the return of the ultrasonic pulse's echo.
 T0TCR=0; //Stops Timer 0 after 
receiving the echo signal.
 get=T0TC; //Reads the time count 
stored in Timer 0, which represents the time taken for the 
ultrasonic pulse to travel to the target object and return as an 
echo.
//CALCULATION
 if(get<38000)
 get=get/59;
 else
 get=0;
 return get;
}
