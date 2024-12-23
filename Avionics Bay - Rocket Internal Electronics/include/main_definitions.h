//  All general purpose boards pin-out definitions

#ifndef MAIN_DEFINITIONS_H
#define MAIN_DEFINITIONS_H

//  TARS General Definitions

#define TARS_CAN_TX_PIN 29

#define TARS_CAN_RX_PIN 30

//  KIPP Definitions

#define KIPP_CAN_TX_PIN 29

#define KIPP_CAN_RX_PIN 30

#define MAIN_CANBUS_INTERFACE CAN1

#define BACKUP_CANBUS_INTERFACE CAN2

#define TRANSMISSION_BUFFER TX_SIZE_16

#define RECEIVER_BUFFER RX_SIZE_256

#define CAN_BAUD_RATE 500000

#endif