float getDHT1Temp() {

  float t1 = dht1.readTemperature();
  float f1 = dht1.readTemperature(true);

  return t1;
}
