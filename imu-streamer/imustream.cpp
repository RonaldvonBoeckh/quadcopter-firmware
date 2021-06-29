#include <imustream.h>

void IMUstreamer::go() {
	//init the drone class
	IMUstreamer::initialize();

	//inifite loop while in standby
	while(1) {
		IMUstreamer::command = IMUstreamer::com.get_cmd();

		//in standby, only 3 possible commands
		switch(IMUstreamer::command) {
			case CALIBRATE:
				delay(20);
				IMUstreamer::com.send_debug("Starting calibration");
				delay(20);
				IMUstreamer::calibrate();
				break;
			case START_COLLECT:
				delay(20);
				IMUstreamer::com.send_debug("Starting data collection");
				delay(20);
				IMUstreamer::collect_data(); 
				break;
			default:	//-1 or other, no command
				break;	
		}
		
	}

}

void IMUstreamer::calibrate(){
	//Perform sensor calibration with 5k samples
	IMUstreamer::sensors.calibrate_imu(1000);

	//Send cmd to application that calibration is done
	IMUstreamer::com.send_cmd(CALIBRATE_DONE_CMD);
}

void IMUstreamer::collect_data(){
	digitalWrite(13,HIGH);

	IMUstreamer::sensors.reset();

	float timeStart = millis();
	float timeNow, timeLast = millis();
	float dt = 0;
	int finalIndex = 0;
	const int maxIndex = 1000;		//to allocate array space

	//vars for state of drone
	attitude_t attitude;	//to hold temp values
	float time;
	bool useAccel = true;

	bool firstLoop = true;
	//collect sensor data and send if reach maxIndex, or told to stop by matlab app
	for(int i = 0; i < maxIndex; i++){
		timeNow = millis();

		if(firstLoop){
			dt = 0;
			firstLoop = false;
		}
		else{
			dt = (timeNow-timeLast) / 1000;
		}
		//step comp filter
		IMUstreamer::sensors.attitude_estimation_step(dt, useAccel);

		//get state estimate and time
		attitude = IMUstreamer::sensors.get_attitude();
		time = timeNow - timeStart;

		if(time>1000){
			useAccel = true;
		}

		//trasmit data
		IMUstreamer::com.send_state(attitude, time);

		//step index and update timeLast to timenow
		timeLast = timeNow;

		//check for stop streaming command from app, and break inf loop if received
		IMUstreamer::command = IMUstreamer::com.get_cmd();
		if(IMUstreamer::command == STOP_COLLECT){
			break;
		}
	}

	IMUstreamer::com.send_cmd(SENDING_DONE_CMD);

	digitalWrite(13,LOW);
}

void IMUstreamer::initialize(){
	//Initialize sub-classes
	IMUstreamer::sensors.initialize(0.05, 0.95);	//sensors class
	IMUstreamer::com.ble_uart_init();		//ble com class
	
	//wait for ble con to be established
	bool connected;
	while(!IMUstreamer::com.is_connected()){
		delay(10);
	}

	delay(5000);

	//send debug mesg
	IMUstreamer::com.send_debug("Connection established");
	delay(20);
}