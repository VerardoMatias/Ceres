float getDHT1Hum() {
  
  float h1 = dht1.readHumidity();

  Serial.print(F("Humidity: "));
  Serial.println(h1);

  return h1;
}
