//Developed by Matias Verardo
//ARGENTINA 2019

//Conexiones
/*
  ---DHT22-- 1
  VCC <-> VCC(5V)
  2. PIN 3
  3. LIBRE
  GND <-> GND

  ---DHT22-- 2
  VCC <-> VCC(5V)
  2. PIN 3
  3. LIBRE
  GND <-> GND

  --DS1307--
  GND <-> GND
  VCC <-> VCC(5V)
  SCL <-> A5
  SDA <-> A4

  ---DISPLAY I2C---
  Está marcado.
  GND <-> GND
  VCC <-> VCC(5V)
  SDA <-> A4
  SCL <-> A5

  --ENCODER--
  GND <-> GND
  VCC <-> VCC(5V)
  CLK <-> 14
  DT  <-> 15
  SW  <-> 16

  --RELES--

  LUZ VEGE   <-> 12
  LUZ FLORA  <-> 11
  EXT VEGE   <-> 10
  EXT FLORA  <-> 9
  ART1       <-> 8
  ART2       <-> 7
  VENT VEGE  <-> 6
  VENT FLORA <-> 5
*/

#include <LiquidCrystal_I2C.h>
//#include "Adafruit_LiquidCrystal.h"
#include <Wire.h>
#include "DHT.h"
#include "RTClib.h"

#define DHTPIN1 18           //DHT 1
#define DHTPIN2 19           //DHT 2
#define DHTTYPE DHT22
#define VENTILACION 34       //RELE
#define HUMIDIFICADOR 35     //RELE
#define EXTRACCIONFLORA 32   //RELE
#define EXTRACCIONVEGE 33    //RELE
#define LUZFLORACION 25      //RELE
#define LUZVEGETATIVO 26     //RELE
#define relelibre1 27        //RELE
#define relelibre2 14        //RELE

RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x27, 20, 4);
//Adafruit_LiquidCrystal lcd(0);

DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);

const float horaONveg = 15;
const float horaOFFveg = 9;

const float tempMAXveg = 26;
const float tempMINveg = 20;

const float humMAXveg = 75;
const float humMINveg = 50;


const float horaONflora = 21;
const float horaOFFflora = 9;

const float tempMAXflora = 24;
const float tempMINflora = 18;

const float humMAXflora = 50;
const float humMINflora = 30;

bool flagLuzVege = false;
bool flagLuzFlora = false;

int hora  = 0;
int fecha = 0;
float temp1 = 0;
float hum1  = 0;
float temp2 = 0;
float hum2  = 0;


bool bienvenidaState = false;


byte termometru[8] = //icon for termometer
{
  B00100,
  B01010,
  B01010,
  B01010,
  B01110,
  B11111,
  B11111,
  B01110
};

byte linea[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B10101,
  B00000,
  B00000,
  B00000
};

byte vertical[8] = {
  B00100,
  B00000,
  B00100,
  B00000,
  B00100,
  B00000,
  B00100,
  B00000
};

byte curvita[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B10101,
  B00000,
  B00100,
  B00000
};

byte verticalArriba[8] = {
  B00100,
  B00000,
  B00100,
  B00000,
  B10101,
  B00000,
  B00000,
  B00000
};

byte flechaIzq[] = {
  B00000,
  B00000,
  B00100,
  B01000,
  B11111,
  B01000,
  B00100,
  B00000
};

byte flechaDer[] = {
  B00000,
  B00000,
  B00100,
  B00010,
  B11111,
  B00010,
  B00100,
  B00000
};

void setup () {
  Serial.begin(57600);
  Serial.println(F("DHTxx test!"));
#ifdef AVR
  Wire.begin();
#else
  Wire1.begin(); // Shield I2C pins connect to alt I2C bus on Arduino Due
#endif
  rtc.begin();

 /* if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }*/

  rtc.adjust(DateTime(__DATE__, __TIME__));

  pinMode(LUZVEGETATIVO, OUTPUT);
  pinMode(LUZFLORACION, OUTPUT);
  pinMode(EXTRACCIONVEGE, OUTPUT);
  pinMode(EXTRACCIONFLORA, OUTPUT);
  pinMode(HUMIDIFICADOR, OUTPUT);
  pinMode(VENTILACION, OUTPUT);
  digitalWrite(LUZVEGETATIVO, HIGH);
  digitalWrite(LUZFLORACION, HIGH);
  digitalWrite(EXTRACCIONVEGE, HIGH);
  digitalWrite(EXTRACCIONFLORA, HIGH);
  digitalWrite(HUMIDIFICADOR, HIGH);
  digitalWrite(VENTILACION, LOW);

  lcd.begin(20, 4);
  lcd.init();
  lcd.backlight();
  dht1.begin();
  dht2.begin();

  lcd.createChar(1, termometru);
  lcd.createChar(2, linea);
  lcd.createChar(3, vertical);
  lcd.createChar(4, curvita);
  lcd.createChar(5, verticalArriba);
  lcd.createChar(6, flechaIzq);
  lcd.createChar(7, flechaDer);
}

void loop () {

  if (bienvenidaState == false) {
    bienvenida();
  }

  float temp1 = getDHT1Temp();
  float hum1  = getDHT1Hum();
  float temp2 = getDHT2Temp();
  float hum2  = getDHT2Hum();
  mostrarTodo(temp1, temp2, hum1, hum2);
  delay(10000);

  luces();
  decisiones(temp1, temp2, hum1, hum2);
}
