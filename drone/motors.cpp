#include <motors.h>


void Motors::initialize() {
	//attach motors to respective pins
	motor_rf.attach(MOTOR_RF);
	motor_rb.attach(MOTOR_RB);
	motor_lb.attach(MOTOR_LB);
	motor_lf.attach(MOTOR_LF);

	// pulse_min = ;
	// pulse_max = 2000;

	//Actuate all motors to 0 thorttle
	motor_rf.writeMicroseconds(MIN_PULSE_WIDTH);
	motor_rb.writeMicroseconds(MIN_PULSE_WIDTH);
	motor_lb.writeMicroseconds(MIN_PULSE_WIDTH);
	motor_lf.writeMicroseconds(MIN_PULSE_WIDTH);

}

void Motors::kill(){
	motor_rf.writeMicroseconds(MIN_PULSE_WIDTH);
	motor_rb.writeMicroseconds(MIN_PULSE_WIDTH);
	motor_lb.writeMicroseconds(MIN_PULSE_WIDTH);
	motor_lf.writeMicroseconds(MIN_PULSE_WIDTH);
}

void Motors::update(ExtY_droneControl_T * throttles) {
	//compute pulse widths
	float pulse_rf = throttles->motor_rf_throttle * (MAX_PULSE_WIDTH - MIN_PULSE_WIDTH) + MIN_PULSE_WIDTH;
	float pulse_rb = throttles->motor_rb_throttle * (MAX_PULSE_WIDTH - MIN_PULSE_WIDTH) + MIN_PULSE_WIDTH;
	float pulse_lb = throttles->motor_lb_throttle * (MAX_PULSE_WIDTH - MIN_PULSE_WIDTH) + MIN_PULSE_WIDTH;
	float pulse_lf = throttles->motor_lf_throttle * (MAX_PULSE_WIDTH - MIN_PULSE_WIDTH) + MIN_PULSE_WIDTH;

	//Actuate motor values
	motor_rf.writeMicroseconds(pulse_rf);
	motor_rb.writeMicroseconds(pulse_rb);
	motor_lb.writeMicroseconds(pulse_lb);
	motor_lf.writeMicroseconds(pulse_lf);
}

void Motors::detach() {
	motor_rf.detach();
	motor_rb.detach();
	motor_lb.detach();
	motor_lf.detach();
}

Motors::Motors(){

}

Motors::~Motors(){

}