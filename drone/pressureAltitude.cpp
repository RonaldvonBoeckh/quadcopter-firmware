#include<pressureAltitude.h>
#include<arduino.h>

void PressureAltitude::init(){
	bmp_temp = bmp.getTemperatureSensor();	//assign pointer vals to respective sensors
	bmp_pressure = bmp.getPressureSensor();
	bmp.begin();
	bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
				Adafruit_BMP280::SAMPLING_NONE,     /* Temp. oversampling */
				Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
				Adafruit_BMP280::FILTER_X16,      /* Filtering. */
				Adafruit_BMP280::STANDBY_MS_1); /* Standby time. */
}

void PressureAltitude::setAltitude(float current_altitude){
	//set calibration altitude to the inputted one by the user
	calibrated_altitude = current_altitude;

	//gather 10 pressure samples to get a better estimate of current presure
	sensors_event_t pressure_event;
	int average_num = 10;
	for (int i = 0; i<average_num; i++){
		bmp_pressure->getEvent(&pressure_event);
		calibrated_pressure += pressure_event.pressure*100;	//meas in hPa, so put into Pa
	}
	calibrated_pressure /= average_num;

	//now we use the current pressure and altitude to find equivalent sea level pressure
	//using barometric formula https://en.wikipedia.org/wiki/Barometric_formula
	float denominator = pow( ((REFERENCE_TEMP + LAPSE_RATE * current_altitude) / REFERENCE_TEMP ), PRESSURE_EXP);
	ref_pressure = calibrated_pressure / denominator;
	Serial.print(ref_pressure);
}

float PressureAltitude::getRefPressure(){
	return ref_pressure;
}


void PressureAltitude::getAltitude(float * altitude, float * pressure){
	sensors_event_t pressure_event;
	bmp_pressure->getEvent(&pressure_event);
	*pressure = pressure_event.pressure;
	//using barometric formula
	*altitude = ALTITUDE_COEFF * (1 - pow((*pressure*100 / ref_pressure), (1 / PRESSURE_EXP)) );
}

PressureAltitude::PressureAltitude(){
	ref_pressure = NOMINAL_SEA_PRESSURE;	//set to nominal in case it was not init by the setAltitude
}