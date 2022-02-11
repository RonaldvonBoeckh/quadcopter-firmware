# quadcopter-firmware
This is a first attempt at a full quadcopter control system implementation in C/C++. 

## Control System Design
The control system and state estimation were implemented in MATLAB/Simulink, and the system was validated using derived equations of motion.

## Hardware
A pre-purchased quadcopter chassis was used, and the control system is run on an arduino nano ble sense. The board has on-board sensors including IMU (3-axis accelerometer, 3-axis gyroscope), magnetometer, and barometer. Communication with a host PC uses BLE to transfer commands and debugging data.

## Next Steps
I am currently working on version 2, which will implement :
- More sophisticated state estimation using a full-state estimator
- Integration of GPS module to enable consistent position estimation
