#include <drone.h>

void Drone::go() {
	//init the drone class
	Drone::initialize();
	Drone::com.send_debug("Initialization complete, in standby mode");

	//inifite loop while in standby
	while(1) {
		Drone::command = Drone::com.get_cmd();

		//in standby, only 3 possible commands
		switch(Drone::command) {
			case CALIBRATE:
				Drone::com.send_debug("Starting calibration");
				Drone::drone_status = calibrating;
				Drone::calibrate();
				Drone::com.send_debug("Done calibration");
				break;
			case STREAM:
				Drone::drone_status = streaming;
				Drone::stream(); 
				break;
			case START_FLYING:
				Drone::drone_status = flying;
				//Drone::fly();
				break;
			default:	//-1 or other, no command
				break;	
		}

		//reset drone state to standby
		Drone::drone_status = standby;
		
	}

}

void Drone::calibrate(){
	//Perform sensor calibration with 5k samples
	Drone::sensors.calibrate_imu(5000);

	//Send cmd to application that calibration is done
	Drone::com.send_cmd(CALIBRATE_DONE);
}

void Drone::stream(){
	float timeLast, timeNow = millis();
	float dt = 0;
	int index = 0;

	//vars for state of drone
	attitude_t attitude;
	float altitude;

	//reset sensors state
	Drone::sensors.reset();

	bool firstLoop = true;

	//Step sensors object in inf loop
	while(1){
		timeNow = millis();

		//dt is massive for first loop, so set to 0
		if(firstLoop){
			dt = 0;
			firstLoop = false;
		}
		else{
			dt = (timeNow-timeLast) / 1000;
		}
		
		Drone::sensors.attitude_estimation_step(dt);
		//Drone::sensors.altitude_estimation_step();

		//step index and update timeLast to timenow
		timeLast = timeNow;
		index ++;

		//if index is 4, time to reset index and reset
		if(index>=20){
			index = 0;
			attitude = Drone::sensors.get_attitude();
			altitude = 40;
			Drone::com.send_state(attitude, altitude, dt*1000);
		}

		//delay(10);

		//check for stop streaming command from app, and break inf loop if received
		Drone::command = Drone::com.get_cmd();
		if(Drone::command == STREAM_STOP){
			break;
		}
	}
}

/**
 * @brief Drone goes into fly mode. Performs control loop until land signal is received via ble
 * then calls Drone:land();
 * 
 */
void Drone::fly(){
	/** Perform the control loop
	 * 1.get altitude setpoint
	 * 2.poll sensors
	 * 3.perform control loop
	 * 4.check for land command */

	//create variables for state estimates and time calcs
	float altitude, altitude_setpoint;
	attitude_t attitude;
	ExtU_droneControl_T control_inputs;
	bool newInput = false;
	float timeLast, timeNow = millis();
	float dt = 0;

	//reset sensors class
	Drone::sensors.reset();


	//set all control inputs to default
	Drone::default_control(&control_inputs);
	Drone::control.setExternalInputs(&control_inputs);

	while(1) {
		newInput = false;
		//get altitude setpoint from ble, if new, assign to control input
		altitude_setpoint = Drone::com.get_altitude();
		if(altitude_setpoint>0){
			control_inputs.altitude_setpoint = altitude_setpoint;
			newInput = true
		}
	}

}

void Drone::default_control( ExtU_droneControl_T* control_inputs){
	control_inputs->altitude_setpoint = ALTITUDE_DEFAULT;
	control_inputs->roll_setpoint = 0;
	control_inputs->pitch_setpoints = 0;
	control_inputs->yaw_setpoint = 0;
}

/**
 * @brief Drone goes into landing mode. Sets altitude setpoint to 30cm, then once reached turns off motors
 * and then goes into standby mode
 * 
 */
void Drone::land(){

}

void Drone::initialize(){
	//Initialize sub-classes
	Drone::sensors.initialize(0.02, 0.98);	//sensors class
	Drone::com.ble_uart_init();		//ble com class
	Drone::motors.initialize();		//pwm motor driver

	//init the control when needed in flying mode
	
	//wait for ble con to be established
	bool connected;
	while(!Drone::com.is_connected()){
		delay(10);
	}


	//send debug mesg
	Drone::com.send_debug("Connection established");

	//set drone state to standby
	Drone::drone_status = standby;
}