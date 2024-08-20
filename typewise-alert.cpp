#include "TypewiseAlert.h"

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {
    BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

    // Define an array of function pointers for alert mechanisms
    void (*sendToTarget[])(BreachType breachType) = {sendToController, sendToEmail};

    // Call the appropriate alert function based on the target
    sendToTarget[alertTarget](breachType);
}
