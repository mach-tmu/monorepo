#include "../../include/main_definitions.h"
#include <FlexCAN_T4.h>

// Initialize CAN buses globally with its configuration

extern FlexCAN_T4<MAIN_CANBUS_INTERFACE, RECEIVER_BUFFER, TRANSMISSION_BUFFER> mainCAN;

extern FlexCAN_T4<BACKUP_CANBUS_INTERFACE, RECEIVER_BUFFER, TRANSMISSION_BUFFER> backupCAN;

void can_bus_inits();

void send_can_message_std(uint32_t identifier, const uint8_t *transmission_data, uint8_t length);

void send_can_message_bkp(uint32_t identifier, const uint8_t *transmission_data, uint8_t length);

void send_alive_response();

void send_error_stats(uint8_t error_codes);