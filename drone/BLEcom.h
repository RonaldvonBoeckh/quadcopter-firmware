#ifndef BLECOM_HEADER
#define BLECOM_HEADER

#include <dronetypedef.h>

#include <bluefruit.h>

void rx_callback();

void connect_callback(uint16_t conn_handle);

void disconnect_callback(uint16_t conn_handle, uint8_t reason);


class BLEcom{

	public:
		void ble_uart_init();

		void send_state(attitude_t attitude, float altitude, float dt);

		void send_cmd(int cmd_code);

		void send_debug(String debug_msg);

		int get_cmd();

		float get_altitude();

		bool is_connected();
		
		BLEcom();

		~BLEcom();


	private:

		void start_adv();



};

#endif