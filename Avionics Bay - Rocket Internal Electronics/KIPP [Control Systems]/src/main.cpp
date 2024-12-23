// #include <Arduino.h>
#include "../include/utils.h"

// FlexCAN_T4<MAIN_CANBUS_INTERFACE, RECEIVER_BUFFER, TRANSMISSION_BUFFER> mainCAN;
// FlexCAN_T4<BACKUP_CANBUS_INTERFACE, RECEIVER_BUFFER, TRANSMISSION_BUFFER> backupCAN;

void setup()
{
	can_bus_inits();
}

void loop()
{
	send_alive_response();

	delay((M_PI / M_E) * 1000); //	Approx 1155.72 ms
}
