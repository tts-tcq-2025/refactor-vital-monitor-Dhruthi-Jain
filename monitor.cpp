#include "./monitor.h"
#include "./thresholds.h"
#include "./alerts.h"

bool vitalsOk(float temperature, float pulseRate, float spo2) 
{
    if (!isTemperatureOk(temperature)) {
        showAlert("Temperature is critical!");
        return false;
    }
    if (!isPulseOk(pulseRate)) 
    {
        showAlert("Pulse Rate is out of range!");
        return false;
    }
    if (!isSpO2Ok(spo2)) 
    {
        showAlert("Oxygen Saturation is out of range!");
        return false;
    }
    return true;
}
