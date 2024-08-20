#include <gtest/gtest.h>
#include "TypewiseAlert.h"

TEST(TypeWiseAlertTestSuite, InfersBreachAccordingToLimits) {
    EXPECT_EQ(inferBreach(12, 20, 30), TOO_LOW);
    EXPECT_EQ(inferBreach(22, 20, 30), NORMAL);
    EXPECT_EQ(inferBreach(32, 20, 30), TOO_HIGH);
}

TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureBreach) {
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 20), NORMAL);
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 36), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, 0), NORMAL);
}

TEST(TypeWiseAlertTestSuite, CheckAndAlertToController) {
    BatteryCharacter batteryChar = {HI_ACTIVE_COOLING, "BrandX"};
    testing::internal::CaptureStdout();
    checkAndAlert(TO_CONTROLLER, batteryChar, 46);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("feed : 2"), std::string::npos); // TOO_HIGH
}

TEST(TypeWiseAlertTestSuite, CheckAndAlertToEmail) {
    BatteryCharacter batteryChar = {MED_ACTIVE_COOLING, "BrandY"};
    testing::internal::CaptureStdout();
    checkAndAlert(TO_EMAIL, batteryChar, -1);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("To: a.b@c.com"), std::string::npos);
    EXPECT_NE(output.find("Hi, the temperature is too low"), std::string::npos);
}
