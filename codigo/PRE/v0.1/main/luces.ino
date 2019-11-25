void luces () {

  int hora = 0;

  DateTime now = rtc.now();
  hora    = now.hour();

  if ((now.hour() <= horaOFFveg) || (now.hour() >= horaONveg)) {
    digitalWrite(LUZVEGETATIVO, LOW);
    Serial.println("VEGE LUZ ON");
  } else {
    digitalWrite(LUZVEGETATIVO, HIGH);
    Serial.println("VEGE LUZ OFF");
  }

  if ((now.hour() <= horaOFFflora) || (now.hour() >= horaONflora)) {
    digitalWrite(LUZFLORACION, LOW);
    Serial.println("FLORA LUZ ON");
  } else {
    digitalWrite(LUZFLORACION, HIGH);
    Serial.println("FLORA LUZ OFF");
  }

}
