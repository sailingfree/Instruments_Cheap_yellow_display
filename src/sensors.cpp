#include <sensors.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <bme280.h>


// GPIO where the DS18B20 is connected to
//const int oneWireBus = 22;     

// Setup a oneWire instance to communicate with any OneWire devices
//OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
//DallasTemperature sensors(&oneWire);

static float temperatureC;
static float temperatureF;
static float pressurePA;
static float humidityRH;

/* BME-280 */
bfs::Bme280 bme;

// Task to read the sensors
// Discard if the device reports disconnected
void readSensors(void *parameter) {
    static time_t last = 0;
    while (1) {
        time_t now = millis();

        if (now - last > TEMPERATURE_PERIOD) {
            last = now;
  //          float temp;
  //          sensors.requestTemperatures();
  //          temp = sensors.getTempCByIndex(0);
  //          if(temp != DEVICE_DISCONNECTED_C) {
  //            temperatureC = temp;
  //            temperatureF = sensors.toFahrenheit(temperatureC);
  //          }
          }
        if (bme.Read()) {
          temperatureC = bme.die_temp_c();
          temperatureF = (bme.die_temp_c() * 1.8f) + 32.0f;
          pressurePA = bme.pres_pa();
          humidityRH = bme.humidity_rh();
          Serial.print(bme.pres_pa());
          Serial.print("\t");
          Serial.print(bme.die_temp_c());
          Serial.print("\t");
          Serial.println(bme.humidity_rh());
        }
        // delay for 1000msecs
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void sensorsSetup() {
  // Start the DS18B20 sensor
//  sensors.begin();

  Wire.begin(27, 22, 400000);
  //Wire.setClock(400000);
  /* Wire at the primary I2C address */
  bme.Config(&Wire, bfs::Bme280::I2C_ADDR_PRIM);
  /* Initialize the BME-280 */
  if (!bme.Begin()) {
    Serial.println("Error initializing communication with BME-280");
  }

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

float getHumidity() {
  return humidityRH;
}

float getPressure() {
  return pressurePA / 100;
}