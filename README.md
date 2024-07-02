# Manhole_Lid_open_detection_and_Alarming
An embedded C project which deals with detection of Manhole lid open, and will alarm respect Munciple office. This project is carried out on LPC2148 micro-controller using embedded C programming language and by using KEIL IDE. 
This project contains different Drivers codes for different components. which are controlled by microcontroller. 

Following is the list of components.
1. Microcontroller LPC2148
2. Ultrasonic sensor HCSR04
3. GSM module
4. Power supply
5. LED indicator
6. Selenoid Actuator or Driver motor.

#Working
1. power supply will be connected to moicro controller and the ultrasonic sensor will be attached at the bottom of the manhole.
2. the initial distance of closed lid from sensor's transmitter will be set as the threshold of the alarming.
3. the sensor will be contineously detecting the distance between the Lid and Transmitter.
4. if the distance crosses the threshold it will send an alret to microcontroller.
5. Here MC will activate the acctuator or the driver motor we can say. and GSM module will send the location of the manhole to the near munciple cooperation.
6. simultaneously the LED which will be situated at the top of selenoid acctuator will rise and will start to glow.
