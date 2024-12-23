#include "../../include/can_bus_kipp.hpp"

// Initialize CAN buses globally

FlexCAN_T4<MAIN_CANBUS_INTERFACE, RECEIVER_BUFFER, TRANSMISSION_BUFFER> mainCAN;

FlexCAN_T4<BACKUP_CANBUS_INTERFACE, RECEIVER_BUFFER, TRANSMISSION_BUFFER> backupCAN;

void can_bus_inits() // Initialize CAN buses configurations
{
    mainCAN.begin();
    backupCAN.begin();
    mainCAN.setBaudRate(CAN_BAUD_RATE);
    backupCAN.setBaudRate(CAN_BAUD_RATE);
}

void send_can_message_std(uint32_t identifier, const uint8_t *transmission_data, uint8_t length)
{
    CAN_message_t message_std;
    message_std.id = identifier;
    message_std.len = length;

    for (uint8_t i = 0; i < length; i++)
    {
        message_std.buf[i] = transmission_data[i];
    }

    if (!mainCAN.write(message_std))
    {
        Serial.println("Data Transmission Failed");
    }
    else
    {
        Serial.print("Data Transmitted successfully with ID : 0x");
        Serial.println(identifier, HEX);
    }
}

void send_can_message_bkp(uint32_t identifier, const uint8_t *transmission_data, uint8_t length)
{
    CAN_message_t message_std;
    message_std.id = identifier;
    message_std.len = length;

    for (uint8_t i = 0; i < length; i++)
    {
        message_std.buf[i] = transmission_data[i];
    }

    if (!backupCAN.write(message_std))
    {
        Serial.println("Data Transmission Failed");
    }
    else
    {
        Serial.print("Data Transmitted successfully with ID : 0x");
        Serial.println(identifier, HEX);
    }
}

void send_alive_response()
{
    uint8_t data[2] = {0x00, 0x00};
    send_can_message_std(0x000, data, 2);
    send_can_message_bkp(0x000, data, 2);
}

void send_error_stats(uint8_t error_codes)
{
    uint8_t data[1] = {error_codes};
    send_can_message_std(0xfff, data, 1);
    send_can_message_bkp(0xfff, data, 1);
}
