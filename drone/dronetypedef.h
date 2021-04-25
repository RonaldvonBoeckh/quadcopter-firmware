#ifndef DRONE_TYPES_HEADER
#define DRONE_TYPES_HEADER

#include <control.h>

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

//struct to keep track of input commands
typedef struct {
	bool new_val = false;
	int cmd_val = 0;
} cmd_t;

//input command codes via bleuart
#define CALIBRATE 1
#define STREAM 2
#define STREAM_STOP 3
#define START_FLYING 4
#define STOP_FLYING 5
#define INPUT_COMMAND_CODE_MAX 5

//output command codes via bleuart
#define CALIBRATE_DONE 1
#define CALIBRATE_DONE_CMD "c1"
#define LANDED 2
#define LANDED_CMD "c2"

//altitude command values
#define ALTITUDE_40CM 4
#define ALTITUDE_50CM 5
#define ALTITUDE_60CM 6
#define ALTITUDE_70CM 7
#define ALTITUDE_80CM 8

#endif