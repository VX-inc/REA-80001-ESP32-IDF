#include "Arduino.h"
#include "Support.h"
#include "Adafruit_NeoPixel.h"
#include "defs.h"
#include "Power_Supply.h"


void slottedLoop() {
  static uint32_t slot_100ms = 0;
  static uint32_t slot_10ms = 0;

  if (millis() >= slot_100ms) {
    Slot_100ms();
    while (millis() >= slot_100ms) {
      slot_100ms += 100;
    }
  }

  if (millis() >= slot_10ms) {
    Slot_10ms();
    while (millis() >= slot_10ms) {
      slot_10ms += 10;
    }
  }

  Slot_EveryLoop();
}

Adafruit_NeoPixel status_led(1, LED_STATUS_PIN, NEO_GRB + NEO_KHZ800);

void initializeStatusLED() {
  status_led.begin();
  status_led.clear();
  status_led.setPixelColor(0, status_led.Color(10, 10, 10));
  status_led.show();
}

void refreshStatusLED() {
  updateStatusLED(getPSUState());
}

void updateStatusLED(PSUState commandedSupplyState) {
  if (commandedSupplyState == PSU_POWER_OFF) {
    status_led.setPixelColor(LED_STATUS_ADDRESS, status_led.Color(10, 10, 10));
  }
  if (commandedSupplyState == PSU_20V) {
    status_led.setPixelColor(LED_STATUS_ADDRESS, status_led.Color(0, 0, 10));
  }
  if (commandedSupplyState == PSU_12V) {
    status_led.setPixelColor(LED_STATUS_ADDRESS, status_led.Color(0, 10, 10));
  }
  if (commandedSupplyState == PSU_5V) {
    status_led.setPixelColor(LED_STATUS_ADDRESS, status_led.Color(0, 10, 0));
  }
  status_led.show();
}