#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>

// Create the TSL2561 object
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

void setup() {
  Serial.begin(9600);
  if (!tsl.begin()) {
    Serial.println("No TSL2561 sensor found");
    while (1);
  }
  // Configure the sensor
  tsl.enableAutoRange(true);
  tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);  // shortest integration time (bright light)
  Serial.println("TSL2561 sensor initialized");
}

void loop() {
  sensors_event_t event;
  tsl.getEvent(&event);
  if (event.light) {
    Serial.print("Light: ");
    Serial.print(event.light);
    Serial.println(" lux");

    // Map the light intensity to an analog value (0-255 for 8-bit PWM)
    int analogValue = map(event.light, 0, 40000, 0, 255);  // Adjusted range for 0.1 to 40,000 lux
    analogWrite(9, analogValue);  // Output the analog value (PWM on pin 9)
  }
  delay(1000);
}
