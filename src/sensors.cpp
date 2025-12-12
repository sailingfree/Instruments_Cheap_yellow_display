#include <sensors.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// GPIO where the DS18B20 is connected to
const int oneWireBus = 22;     

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void sensorsSetup() {
  // Start the DS18B20 sensor
  sensors.begin();
}

float temperatureC;
float temperatureF;

void sensorsWork() {
    static time_t last = 0;
    time_t now = millis();

    if(now - last > TEMPERATURE_PERIOD) {
        last = now;
        sensors.requestTemperatures(); 
        temperatureC = sensors.getTempCByIndex(0);
        temperatureF = sensors.getTempFByIndex(0);
    }
}

float getTempC() {
  return temperatureC;
}

float getTempF() {
  return temperatureF;
}