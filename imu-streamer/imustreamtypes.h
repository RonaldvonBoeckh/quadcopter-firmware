//file imustreamtypes.h
#ifndef IMUSTREAMTYPES_HEADER
#define IMUSTREAMTYPES_HEADER


//struct for attitude angles
typedef struct {
	float roll = 0;
	float pitch = 0;
	float yaw = 0;
} attitude_t;

//struct to keep track of input commands
typedef struct {
	bool new_val = false;
	int cmd_val = 0;
} cmd_t;

//input command codes via bleuart
#define CALIBRATE 1
#define START_COLLECT 2
#define STOP_COLLECT 3

//output command codes via bleuart
#define CALIBRATE_DONE 1
#define CALIBRATE_DONE_CMD "c1"
#define SENDING_DONE 2
#define SENDING_DONE_CMD "c2"

#endif