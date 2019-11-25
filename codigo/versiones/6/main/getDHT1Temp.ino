float getDHT1Temp() {

  float t1 = dht1.readTemperature();
  float f1 = dht1.readTemperature(true);

  Serial.print(F("%  Temperature: "));
  Serial.print(t1);
  Serial.print(F("°C "));

  return t1;
}
