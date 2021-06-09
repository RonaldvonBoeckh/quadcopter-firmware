#ifndef DRONE_TYPES_HEADER
#define DRONE_TYPES_HEADER

#include <droneControl.h>	//for control types from matlab generated code
#include <BLEcom.h>		//for ble com params like packet length

//struct for attitude angles
typedef struct {
	real_T roll = 0;
	real_T pitch = 0;
	real_T yaw = 0;
} attitude_t;

//enum for states
enum drone_state_t{
	standby = 0,
	calibrating = 1,
	streaming = 2,
	flying = 3,
	landing = 4,
};

typedef struct{
	float x = 0;
	float y = 0;
	float z = 0;
} vector3_t;

//class to keep track of commands
class cmd_t{
	private:
		bool new_val = false;					//track if new val has been recieved

	public:
		char msg[BLE_PACKET_LENGTH + 1] = {0};

		//to check if  new val was received
		bool return_new_val(){
			return new_val;
		};

		//returns pointer of char array with msg
		char * read_msg(){
			new_val = false;
			return msg;
		};

		void new_val_rx(){
			new_val = true;
		};


};



//altitude command values
#define ALTITUDE_40CM 4
#define ALTITUDE_50CM 5
#define ALTITUDE_60CM 6
#define ALTITUDE_70CM 7
#define ALTITUDE_80CM 8

//altitude values
#define LANDING_ALTITUDE 0.3
#define LANDING_TOL = 0.05


#endif