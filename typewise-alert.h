#pragma once

#include "TempClassification.h"
#include "AlertMechanism.h"

typedef struct {
    CoolingType coolingType;
    char brand[48];
} BatteryCharacter;

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
