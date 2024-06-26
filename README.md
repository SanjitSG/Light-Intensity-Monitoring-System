# Light-Intensity-Monitoring-System

## Description
A project to measure and display light intensity using a TSL2561 luminosity sensor, Arduino Nano, and Mistura PI-4000 process indicator. This system reads light levels, processes the data, and outputs a corresponding analog signal to a display for real-time monitoring.

## Components
1. GY-2561 TSL2561 Luminosity Sensor
2. Arduino Nano
3. Mistura PI-4000 Display
4. 1kΩ Resistor
5. 10µF Capacitor
6. Connecting wires
7. Breadboard (optional for prototyping)

## Wiring Diagram

### TSL2561 to Arduino Nano
- **VCC** (sensor) to 3.3V/5V (Nano)
- **GND** (sensor) to GND (Nano)
- **SCL** (sensor) to A5 (Nano)
- **SDA** (sensor) to A4 (Nano)

### Low-Pass Filter for PWM to Analog Conversion
- **Pin 9 (PWM Output)** on the Arduino Nano:
  - Connect to one end of the 1kΩ resistor.
  - The other end of the 1kΩ resistor connects to both the positive lead of the 10µF capacitor and the analog input of the PI-4000.
- **Negative lead of the 10µF capacitor**:
  - Connect to the GND of the Arduino Nano.
- **GND of the Arduino Nano**:
  - Also connect to the GND of the PI-4000 to ensure a common ground.

### Schematic
# Light-Intensity-Monitoring-System

## Description
A project to measure and display light intensity using a TSL2561 luminosity sensor, Arduino Nano, and Mistura PI-4000 process indicator. This system reads light levels, processes the data, and outputs a corresponding analog signal to a display for real-time monitoring.

## Components
1. GY-2561 TSL2561 Luminosity Sensor
2. Arduino Nano
3. Mistura PI-4000 Display
4. 1kΩ Resistor
5. 10µF Capacitor
6. Connecting wires
7. Breadboard (optional for prototyping)

## Wiring Diagram

### TSL2561 to Arduino Nano
- **VCC** (sensor) to 3.3V/5V (Nano)
- **GND** (sensor) to GND (Nano)
- **SCL** (sensor) to A5 (Nano)
- **SDA** (sensor) to A4 (Nano)

### Low-Pass Filter for PWM to Analog Conversion
- **Pin 9 (PWM Output)** on the Arduino Nano:
  - Connect to one end of the 1kΩ resistor.
  - The other end of the 1kΩ resistor connects to both the positive lead of the 10µF capacitor and the analog input of the PI-4000.
- **Negative lead of the 10µF capacitor**:
  - Connect to the GND of the Arduino Nano.
- **GND of the Arduino Nano**:
  - Also connect to the GND of the PI-4000 to ensure a common ground.

### Schematic
```
Arduino Nano TSL2561 PI-4000
A5 --------------> SCL
A4 --------------> SDA
3.3V/5V ---------> VCC
GND -------------> GND

Low pass filter
D9 --[1kΩ]-->---+--> Analog Input (PI-4000)
|
=== 10µF
|
GND 
```
## Explanation

### TSL2561 Sensor to Arduino Nano:
- **VCC** (sensor) to 3.3V/5V on the Nano
- **GND** (sensor) to GND on the Nano
- **SCL** (sensor) to A5 on the Nano
- **SDA** (sensor) to A4 on the Nano

### Low-Pass Filter Setup:
1. Connect **Pin 9** on the Arduino Nano (PWM output) to one end of a **1kΩ resistor**.
2. Connect the other end of the 1kΩ resistor to:
   - The positive lead of a **10µF capacitor**
   - The analog input terminal of the **PI-4000**
3. Connect the negative lead of the **10µF capacitor** to the **GND** of the Arduino Nano.

### Common Ground:
- Connect the **GND** of the Arduino Nano to the **GND** of the PI-4000 to ensure a common ground reference.

### How It Works
- The TSL2561 sensor measures light intensity and communicates this data to the Arduino Nano via I2C.
- The Arduino Nano processes this data and outputs a corresponding PWM signal from pin 9.
- The low-pass filter (1kΩ resistor and 10µF capacitor) smooths the PWM signal into a steady DC voltage.
- The Mistura PI-4000 reads this DC voltage as an analog input and displays the corresponding light intensity.
