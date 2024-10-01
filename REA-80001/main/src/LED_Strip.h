
#include "defs.h"

enum AutoDetectStateType {
  AD_IDLE = 0,
  AD_START = 1,
  AD_ENABLE_POWER = 2,
  AD_TESTSHORT = 3,
  AD_ZERO_CURRENT = 4,
  AD_COMMAND_STRIP = 5,
  AD_MEASURE_CURRENT = 6,
  AD_COMPLETE = 7,
  AD_FAIL = 8
};

void receivedPSUStatus(PSUState state, PSUStatus status);
void receivedCurrentMeasurement(float current);
void clearLEDStrip();
void startAutoDetect();
void LEDStripHandler();
void LEDStrip10msHandler();
void LEDStrip100msHandler();
void initializeLEDStrip();
void toggleTestPattern();
bool currentRequestReturned();
float getCurrentValue();
void AutoVoltageDetect();
void sendCurrentMeasureCommand();
void sendZeroCurrentCommand();
void testLEDStripCurrent();
void runTestPattern();
void updatePattern(int pat);
void rainbow();
void rainbowCycle();
void theaterChaseRainbow();
void colorWipe(uint32_t c);
void wipe();
uint32_t Wheel(byte WheelPos);