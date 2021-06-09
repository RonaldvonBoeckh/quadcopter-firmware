#ifndef ATTITUDE_ESTIMATION
#define ATTITUDE_ESTIMATION

#include <compFilter.h>
#include <Adafruit_LSM6DS33.h>
#include <dronetypedef.h>

class AttitudeEstimation{
	private:
		CompFilter compfilter;	//complimentary filter class
		Adafruit_LSM6DS33 lsm6;	//driver for IMU

		vector3_t gyro_bias;	//3d vector to hold gyro bias values




	public:
		void init();
		void step(attitude_t * attitude, float dt);
		void gyro_bias_calibrate(int num_samples);
		AttitudeEstimation();
		~AttitudeEstimation();
};

#endif