#include <sensors.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// GPIO where the DS18B20 is connected to
const int oneWireBus = 22;     

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

static float temperatureC;
static float temperatureF;

// Task to read the sensors
// Discard if the device reports disconnected
void readSensors(void *parameter) {
    static time_t last = 0;
    while (1) {
        time_t now = millis();

        if (now - last > TEMPERATURE_PERIOD) {
            last = now;
            float temp;
            sensors.requestTemperatures();
            temp = sensors.getTempCByIndex(0);
            if(temp != DEVICE_DISCONNECTED_C) {
              temperatureC = temp;
              temperatureF = sensors.toFahrenheit(temperatureC);
            }
          }
        // delay for 1000msecs
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void sensorsSetup() {
  // Start the DS18B20 sensor
  sensors.begin();

  // Create a task to read the sensor in the background so we don't delay the main task
  Serial.printf("Going to start sensors task\n");
  xTaskCreate(readSensors, "readSensors", 8000, NULL, 1, NULL);
}


void sensorsWork() {

}

float getTempC() {
  return temperatureC;
}

float getTempF() {
  return temperatureF;
}