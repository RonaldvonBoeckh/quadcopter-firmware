#include <BLEcom.h>
#include <Arduino.h>

//for input normal commands
cmd_t cmd;
//to track new altitude set point
cmd_t altitude_set;

BLEDfu  bledfu;  // OTA DFU service
BLEDis  bledis;  // device information
BLEUart bleuart; // uart over ble
BLEBas  blebas;  // battery

bool connected;

//constructor
BLEcom::BLEcom(){
	//set cmd structs to 0 and false
	cmd.new_val = false;
	cmd.cmd_val = 0;
	altitude_set.new_val = false;
	altitude_set.cmd_val = 0;
	//ensure connected flag is false
	connected = false;
}

//destructor
BLEcom::~BLEcom(){
	//nothing to do
}

/**
 * @brief start advertising of bleuart service
 * 
 */
void BLEcom::start_adv(){
	// Advertising packet
	Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
	Bluefruit.Advertising.addTxPower();

	// Include bleuart 128-bit uuid
	Bluefruit.Advertising.addService(bleuart);

	// Secondary Scan Response packet (optional)
	// Since there is no room for 'Name' in Advertising packet
	Bluefruit.ScanResponse.addName();

	/* Start Advertising
	* - Enable auto advertising if disconnected
	* - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
	* - Timeout for fast mode is 30 seconds
	* - Start(timeout) with timeout = 0 will advertise forever (until connected)
	* 
	* For recommended advertising interval
	* https://developer.apple.com/library/content/qa/qa1931/_index.html   
	*/
	Bluefruit.Advertising.restartOnDisconnect(true);
	Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
	Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
	Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds  
}

/**
 * @brief callback function when data is received over bleuart
 * Pareses message and places info into the cmd or altitude_set cmd_t structs
 * 
 */
void rx_callback(){
	//get data from buffer
	char str[20+1] = { 0 };
	bleuart.read(str, 20);

	char in_val = str[1];
	//parse to extract commands
	//---------------------------------------
	switch(str[0]){
		case 'a':	//new altitude setpoint
			altitude_set.new_val = true;
			altitude_set.cmd_val = str[1] - '0';
			switch(altitude_set.cmd_val){
				case ALTITUDE_40CM:
					altitude_set.cmd_val = 40;
					break;
				case ALTITUDE_50CM:
					altitude_set.cmd_val = 50;
					break;
				case ALTITUDE_60CM:
					altitude_set.cmd_val = 60;
					break;
				case ALTITUDE_70CM:
					altitude_set.cmd_val = 70;
					break;
				case ALTITUDE_80CM:
					altitude_set.cmd_val = 80;
					break;
				default:
					altitude_set.cmd_val = -1;
					altitude_set.new_val = false;	//if it got here, no allowed val was passed
			}
			break;
		
		case 'c':	//standard command
			cmd.cmd_val = str[1] - '0';
			if(cmd.cmd_val >= 1 && cmd.cmd_val <= INPUT_COMMAND_CODE_MAX){
				cmd.new_val = true;
			}
			else{
				cmd.cmd_val = -1;
				cmd.new_val = false;
			}
			break;

	}
}

/**
 * @brief callback function for when the ble connection is established
 * 
 */
void connect_callback(uint16_t conn_handle){
	connected = true;	//set connect flag to true
}

/**
 * @brief callback function for when the ble connection is lost
 * 
 */
void disconnect_callback(uint16_t conn_handle, uint8_t reason){
	connected = false;
}
/**
 * @brief initialize the ble uart service using bluefruit library
 * 
 */
void BLEcom::ble_uart_init(){
	Bluefruit.autoConnLed(true);    //by default, but made explicit
	// Config the peripheral connection with maximum bandwidth 
	// more SRAM required by SoftDevice
	// Note: All config***() function must be called before begin()
	Bluefruit.configPrphBandwidth(BANDWIDTH_MAX);

	//init ble
	Bluefruit.begin(1,0);   //peripheral=1, central=0
	Bluefruit.setTxPower(4);    // Check bluefruit.h for supported values
	Bluefruit.setName("Drone");
	//Bluefruit.setName(getMcuUniqueID()); // useful testing with multiple central connections
	Bluefruit.Periph.setConnectCallback(connect_callback);
	Bluefruit.Periph.setDisconnectCallback(disconnect_callback);

	// To be consistent OTA DFU should be added first if it exists
	bledfu.begin();

	// Configure and Start Device Information Service
	bledis.setManufacturer("Adafruit Industries");
	bledis.setModel("Bluefruit Feather52");
	bledis.begin();

	// Configure and Start BLE Uart Service
	bleuart.begin();
	//bleuart.bufferTXD(0);     //disable buffer, send data right away
	bleuart.setRxCallback(BLEUart::rx_callback_t(rx_callback));

	// Start BLE Battery Service
	blebas.begin();
	blebas.write(100);

	// Set up and start advertising
	BLEcom::start_adv();   //function which sets advertising params

	Serial.println("Initialized ble service class");
}

/**
 * @brief sends attitude and altitude data via bleuart
 * 
 * @param attitude struct containing current roll,pitch,yaw estimates
 * @param alitude float containing current altitude estimate
 * 
 * outputs in form "s roll pitch yaw altitude". d is so receiving end knows its state information
 */
void BLEcom::send_state(attitude_t attitude, float altitude, float dt){
	String roll_s = String(attitude.roll);
	String pitch_s = String(attitude.pitch);
	String yaw_s = String(attitude.yaw);
	String altitude_s = String(altitude);
	String dt_s = String(dt);

	String msg = String("s " + roll_s + " " + pitch_s + " " + yaw_s + " " + altitude_s + " " + dt_s);

	bleuart.print(msg);
}

/**
 * @brief send a message based on the msg code defined in <drone.h>
 * 
 * @param cmd_code code of cmd to send via bleuart, defined in <drone.h>
 */
void BLEcom::send_cmd(int cmd_code){

	if(connected){
		switch(cmd_code){
			case CALIBRATE_DONE:
				bleuart.print(CALIBRATE_DONE_CMD);
				break;
			
			case LANDED:
				bleuart.print(LANDED_CMD);
				break;
		}
	}
}

/**
 * @brief send a debug msg to the app instead of using HW serial
 * 
 * @param debug_msg arduino string class, message to be send via bleuart. keep under 20 digits
 */
void BLEcom::send_debug(String debug_msg){
	String outString = String("d: " + debug_msg);
	bleuart.print(outString);
}

/**
 * @brief gets the command struct
 * 
 * @return int returns command numbr, and -1 if not new command was found
 */
int BLEcom::get_cmd(){
	int return_val = 0;

	if(cmd.new_val == true){
		cmd.new_val = false;		//no longer new val
		return_val = cmd.cmd_val;
		cmd.cmd_val = 0;			//set to 0 so it isnt read 2x
		return return_val;
	}
	else{
		return -1;			//not new val, returns -1
	}
}

/**
 * @brief gets altitude value
 * 
 * @return int altitude set in cm, range 40-80. returns -1 if no new value is found
 */
float BLEcom::get_altitude(){
	float return_val = 0;

	if(altitude_set.new_val == true){
		altitude_set.new_val = false;
		return_val = altitude_set.cmd_val * 0.01;		//return val from cm->m
		altitude_set.cmd_val = -1;
		return return_val;
	}
	else{
		return -1;
	}
}

bool BLEcom::is_connected(){
	return connected;
}