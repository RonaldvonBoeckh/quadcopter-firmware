/* Board and Drone definition header
*/
#ifndef ANDREW_BOARD
#define ANDREW_BOARD

//Pin numbers for PWM outputs
#define MOTOR_RF 5 //orange
#define MOTOR_RB 6 //yellow
#define MOTOR_LB 9 //green
#define MOTOR_LF 10 //blue

#define IR_PIN A0

#define LED_BLINK 13

//Thrust max and min values (us)
#define PWM_MIN 125 
#define PWM_MAX 250  


#endif