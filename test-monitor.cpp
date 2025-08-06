#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, AllVitalsNormal) {
    ASSERT_TRUE(vitalsOk(98.6, 75, 95));
}

TEST(Monitor, TemperatureHigh) {
    ASSERT_FALSE(vitalsOk(103, 75, 95));
}

TEST(Monitor, TemperatureLow) {
    ASSERT_FALSE(vitalsOk(94, 75, 95));
}

TEST(Monitor, PulseLow) {
    ASSERT_FALSE(vitalsOk(98.6, 55, 95));
}

TEST(Monitor, PulseHigh) {
    ASSERT_FALSE(vitalsOk(98.6, 110, 95));
}

TEST(Monitor, SpO2Low) {
    ASSERT_FALSE(vitalsOk(98.6, 75, 85));
}
