#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "DHT.h"
#include "RTClib.h"

#define DHTPIN1 2
#define DHTPIN2 3
#define DHTTYPE DHT22

DS1307 rtc;
LiquidCrystal_I2C lcd(0x27, 20, 4);

DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);




int hora  = 0;
int fecha = 0;
float temp1 = 0;
float hum1  = 0;
float temp2 = 0;
float hum2  = 0;

void setup () {
  Serial.begin(57600);
  Serial.println(F("DHTxx test!"));
#ifdef AVR
  Wire.begin();
#else
  Wire1.begin(); // Shield I2C pins connect to alt I2C bus on Arduino Due
#endif
  rtc.begin();

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }
  lcd.init();
lcd.backlight();
lcd.clear();
dht1.begin();
dht2.begin();
}

void loop () {

  //String fecha  = getFecha();
  //String hora   = getHora(); 
  float temp1 = getDHT1Temp();
  float hum1  = getDHT1Hum();
  float temp2 = getDHT2Temp();
  float hum2  = getDHT2Hum();
  mostrarTodo(temp1, temp2, hum1, hum2);
    delay(10000);

  


}
