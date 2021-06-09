#ifndef COMPFILTER
#define COMPFILTER
#include <math.h>
#include <dronetypedef.h>

#define ACOEFF_DEFAULT 0.02
#define GCOEFF_DEFAULT 0.98

class CompFilter{
	private:
		float aCoeff, gCoeff;
	
	public:
		void set_coeffs(float a, float g);
		void step(attitude_t * attitude, vector3_t * accel, vector3_t * gyro, float dt);
		CompFilter();
		~CompFilter();
};

#endif