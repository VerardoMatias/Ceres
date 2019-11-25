#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN1 2
#define DHTPIN2 3
#define DHTTYPE DHT22

LiquidCrystal_I2C lcd(0x27, 20, 4);

DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  
  lcd.init();
  lcd.backlight();
  lcd.clear();
  dht1.begin();
  dht2.begin();
}

void loop() {

    float h1 = dht1.readHumidity();
    float t1 = dht1.readTemperature();
    float f1 = dht1.readTemperature(true);

    if (isnan(h1) || isnan(t1) || isnan(f1)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
    }

    float hif1 = dht1.computeHeatIndex(f1, h1);
    float hic1 = dht1.computeHeatIndex(t1, h1, false);

    Serial.print(F("Humidity: "));
    Serial.print(h1);
    Serial.print(F("%  Temperature: "));
    Serial.print(t1);
    Serial.print(F("°C "));
    Serial.print(f1);
    Serial.print(F("°F  Heat index: "));
    Serial.print(hic1);
    Serial.print(F("°C "));
    Serial.print(hif1);
    Serial.println(F("°F"));

    //lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(h1);

    lcd.setCursor(0,2);
    lcd.print(t1);



    float h2 = dht2.readHumidity();
    float t2 = dht2.readTemperature();
    float f2 = dht2.readTemperature(true);

    if (isnan(h2) || isnan(t2) || isnan(f2)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
    }

    float hif2 = dht2.computeHeatIndex(f2, h2);
    float hic2 = dht2.computeHeatIndex(t2, h2, false);

    Serial.print(F("Humidity: "));
    Serial.print(h2);
    Serial.print(F("%  Temperature: "));
    Serial.print(t2);
    Serial.print(F("°C "));
    Serial.print(f2);
    Serial.print(F("°F  Heat index: "));
    Serial.print(hic2);
    Serial.print(F("°C "));
    Serial.print(hif2);
    Serial.println(F("°F"));

    //lcd.clear();
    lcd.setCursor(15,1);
    lcd.print(h2);

    lcd.setCursor(15,2);
    lcd.print(t2);

    delay(5000);

    //lcd.setBacklight(LOW);

  
}
