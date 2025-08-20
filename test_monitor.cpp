#include "./monitor.h"
#include "./thresholds.h"
#include <iostream>
#include <cassert>
using namespace std;

void testTemperature() {
    cout << "\n[Temperature Tests]\n";
    assert(!vitalsOk(94.0, 80, 95));   
    assert(vitalsOk(95.0, 80, 95));    
    isTemperatureWarning(95.5);      
    assert(vitalsOk(97.0, 80, 95));  
    isTemperatureWarning(101.0);     
    assert(vitalsOk(102.0, 80, 95));  
    assert(!vitalsOk(103.0, 80, 95));  
}

void testPulse() {
    cout << "\n[Pulse Tests]\n";
    assert(!vitalsOk(98, 59.0, 95));   
    assert(vitalsOk(98, 60.0, 95)); 
    isPulseWarning(61.0);             
    assert(vitalsOk(98, 80.0, 95));  
    isPulseWarning(99.0);             
    assert(vitalsOk(98, 100.0, 95));  
    assert(!vitalsOk(98, 101.0, 95));  
}

void testSpO2() {
    cout << "\n[SpO2 Tests]\n";
    assert(!vitalsOk(98, 80, 89.0));   
    assert(vitalsOk(98, 80, 90.0)); 
    isSpO2Warning(91.0);             
    assert(vitalsOk(98, 80, 95.0)); 
}

int main() {
    testTemperature();
    testPulse();
    testSpO2();
    cout << "\n All functional tests passed!\n";
    return 0;
}
