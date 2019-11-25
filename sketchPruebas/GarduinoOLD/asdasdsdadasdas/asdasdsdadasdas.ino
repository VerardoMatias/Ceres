//Developed by Matias Verardo

//Conexiones!
/*
  ---DHT22--
  Mirandolo de frente, del plastico, se cuenta de izq a derecha 4 pines
  1. GND
  2. PIN 8
  3. LIBRE
  4. VCC(5V)

  ---DISPLAY I2C---
  Está marcado.
  GND <-> GND
  VCC <-> VCC(5V)
  SDA <-> A4
  SCL <-> A5

  ---SALIDAS DIGITALES---
  Está marcado.
  GND&COM1&GND <-> GND
  VCC <-> VCC(5V)
  INT1 <-> PIN 11
  INT2 <-> PIN 12  
*/


#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

#define DHTPIN 8                   // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22              // DHT 22  (AM2302), AM2321

#define extractor 11
#define luzLED 12

DHT dht(DHTPIN, DHTTYPE);

/****************************************BOTONES**********************************************/
const int  Up_buttonPin   = 3;    // the pin that the pushbutton is attached to
const int  Down_buttonPin = 4;
const int  Select_buttonPin = 5;
const int  Back_buttonPin = 6;
int buttonPushCounter = 0;        // counter for the number of button presses

/*UP*/
int up_buttonState = 0;           // current state of the up button
int up_lastButtonState = 0;       // previous state of the up button

/*SELECT*/
int select_buttonState = 0;
int select_lastButtonState = 0;

/*DOWN*/
int down_buttonState = 0;         // current state of the up button
int down_lastButtonState = 0;     // previous state of the up button

/*BACK*/
int back_buttonState = 0;
int back_lastButtonState = 0;

bool bPress = false;//cambia de valor cuando se presiona UP o DOWN
bool SPress = false;//cambia de valor cuando se presiona SELECT

/**************************BANDERAS*****************************/
bool hayEEPROM = false;         /***modo debug*** false para pasar por configuracion de usuario, true para ver hum y temp******************************************************************************************************************/
bool bienvenidaState = false;


/*DATOS INGRESADOS POR EL USUARIO*/
byte luzHsOn = 0;                  //Horario en que se prende la luz
byte luzHsOff = 0;                 //Horario en que se apaga la luz 
byte tempMax = 0;                  //Temperatura maxima
byte tempMin = 0;                  //Temperatura minima
byte humMax = 0;                   //Humedad maxima
byte humMin = 0;                   //Humedad minima

/*DATOS SENSORES*/
/*DHT-22*/

/*TEMPERATURA*/
String temperaturaLCD = "";
byte tempAhora, promTemps = 0;

/*HUMEDAD*/
String humedadLCD = "";
byte humAhora, promHums = 0;


void setup() {
  Serial.begin(9600);
  pinMode( Up_buttonPin , INPUT_PULLUP);                //Boton Arriba
  pinMode( Down_buttonPin , INPUT_PULLUP);              //Boton Abajo
  pinMode( Select_buttonPin , INPUT_PULLUP);            //Boton Seleccionar
  pinMode( Back_buttonPin , INPUT_PULLUP);              //Boton BACK

  pinMode (extractor, OUTPUT);
  digitalWrite(extractor, LOW);
  pinMode (luzLED, OUTPUT);
  digitalWrite(luzLED, LOW);

  lcd.init();
  lcd.backlight();
  dht.begin();
}

void loop() {
  
  if (bienvenidaState == false) {
    bienvenida();
  }

  //Leer datos EEPROM

  /*if (hayEEPROM == false) { //chequear si hay datos almacenados en EEPROM
    byte luzHsOn = pedirHoraOn();
    byte luzHsOff = pedirHoraOff();
    byte tempMax = pedirTempMax();
    byte tempMin = pedirTempMin();
    byte humMax = pedirHumMax();
    byte humMin = pedirHumMin();
    
    hayEEPROM = true;

  }*/

  tempAhora = sensarTemperatura();
  humAhora = sensarHumedad();

  mostrarTemperatura(tempAhora);
  mostrarHumedad(humAhora);

  Serial.println(tempAhora);

  if(tempAhora >= 20){
    digitalWrite(extractor, HIGH);
    delay(2000);
    digitalWrite(extractor, LOW);
  }






























  

}
