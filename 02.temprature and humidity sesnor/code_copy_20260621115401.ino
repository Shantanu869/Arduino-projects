#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define DHTPIN 2
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27, 16, 2);

DHT dht(DHTPIN,DHTTYPE);

void setup()
{
    Serial.begin(9600);
    dht.begin();
    lcd.begin();
   lcd.backlight();
}

void loop()
{
  float humidity= dht.readHumidity();
  float temp= dht.readTemperature();

  lcd.clear();
  lcd.setCursor(0,0);
  if(isnan(humidity)|| isnan(temp))
  {
    lcd.print("Failed to read");
    return;
  }

 lcd.setCursor(0, 1);
 lcd.print("temp:");
 lcd.print(temp);
 lcd.print("C");

 lcd.setCursor(0,0);
 lcd.print("Humidity:");
 lcd.print(humidity);
 lcd.print("%");

  delay(2000);
};