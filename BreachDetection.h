#pragma once

typedef enum {
    NORMAL,
    TOO_LOW,
    TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
