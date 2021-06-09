#ifndef PRESSUREALTITUDE_HEADER
#define PRESSUREALTITUDE_HEADER
#include <Adafruit_BMP280.h>
#include <math.h>

#define PRESSURE_EXP 5.2558
#define REFERENCE_TEMP 288
#define LAPSE_RATE -0.0065
#define ALTITUDE_COEFF 44308
#define NOMINAL_SEA_PRESSURE 101325

class PressureAltitude{
	public:
		void init();
		void setAltitude(float current_altitude);
		void getAltitude(float * altitude);
		PressureAltitude();

	private:
		float calibrated_altitude, calibrated_pressure;
		float ref_pressure;
		Adafruit_BMP280 bmp;
		Adafruit_Sensor *bmp_temp;
		Adafruit_Sensor *bmp_pressure;
};

#endif

