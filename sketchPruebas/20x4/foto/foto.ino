int pinLDR = A2;

int valorLDR = 0;

void setup() {

  Serial.begin(9600);
  
}

void loop() {
  
  valorLDR = analogRead(pinLDR);

  Serial.println(valorLDR);
  delay(200);

}
