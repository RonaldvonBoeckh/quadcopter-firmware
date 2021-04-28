#ifndef DRONE_HEADER
#define DRONE_HEADER

#include <dronetypedef.h>

#include <droneControl.h>
#include <BLEcom.h>
#include <motors.h>
#include <sensors.h>
#include <andrewboard.h>
#include <Arduino.h>

//drone default setpoint values
#define ALTITUDE_DEFAULT  0.4

//---------------------------------------------------

class Drone {
	public:
		void go();
	
	private:
		void initialize();
		void fly();
		void land();
		void calibrate();
		void stream();
		void reset_control_inputs(ExtU_droneControl_T* control_inputs);

		BLEcom com;
		Motors motors;
		Sensors sensors;
		droneControlModelClass control;

		drone_state_t drone_status;
		int command;


};

typedef struct{
	float timeLast =  0;
	float timeNow = 0;
	float dt = 0;
	int index = 0;
	bool firstLoop = true;
}timeData_t;

#endif



