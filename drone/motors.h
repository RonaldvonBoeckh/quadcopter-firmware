

#ifndef MOTORS_HEADER
#define MOTORS_HEADER

#include <dronetypedef.h>
#include <Arduino.h>

#include <andrewboard.h>
#include <Servo.h>

class Motors {
	public:

		void initialize();
		void update(ExtY_control_T throttles);
		void detach();
		
		Motors();
		~Motors();

	private:

		Servo motor_rf;
		Servo motor_rb;
		Servo motor_lb;
		Servo motor_lf;

		float pulse_min;
		float pulse_max;



};

#endif
