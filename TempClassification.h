#pragma once

#include "BreachDetection.h"

typedef enum {
    PASSIVE_COOLING,
    HI_ACTIVE_COOLING,
    MED_ACTIVE_COOLING
} CoolingType;

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
