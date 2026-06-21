# DHT11 Temperature & Humidity Monitor

Reads temperature and humidity from a DHT11 sensor and displays the values on a 16x2 I2C LCD screen. Refreshes every 2 seconds.

---

## Components

| Component | Specification |
|---|---|
| Microcontroller | Arduino UNO |
| Sensor | DHT11 |
| Display | 16x2 LCD with I2C module (address `0x27`) |

---

## Wiring

### DHT11 → Arduino UNO

| DHT11 Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| DATA | Digital Pin 2 |

### I2C LCD → Arduino UNO

| LCD Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

---

## Libraries Required

Install these via **Arduino IDE → Tools → Manage Libraries**:

- `DHT sensor library` by Adafruit
- `LiquidCrystal_I2C` by Frank de Brabander

---

## How It Works

1. On startup, the LCD backlight turns on and the DHT11 is initialized.
2. Every 2 seconds, the sketch reads humidity and temperature from the sensor.
3. If the sensor read fails, the LCD shows `Failed to read`.
4. Otherwise, it displays:
   - **Row 0:** `Humidity: XX%`
   - **Row 1:** `Temp: XX.XXC`

---

## Uploading

1. Connect the Arduino to your PC via USB.
2. Open `dht11_lcd.ino` in the Arduino IDE.
3. Select **Board:** Arduino UNO and the correct **Port**.
4. Click **Upload**.

---

## Troubleshooting

| Issue | Fix |
|---|---|
| LCD shows nothing | Adjust the contrast potentiometer on the back of the I2C module |
| `Failed to read` on LCD | Check DHT11 wiring on pin 2; ensure VCC is 5V |
| Wrong I2C address | Run an I2C scanner sketch to find your module's address (common: `0x27` or `0x3F`) |
| Upload error (STK500) | Check the COM port selection and USB cable |