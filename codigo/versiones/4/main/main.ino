#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "DHT.h"
#include "RTClib.h"

#define DHTTYPE DHT22
#define DHTPIN1 2
#define DHTPIN2 3
#define boton 4
#define salidaB 5
#define salidaA 6
#define VENTILACION 7
#define COMODIN2 8
#define COMODIN1 9
#define EXTRACCIONFLORA 10
#define EXTRACCIONVEGE 11
#define LUZFLORACION 12
#define LUZVEGETATIVO 13


DS1307 rtc;
LiquidCrystal_I2C lcd(0x27, 20, 4);

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

bool bienvenidaState = false;
bool hayEEPROM = false;

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

  rtc.adjust(DateTime(__DATE__, __TIME__));

  pinMode (salidaA, INPUT); // pin 2
  pinMode (salidaB, INPUT); // pin 3
  // el pulsador debe ser polarizado a valor ALTO
  pinMode (boton, INPUT_PULLUP);

  pinMode(LUZVEGETATIVO, OUTPUT);
  pinMode(LUZFLORACION, OUTPUT);
  pinMode(EXTRACCIONVEGE, OUTPUT);
  pinMode(EXTRACCIONFLORA, OUTPUT);
  pinMode(COMODIN1, OUTPUT);
  pinMode(COMODIN2, OUTPUT);
  pinMode(VENTILACION, OUTPUT);
  digitalWrite(LUZVEGETATIVO, HIGH);
  digitalWrite(LUZFLORACION, HIGH);
  digitalWrite(EXTRACCIONVEGE, HIGH);
  digitalWrite(EXTRACCIONFLORA, HIGH);
  digitalWrite(COMODIN1, HIGH);
  digitalWrite(COMODIN2, HIGH);
  digitalWrite(VENTILACION, LOW);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  dht1.begin();
  dht2.begin();

  lcd.createChar(1, termometru);
  lcd.createChar(2, linea);
  lcd.createChar(3, vertical);
  lcd.createChar(4, curvita);
  lcd.createChar(5, verticalArriba);
  lcd.createChar(6, flechaIzq);
  lcd.createChar(7, flechaDer);

  int estadoPrevioA = digitalRead(salidaA);
}

void loop () {
  int contador = 0;
  int estadoA = 0;
  int estadoPrevioA = 0;

  if (bienvenidaState == false) {
    bienvenida();
  }

  //configurarVEGE();
  //configurarFLORA();

  //if (hayEEPROM == false) {
    lcd.setCursor(0,0);
    lcd.print("Hora ON vege");
    float horaONveg = encoder(contador, estadoA, estadoPrevioA);
    Serial.println("asdasdasd");
    Serial.println(horaONveg);

    
    float horaOFFveg = encoder(contador, estadoA, estadoPrevioA);
    float tempMAXveg = encoder(contador, estadoA, estadoPrevioA);
    float tempMINveg = encoder(contador, estadoA, estadoPrevioA);
    float humMAXveg = encoder(contador, estadoA, estadoPrevioA);
    float humMINveg = encoder(contador, estadoA, estadoPrevioA);

    float horaONflora = encoder(contador, estadoA, estadoPrevioA);
    float horaOFFflora = encoder(contador, estadoA, estadoPrevioA);
    float tempMAXflora = encoder(contador, estadoA, estadoPrevioA);
    float tempMINflora = encoder(contador, estadoA, estadoPrevioA);
    float humMAXflora = encoder(contador, estadoA, estadoPrevioA);
    float humMINflora = encoder(contador, estadoA, estadoPrevioA);

   // hayEEPROM = true;
  //}


  float temp1 = getDHT1Temp();
  float hum1  = getDHT1Hum();
  float temp2 = getDHT2Temp();
  float hum2  = getDHT2Hum();
  mostrarTodo(temp1, temp2, hum1, hum2);
  delay(10000);

  luces();
  decisiones(temp1, temp2, hum1, hum2);
}
