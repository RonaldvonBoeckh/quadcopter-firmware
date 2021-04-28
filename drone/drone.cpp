#include <drone.h>

void Drone::go() {
	//init the drone class
	Drone::initialize();
	//set drone state to standby
	Drone::drone_status = standby;
	Drone::com.send_debug("Init done, con est, in standby mode");

	//inifite loop while in standby
	while(1) {
		Drone::command = Drone::com.get_cmd();
		//in standby, only 3 possible commands
		switch(Drone::command) {
			case CALIBRATE:
				Drone::drone_status = calibrating;
				Drone::com.send_debug("Starting calibration");
				Drone::calibrate();
				Drone::com.send_debug("Done calibration");
				break;
			case STREAM:
				Drone::drone_status = streaming;
				Drone::com.send_debug("Starting streaming");
				Drone::stream(); 
				Drone::com.send_debug("Done streaming");
				break;
			case START_FLYING:
				Drone::com.send_debug("Starting flying");
				Drone::drone_status = flying;
				Drone::fly();
				Drone::com.send_debug("Landed");
				break;
			default:	//-1 (no new cmd) or 0 (no command)
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
	//vars for state of drone
	attitude_t attitude;
	float altitude;

	//reset sensors state
	Drone::sensors.reset();

	//init time data struct
	timeData_t timeData;

	//Step sensors object in inf loop
	while(1){
		timeData.timeNow = millis();

		//dt is massive for first loop, so set to 0
		if(timeData.firstLoop){
			timeData.dt = 0;
			timeData.firstLoop = false;
		}
		else{
			timeData.dt = (timeData.timeNow-timeData.timeLast) / 1000;
		}
		
		Drone::sensors.attitude_estimation_step(dt);
		Drone::sensors.altitude_estimation_step();

		//step index and update timeLast to timenow
		timeData.timeLast = timeData.timeNow;
		timeData.index ++;

		//if index is 20, time to reset index and reset
		if(timeData.index>=20){
			timeData.index = 0;
			attitude = Drone::sensors.get_attitude();
			altitude = sensors.get_altitude();
			Drone::com.send_state(attitude, altitude, timeData.dt*1000);
		}


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
	 * 1.get new setpoints, if new ones -> set to control system
	 * 2.poll sensors
	 * 3.perform control loop
	 * 4.check for land command */

	//create variables for state estimates
	float altitude, altitude_setpoint;
	attitude_t attitude;
	ExtU_droneControl_T control_inputs;


	//reset sensors class
	Drone::sensors.reset();

	//time data struct
	timeData_t timeData;

	//set all control inputs to default
	Drone::rest_control_inputs(&control_inputs);
	Drone::control.setExternalInputs(&control_inputs);

	while(1) {
		//FIND NEW DT
		timeData.timeNow = millis();
		//dt is massive for first loop, so set to 0
		if(timeData.firstLoop){
			timeData.dt = 0;
			timeData.firstLoop = false;
		}
		else{
			timeData.dt = (timeData.timeNow-timeData.timeLast) / 1000;
		}

		//NEW INPUT CHECKING
		//if flying, check for new altitude setpoint
		if(drone_status == flying){
			altitude_setpoint = Drone::com.get_altitude();
			if(altitude_setpoint>0){
				control_inputs.altitude_setpoint = altitude_setpoint;
			}
		}
	
		/*
		*later add code for changing attitude setpoints
		*/

		//STEP AND POLL SENSORS
		sensors.attitude_estimation_step(dt);
		sensors.altitude_estimation_step();		//designed for ~200Hz, fixed dt

		//step index and update timeLast to timenow
		timeData.timeLast = timeData.timeNow;

		//get attitude and altitude
		attitude = sensors.get_attitude();
		altitude = sensors.get_altitude();
		
		//if drone is in landing status, check to see if it is landing range
		if(drone_status == landing){
			//check if in landing range
			if( (altitude < LANDING_ALTITUDE + LANDING_TOL) & (altitude > LANDING_ALTITUDE - LANDING_TOL) ){
				motors.kill();
				break
			}
		}

		//set control system inputs
		control_inputs.roll_value = attitude.roll;
		control_inputs.pitch_value = attitude.pitch;
		control_inputs.yaw_value = attitude.yaw;
		control_inputs.altitude_value = altitude;
		control.setExternalInputs(&control_inputs);

		//step control system
		control.step();

		//write command to motors
		motors.update(&control.getExternalOutputs());

		//CHECK FOR LAND COMMAND
		Drone::command = Drone::com.get_cmd();
		if(Drone::command == STOP_FLYING){
			drone_status = landing;
			control_inputs.altitude_setpoint = LANDING_ALTITUDE;
		}

	}

}

/**
 * @brief sets the control inputs to control system to 0
 * 
 * @param control_inputs 
 */
void Drone::reset_control_inputs( ExtU_droneControl_T* control_inputs){
	control_inputs->altitude_setpoint = ALTITUDE_DEFAULT;
	control_inputs->altitude_value = 0;
	control_inputs->roll_setpoint = 0;
	control_inputs->roll_value = 0;
	control_inputs->pitch_setpoints = 0;
	control_inputs->pitch_value = 0;
	control_inputs->yaw_setpoint = 0;
	control_inputs->yaw_value = 0;
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

	
	//wait for ble con to be established
	bool connected;
	while(!Drone::com.is_connected()){
		delay(10);
	}

	//send debug mesg
	Drone::com.send_debug("Connection established");
}