#include "./thresholds.h"
#include "./alerts.h"

namespace {
    constexpr float TEMP_MIN = 95.0f;
    constexpr float TEMP_MAX = 102.0f;

    constexpr float PULSE_MIN = 60.0f;
    constexpr float PULSE_MAX = 100.0f;

    constexpr float SPO2_MIN = 90.0f;

    constexpr float WARNING_TOLERANCE_FACTOR = 0.015f; // 1.5%
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
    float tolerance = TEMP_MAX * WARNING_TOLERANCE_FACTOR;
    if (temperature <= TEMP_MIN + tolerance) {
        showWarning("Approaching hypothermia");
        return true;
    }
    if (temperature >= TEMP_MAX - tolerance) {
        showWarning("Approaching hyperthermia");
        return true;
    }
    return false;
}

bool isPulseWarning(float pulseRate) {
    float tolerance = PULSE_MAX * WARNING_TOLERANCE_FACTOR;
    if (pulseRate <= PULSE_MIN + tolerance) {
        showWarning("Pulse rate nearing bradycardia");
        return true;
    }
    if (pulseRate >= PULSE_MAX - tolerance) {
        showWarning("Pulse rate nearing tachycardia");
        return true;
    }
    return false;
}

bool isSpO2Warning(float spo2) {
    float tolerance = SPO2_MIN * WARNING_TOLERANCE_FACTOR;
    if (spo2 <= SPO2_MIN + tolerance) {
        showWarning("Oxygen saturation nearing hypoxemia");
        return true;
    }
    return false;
}
