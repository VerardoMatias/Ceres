float getDHT2Hum() {
  float h2 = dht2.readHumidity();

  Serial.print(F("Humidity: "));
  Serial.print(h2);

  return h2;
}
