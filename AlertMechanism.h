#pragma once

#include "BreachDetection.h"

typedef enum {
    TO_CONTROLLER,
    TO_EMAIL
} AlertTarget;

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
