#include <sensors.h>

Adafruit_LSM6DS33 lsm6;	//made global to try to fix bug

void Sensors::initialize(float aCoeff = 0.02 , float gCoeff = 0.98){

	//set vars to 0 to initialize
	Sensors::attitude.roll = 0;
	Sensors::attitude.pitch = 0;
	Sensors::attitude.yaw = 0;

	//make sure all calib data is set to 0
	Sensors::calibration_data.accelx = 0;
	Sensors::calibration_data.accely = 0;
	Sensors::calibration_data.accelz = 0;
	Sensors::calibration_data.gyrox = 0;
	Sensors::calibration_data.gyroy = 0;
	Sensors::calibration_data.gyroz = 0;
	Sensors::calibrated = false;

	lsm6.begin_I2C();

	//init the com filter
	Sensors::complimentary_filter_init(aCoeff, gCoeff);
	//init the lpf
	Sensors::IR_initialize();
	


}


void Sensors::complimentary_filter_init(float aCoeff, float gCoeff){
	lsm6.begin_I2C();
	//set some params like FS(full-scale) and ODR(output data rate)	
	lsm6.setAccelRange(LSM6DS_ACCEL_RANGE_2_G);
	
	lsm6.setAccelDataRate(LSM6DS_RATE_208_HZ);
	
	lsm6.setGyroRange(LSM6DS_GYRO_RANGE_500_DPS);

	lsm6.setGyroDataRate(LSM6DS_RATE_208_HZ);		//>= loop rate ideally


	//set accel and gyro coefficients to global variables in this file
	accelCoeff = aCoeff;
	gyroCoeff = gCoeff;
}

void Sensors::IR_initialize(){
	
	//init ADC to 14-bit and 3V analog ref
	analogReadResolution(14);
	analogReference(AR_INTERNAL_3_0);
	//init lpf class
	Sensors::lpf.initialize();
}

/**
 * @brief Resets the attitude states of the system to 0. For alttitude, re-unitializes the lpf 
 * 
 */
void Sensors::reset(){
	//set attitude to 0
	Sensors::attitude.roll = 0;
	Sensors::attitude.pitch = 0;
	Sensors::attitude.yaw = 0;

	//re-init the lpf
	Sensors::lpf.initialize();
}

/**
 * @brief fucntion to claibrate the imu by taking acceleromter and gyro values for a set
 * numer of sampes and averaging them to find bias values. The sensor should be level and immobile
 * during this time
 * 
 * @param samplesNo number of samples sensor biases shouls be averaged over
 * @param calibration_data imu_calib_t data struct containing the imu bias values stored
 * as private variable in Sensors class
 * 
 */
void Sensors::calibrate_imu(int samplesNo){

	//structs to put sensor values in 
	static sensors_event_t accel;
	static sensors_event_t gyro;
	static sensors_event_t temp;

	//Reset calibration struct to 0
	// Sensors::calibration_data.accelx = 0;
	// Sensors::calibration_data.accely = 0;
	// Sensors::calibration_data.accelz = 0;
	Sensors::calibration_data.gyrox = 0;
	Sensors::calibration_data.gyroy = 0;
	Sensors::calibration_data.gyroz = 0;

	//run loop of length samplesNo and add all samples together
	for(int i=0; i<samplesNo; i++){
		lsm6.getEvent(&accel, &gyro, &temp);	//colect IMU and place in sensor_event_t variables
		// Sensors::calibration_data.accelx += accel.acceleration.x;
		// Sensors::calibration_data.accely += accel.acceleration.y;
		// Sensors::calibration_data.accelz += accel.acceleration.z;
		Sensors::calibration_data.gyrox += gyro.gyro.x;
		Sensors::calibration_data.gyroy += gyro.gyro.y;
		Sensors::calibration_data.gyroz += gyro.gyro.z;
	}

	//divide sumed data by sample number
	// Sensors::calibration_data.accelx /= samplesNo;
	// Sensors::calibration_data.accely /= samplesNo;
	// Sensors::calibration_data.accelz /= samplesNo;
	Sensors::calibration_data.gyrox /= samplesNo;
	Sensors::calibration_data.gyroy /= samplesNo;
	Sensors::calibration_data.gyroz /= samplesNo;

	//set the calibrated flag to true
	Sensors::calibrated = true;

}

/**
 * @brief step of complimentary filter of imu for attitude estimation
 * 
 * @param dt time since last step
 */
void Sensors::attitude_estimation_step(float dt){

	//structs to put sensor values in 
	static sensors_event_t accel;
	static sensors_event_t gyro;
	static sensors_event_t temp;
	
	//placeholder for acceleration angle estimations
	static float roll_accel_estimation = 0;
	static float pitch_accel_estimation = 0;


	lsm6.getEvent(&accel, &gyro, &temp);	//colect IMU and place in sensor_event_t variables

	//remove bias values from sensors
	float accelx = accel.acceleration.x; //- Sensors::calibration_data.accelx;
	float accely = accel.acceleration.y; //- Sensors::calibration_data.accely;
	float accelz = accel.acceleration.z; //- Sensors::calibration_data.accelz;
	float gyrox = gyro.gyro.x - Sensors::calibration_data.gyrox;
	float gyroy = gyro.gyro.y - Sensors::calibration_data.gyroy;
	float gyroz = gyro.gyro.z - Sensors::calibration_data.gyroz;


	if(accelz > 0)
	{
		roll_accel_estimation = atan(accely/accelz);
	} 
	else
	{
		if(accel.acceleration.y > 0)
		{
			roll_accel_estimation = M_PI/2 - atan(accelz/accely);
		}
		else
		{
			roll_accel_estimation = -M_PI/2 - atan(accelz/accely);
		}
	}

	//pitch estimation from accel data
	if(accelz > 0)
	{
		pitch_accel_estimation = -atan(accelx/accelz);
	}
	else
	{
		if(accelx < 0)
		{
			pitch_accel_estimation = M_PI/2 + atan(accelz/accelx);
		}
		else
		{
			pitch_accel_estimation = -M_PI/2 + atan(accelz/accelx);
		}
	}

	Sensors::attitude.roll = (Sensors::attitude.roll + gyrox * dt) * gyroCoeff + roll_accel_estimation * accelCoeff;
	Sensors::attitude.pitch = (Sensors::attitude.pitch + gyroy * dt) * gyroCoeff + pitch_accel_estimation * accelCoeff;
	Sensors::attitude.yaw = Sensors::attitude.yaw + gyroz * dt;

}

/**
 * @brief read ADC value of IR sensor and input to LPF. Should be ~200Hz
 * */
void Sensors::altitude_estimation_step(){
	static real_T adc_val = 0;
	static real_T voltage = 0;
	static ExtU_LPF_T lpf_input;

	//conversion from ADC -> distance in m
	adc_val = analogRead(A0);				//read analog value
	voltage = (float(adc_val)/float(16384))*3;  //ADC 14-bit with 3V range
	lpf_input.LPF_in = (56.25/voltage + 0.125)*0.01;           //from datasheet. Distance in m	

	Sensors::lpf.setExternalInputs(&lpf_input);
	Sensors::lpf.step();

}

/**
 * @brief API function to return estimated attitude of drone
 * 
 * @return attitude_t struct containing roll,pitch,yaw
 */
attitude_t Sensors::get_attitude(){
	return attitude;
}

/**
 * @brief API function to return estimated altitude of drone 
 * 
 * @return ExtY_LPF_T 
 */
float Sensors::get_altitude(){
	ExtY_LPF_T lpf_output = lpf.getExternalOutputs();
	float altitude = lpf_output.LPF_out;
	return altitude;
}

Sensors::Sensors(){

}

Sensors::~Sensors(){

}