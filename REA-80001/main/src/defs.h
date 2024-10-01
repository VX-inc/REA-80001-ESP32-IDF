#ifndef DEFS_H 
#define DEFS_H 

enum PSUState {
  PSU_POWER_OFF = 1,
  PSU_20V = 2,
  PSU_12V = 3,
  PSU_5V = 4
};

enum PSUStatus {
  PSU_OK = 0,
  PSU_OVER_CURRENT = 1
};

enum CANDataType {
  CAN_PSU_VOLTAGE = 1,
  CAN_TEST_PATTERN = 2,
  CAN_CURRENT_REQUEST = 3,
  CAN_CURRENT_ZERO_REQUEST = 4,
  CAN_CURRENT_DATA = 5,
  CAN_PSU_STATUS = 6,
  CAN_PSU_TEST_VOLTAGE = 7
};

void Slot_100ms();
void Slot_10ms();
void Slot_EveryLoop();

#endif