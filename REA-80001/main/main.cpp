#include "Arduino.h"
#include "Adafruit_NeoPixel.h"
#include "defs.h"
#include "LED_Strip.h"
#include "CAN.h"
#include "Support.h"
#include "DMX.h"
#include "Serial_Parser.h"



void setup() {
  initializeStatusLED();
  initializeLEDStrip();
  initializeSerial();
  initializeDMX();
  initCAN();
}

void loop() {
  slottedLoop();
}

//Functions that run once every 100ms
void Slot_100ms() {
  refreshStatusLED();
  LEDStrip100msHandler();
}

//Functions that run once every 10ms
void Slot_10ms() {
  checkCANMessages();
  serialParser();
  LEDStrip10msHandler();
}

//Functions that run once every loop (the fastest possible)
void Slot_EveryLoop() {
  LEDStripHandler();
  updateDMX();
}
