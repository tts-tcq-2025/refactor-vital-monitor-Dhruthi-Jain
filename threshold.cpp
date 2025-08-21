#include "./thresholds.h"
#include "./alerts.h"

namespace {
    constexpr float TEMP_MIN = 95.0f;
    constexpr float TEMP_MAX = 102.0f;
    constexpr float PULSE_MIN = 60.0f;
    constexpr float PULSE_MAX = 100.0f;
    constexpr float SPO2_MIN = 90.0f;
    constexpr float WARNING_TOLERANCE_FACTOR = 0.015f;

bool checkWarning(float value, float min, float max, const char* lowMsg, const char* highMsg) {
        float tolerance = max * WARNING_TOLERANCE_FACTOR;
        if (value <= min + tolerance) {
            showWarning(lowMsg);
            return true;
        }
        if (value >= max - tolerance) {
            showWarning(highMsg);
            return true;
        }
        return false;
    }
}

bool isTemperatureOk(float temperature) {
    return (temperature >= TEMP_MIN && temperature <= TEMP_MAX);
}

bool isPulseOk(float pulseRate) {
    return (pulseRate >= PULSE_MIN && pulseRate <= PULSE_MAX);
}

bool isSpO2Ok(float spo2) {
    return (spo2 >= SPO2_MIN);
}

bool isTemperatureWarning(float temperature) {
     return checkWarning(temperature, TEMP_MIN, TEMP_MAX, "Approaching hypothermia", "Approaching hyperthermia");
}

bool isPulseWarning(float pulseRate) {
    return checkWarning(pulseRate, PULSE_MIN, PULSE_MAX, "Pulse rate nearing bradycardia", "Pulse rate nearing tachycardia");
}

bool isSpO2Warning(float spo2) {
    float tolerance = SPO2_MIN * WARNING_TOLERANCE_FACTOR;
    if (spo2 <= SPO2_MIN + tolerance) {
        showWarning("Oxygen saturation nearing hypoxemia");
        return true;
    }
    return false;
}
