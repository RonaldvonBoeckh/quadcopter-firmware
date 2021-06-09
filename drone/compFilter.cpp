/*
Author: ARB
Project: Quadcopter v1
---------------------------------------------
Complimentary filter class for Gyro and Accel
*/
#include <compFilter.h>

/**
 * @brief set the complimentary accel and gyro coefficients
 * 
 * @param a accel coeff
 * @param g gyro coeff
 */
void CompFilter::set_coeffs(float a, float g){
	aCoeff = a;
	gCoeff = g;
}

/**
 * @brief step of a complimentary filter for accel and gyro in 3 axes
 * 
 * @param attitude pointer to attitude struct new value overrides old one
 * @param accel 3d vector struct of accel values
 * @param gyro  3d vector struct of gyro values
 * @param dt time since last comp filter estimation
 */
void CompFilter::step(attitude_t * attitude, vector3_t * accel, vector3_t * gyro, float dt){
	//placeholder for acceleration angle estimations
	float roll_accel_estimation = 0;
	float pitch_accel_estimation = 0;
	
	if(accel->z > 0)
	{
		roll_accel_estimation = atan(accel->y/accel->z);
	} 
	else
	{
		if(accel->y > 0)
		{
			roll_accel_estimation = M_PI/2 - atan(accel->z/accel->y);
		}
		else
		{
			roll_accel_estimation = -M_PI/2 - atan(accel->z/accel->y);
		}
	}

	//pitch estimation from accel data
	if(accel->z > 0)
	{
		pitch_accel_estimation = -atan(accel->x/accel->z);
	}
	else
	{
		if(accel->x < 0)
		{
			pitch_accel_estimation = M_PI/2 + atan(accel->z/accel->x);
		}
		else
		{
			pitch_accel_estimation = -M_PI/2 + atan(accel->z/accel->x);
		}
	}

	attitude->roll = (attitude->roll + gyro->x * dt) * gCoeff + roll_accel_estimation * aCoeff;
	attitude->pitch = (attitude->pitch + gyro->y * dt) * gCoeff + pitch_accel_estimation * aCoeff;
	attitude->yaw = attitude->yaw + gyro->z * dt;
}

CompFilter::CompFilter(){
	//set coeffs to default values
	aCoeff = ACOEFF_DEFAULT;
	gCoeff = GCOEFF_DEFAULT;
}

CompFilter::~CompFilter(){
	
}