void decisiones (float temp1, float temp2, float hum1, float hum2) {

  float hum2R = hum2 - 10;
  
  if ((temp1 <= tempMINveg) || (temp1 >= tempMAXveg)) {//falta ver alguna manera de mantener todo siempre apagado, que ntre al if, revse todo y si esta entre valores, que apague todo

    if (temp1 <= tempMINveg) {
      Serial.println("VEGE TEMP -");
      //digitalWrite();
      //grabar horario
    }
    if (temp1 >= tempMAXveg) {
      Serial.println("VEGE TEMP +");
      digitalWrite(EXTRACCIONVEGE, LOW);
      Serial.println("VEGE EXTRACCION ON");
      //grabar horario
    }
  }

  if ((temp2 <= tempMINflora) || (temp2 >= tempMAXflora)) {

    if (temp2 <= tempMINflora) {
      Serial.println("FLORA TEMP -");
      //digitalWrite();
      //grabar horario
    }
    if (temp2 >= tempMAXflora) {
      Serial.println("FLORA TEMP +");
      digitalWrite(EXTRACCIONFLORA, LOW);
      Serial.println("FLORA EXTRACCION ON");
      //grabar horario
    }
  }

  if ((hum1 <= humMINveg) || (hum1 >= humMAXveg)) {

    if (hum1 <= humMINveg) {
      Serial.println("VEGE HUM -");
      digitalWrite(COMODIN1, LOW);
      Serial.println("HUMIDIFICADOR ON");
      //grabar horario
    }
    if (hum1 >= humMAXveg) {
      Serial.println("VEGE HUM +");
      digitalWrite(EXTRACCIONVEGE, LOW);
      Serial.println("VEGE EXTRACCION ON");
      //grabar horario
    }
  }

  if ((hum2R <= humMINflora) || (hum2R >= humMAXflora)) {

    if (hum2R <= humMINflora) {
      Serial.println("FLORA HUM -");
      //digitalWrite();
      //grabar horario
    }
    if (hum2R >= humMAXflora) {
      Serial.println("FLORA HUM +");
      //digitalWrite();
      //grabar horario
    }
  }
}
