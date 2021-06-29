#ifndef IMUSTREAMER_HEADER
#define IMUSTREAMER_HEADER

#include <imustreamtypes.h>

#include <BLEcomIMU.h>
#include <sensorsIMU.h>

class IMUstreamer{
	public:
		void go();

	private:
		void initialize();
		void calibrate();
		void collect_data();

		BLEcom com;
		Sensors sensors;

		int command;
};




#endif