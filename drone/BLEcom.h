#ifndef BLECOM_HEADER
#define BLECOM_HEADER

#define BLE_PACKET_LENGTH 20

#include <dronetypedef.h>

#include <bluefruit.h>



void rx_callback();

void connect_callback(uint16_t conn_handle);

void disconnect_callback(uint16_t conn_handle, uint8_t reason);


class BLEcom{

	public:
		void ble_uart_init();

		void send_msg(String msg);

		bool is_connected();
		
		BLEcom();

		~BLEcom();


	private:

		void start_adv();



};

#endif