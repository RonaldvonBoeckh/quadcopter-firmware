/*
Header file to define codes for BLE commands between the drone and controller
Messages are defined for drone->controller and controller->drone.
The message coeds are a 1 byte hex value which is the first byte of the data payload
of the BLE packet

See documentation for full explanation on structure of messages
*/

#ifndef DRONECODES
#define DRONECODES

//Controller->Drone Codes
#define GEN_APP_ERROR 0x00
#define CALIBRATE     0x01
#define FLY           0x02
#define MOTION        0x03
#define LAND          0x04

//Drone->Controller codes
#define GEN_DRONE_ERROR 0x00
#define CALIBRATED      0x01
#define LANDED          0x02
#define LOGGING         0x03

#endif 