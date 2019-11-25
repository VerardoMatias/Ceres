float getDHT2Temp() {

  float t2 = dht2.readTemperature();
  float f2 = dht2.readTemperature(true);

  return t2;
}
