#include <ESP32-TWAI-CAN.hpp>

#define CAN_TX 5
#define CAN_RX 4

#define CAN_STUFFING_FRAME 0xAA
#define CAN_IDENTIFIER 0x0A

void initCAN();
void checkCANMessages();
void receivedCurrentValue(uint8_t highByte, uint8_t lowByte);