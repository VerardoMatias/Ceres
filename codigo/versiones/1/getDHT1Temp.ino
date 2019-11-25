float getDHT1Temp() {

  float t1 = dht1.readTemperature();
  float f1 = dht1.readTemperature(true);

  if (isnan(t1) || isnan(f1)) {
    Serial.println(F("Failed to read from DHT1 sensor!"));
    return;
  }

  Serial.print(F("%  Temperature: "));
  Serial.print(t1);
  Serial.print(F("°C "));

  return t1;
}
