#include <BLEcom.h>
#include <Arduino.h>

//for input normal commands
extern cmd_t cmd;			//defined as global var in drone.cpp. Global beause it must be accesed by both drone class and this file

BLEDfu  bledfu;  // OTA DFU service
BLEDis  bledis;  // device information
BLEUart bleuart; // uart over ble
BLEBas  blebas;  // battery

bool connected;

//constructor
BLEcom::BLEcom(){
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
 * Placed message into a cmd_t struct
 * 
 */
void rx_callback(){
	//get data from buffer
	bleuart.read(cmd.msg, BLE_PACKET_LENGTH);
	//set new command to true
	cmd.new_val_rx();
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
	Bluefruit.setName("Quadcopter");
	//Bluefruit.setName(getMcuUniqueID()); // useful testing with multiple central connections
	Bluefruit.Periph.setConnectCallback(connect_callback);
	Bluefruit.Periph.setDisconnectCallback(disconnect_callback);

	// To be consistent OTA DFU should be added first if it exists
	bledfu.begin();

	// Configure and Start Device Information Service
	bledis.setManufacturer("Adafruit Industries");
	bledis.setModel("Bluefruit FeatherSense52");
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
}

/**
 * @brief send a message in string format
 * 
 * @param msg string msg, max 20 bytes long to be sent over bleuart
 */
void BLEcom::send_msg(String msg){
	bleuart.print(msg);
}


bool BLEcom::is_connected(){
	return connected;
}