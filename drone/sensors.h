#ifndef SENSORS_HEADER
#define SENSORS_HEADER

#include <dronetypedef.h>

#include <LPF.h>
#include <Arduino.h>

#include <Adafruit_LSM6DS33.h>
#include <Adafruit_BMP280.h>
#include <math.h>



typedef struct{
	float accelx;
	float accely;
	float accelz;
	float gyrox;
	float gyroy;
	float gyroz;
}imu_calib_t;

class Sensors {
	public:

		void initialize(float aCoeff, float gCoeff);
		
		void calibrate_imu(int samplesNo);

		void reset();

		void attitude_estimation_step(float dt);

		void altitude_estimation_step();

		attitude_t get_attitude();
		
		float get_altitude();

		Sensors();

		~Sensors();

	private:
	
		void IR_initialize();
		void complimentary_filter_init(float aCoeff, float gCoeff);


		Adafruit_BMP280 bmp280;

		float accelCoeff;
		float gyroCoeff;

		imu_calib_t calibration_data;
		bool calibrated;

		attitude_t attitude;

		//add LPF class here
		LPFModelClass lpf;
};

#endif