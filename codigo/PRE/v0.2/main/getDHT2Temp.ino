float getDHT2Temp() {

  float t2 = dht2.readTemperature();
  float f2 = dht2.readTemperature(true);

  Serial.print(F("%  Temperature: "));
  Serial.print(t2);
  Serial.print(F("°C "));

  return t2;
}
