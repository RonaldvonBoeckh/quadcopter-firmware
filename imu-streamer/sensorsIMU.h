#ifndef SENSORS_HEADER
#define SENSORS_HEADER

#include <imustreamtypes.h>

#include <Adafruit_LSM6DS33.h>
#include <math.h>

typedef struct{
	float gyrox;
	float gyroy;
	float gyroz;
}imu_calib_t;

class Sensors {
	public:

		void initialize(float aCoeff, float gCoeff);
		
		void calibrate_imu(int samplesNo);

		void reset();

		void attitude_estimation_step(float dt, bool useAccel);

		attitude_t get_attitude();

		Sensors();

		~Sensors();

	private:
	
		void complimentary_filter_init(float aCoeff, float gCoeff);


		float accelCoeff;
		float gyroCoeff;

		imu_calib_t calibration_data;
		bool calibrated;

		attitude_t attitude;
};

#endif