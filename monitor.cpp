#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

bool isTemperatureOk(float temperature) {
    return (temperature >= 95 && temperature <= 102);
}

bool isPulseOk(float pulseRate) {
    return (pulseRate >= 60 && pulseRate <= 100);
}

bool isSpO2Ok(float spo2) {
    return (spo2 >= 90);
}

void blinkWarning() {
    for (int i = 0; i < 6; ++i) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}

void showAlert(const char* message) {
    cout << message << '\n';
    blinkWarning();
}

bool vitalsOk(float temperature, float pulseRate, float spo2) {
    if (!isTemperatureOk(temperature)) {
        showAlert("Temperature is critical!");
        return false;
    }
    if (!isPulseOk(pulseRate)) {
        showAlert("Pulse Rate is out of range!");
        return false;
    }
    if (!isSpO2Ok(spo2)) {
        showAlert("Oxygen Saturation out of range!");
        return false;
    }
    return true;
}
