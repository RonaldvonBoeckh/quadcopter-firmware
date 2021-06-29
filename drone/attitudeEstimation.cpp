/*
Author: ARB
Project: Quadcopter v1
---------------------------------------------------------
Attitude estimation class

INTERFACES:
	upstream:
		flightSystem
	downstream:
		IMU library
		Comp filter class

API:
	Upstream:
		Is instantiated in the flight flightSystem class
		->initiates this class
			IMU params
			Comp Filter params
			etc.
		->tells this class to step (with dt) for filters
		->asks for current attitude estimate
	Downstream:
		->gets data from IMU
		->sets IMU params
		->complimentary filter step
*/

#include <attitudeEstimation.h>
#include <Adafruit_LSM6DS33.h>		//imu sensor
#include <math.h>

void AttitudeEstimation::init(){
	lsm6.begin_I2C();
	lsm6.setAccelRange(LSM6DS_ACCEL_RANGE_2_G);
	lsm6.setAccelDataRate(LSM6DS_RATE_208_HZ);
	lsm6.setGyroRange(LSM6DS_GYRO_RANGE_500_DPS);
	lsm6.setGyroDataRate(LSM6DS_RATE_208_HZ);		//>= loop rate ideally
}

double AttitudeEstimation::acc_resultant(){
	sensors_event_t accel;
	sensors_event_t gyro;
	sensors_event_t temp;
	lsm6.getEvent(&accel, &gyro, &temp);

	return sqrt(pow(accel.acceleration.x,2) + pow(accel.acceleration.y,2) + pow(accel.acceleration.z,2));
}

/**
 * @brief 
 * 
 * @param attitude current attitude to be used for next step estimation, new attitude is placed in this var after the step
 * @param dt time step since last step of attitude estimation
 */
void AttitudeEstimation::step(attitude_t * attitude, float dt){
	//first get the accel and gyro values
	sensors_event_t accel;
	sensors_event_t gyro;
	sensors_event_t temp;
	lsm6.getEvent(&accel, &gyro, &temp);

	//put into 3d vector structs as defined by the CompFilter::step()
	vector3_t accel_v;
	vector3_t gyro_v;
	accel_v.x = accel.acceleration.x;
	accel_v.y = accel.acceleration.y;
	accel_v.z = accel.acceleration.z;
	gyro_v.x = gyro.gyro.x - gyro_bias.x;	//remove gyro biases
	gyro_v.y = gyro.gyro.y - gyro_bias.y;
	gyro_v.z = gyro.gyro.z - gyro_bias.z;
	//do step, attitude will have new attitude estimate
	compfilter.step(attitude, &accel_v, &gyro_v, dt);

}

/**
 * @brief Function that takes a set of gyro samples to find the gyro bias in all axes
 * 
 * @param num_samples number of samples to compute the gyro biases
 */
void AttitudeEstimation::gyro_bias_calibrate(int num_samples){
	//vars to get imu vals
	sensors_event_t accel;
	sensors_event_t gyro;
	sensors_event_t temp;

	for(int i=0; i<num_samples; i++){
		lsm6.getEvent(&accel, &gyro, &temp);
		gyro_bias.x += gyro.gyro.x;
		gyro_bias.y += gyro.gyro.y;
		gyro_bias.z += gyro.gyro.z;
	}

	gyro_bias.x /= num_samples;
	gyro_bias.y /= num_samples;
	gyro_bias.z /= num_samples;	
}

AttitudeEstimation::AttitudeEstimation(){
	//set the gyro biases to 0 as default to ensure they are initialized
	gyro_bias.x = 0;
	gyro_bias.y = 0;
	gyro_bias.z = 0;
}

AttitudeEstimation::~AttitudeEstimation(){
	
}



