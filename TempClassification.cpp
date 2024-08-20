#include "TempClassification.h"

typedef struct {
    double lowerLimit;
    double upperLimit;
} CoolingLimits;

CoolingLimits getCoolingLimits(CoolingType coolingType) {
    static const CoolingLimits limits[] = {
        {0, 35},  // PASSIVE_COOLING
        {0, 45},  // HI_ACTIVE_COOLING
        {0, 40}   // MED_ACTIVE_COOLING
    };
    return limits[coolingType];
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
    CoolingLimits limits = getCoolingLimits(coolingType);
    return inferBreach(temperatureInC, limits.lowerLimit, limits.upperLimit);
}
