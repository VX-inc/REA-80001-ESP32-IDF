
#include "defs.h"

#define LED_STATUS_PIN 1
#define LED_STATUS_ADDRESS 0

void slottedLoop();
void initializeStatusLED();
void refreshStatusLED();
void updateStatusLED(PSUState commandedSupplyState);