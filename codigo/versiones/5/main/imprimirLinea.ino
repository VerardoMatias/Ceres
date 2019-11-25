void imprimirLinea() {

  lcd.setCursor(7, 0);
  lcd.print("INDOOR");

  lcd.setCursor(0, 1);
  lcd.write(2);

  lcd.setCursor(1, 1);
  lcd.write(2);

  lcd.setCursor(2, 1);
  lcd.write(2);

  lcd.setCursor(3, 1);
  lcd.write(2);

  lcd.setCursor(4, 1);
  lcd.write(2);

  lcd.setCursor(5, 1);
  lcd.write(5);

  lcd.setCursor(5, 0);
  lcd.write(3);

  lcd.setCursor(6, 1);//curvita1
  lcd.write(4);

  lcd.setCursor(6, 2);
  lcd.write(3);

  lcd.setCursor(6, 3);
  lcd.write(3);
  /*---------------------------------------*/

  /*---------------------------------------*/

  lcd.setCursor(19, 1);
  lcd.write(2);

  lcd.setCursor(18, 1);
  lcd.write(2);

  lcd.setCursor(17, 1);
  lcd.write(2);

  lcd.setCursor(16, 1);
  lcd.write(2);

  lcd.setCursor(15, 1);
  lcd.write(2);

  lcd.setCursor(14, 1);
  lcd.write(5);

  lcd.setCursor(14, 0);
  lcd.write(3);

  lcd.setCursor(13, 1);//curvita1
  lcd.write(4);

  lcd.setCursor(13, 2);
  lcd.write(3);

  lcd.setCursor(13, 3);
  lcd.write(3);

  /*---------------------------------------*/

  /*---------------------------------------*/

  lcd.setCursor(7, 1);
  lcd.write(2);

  lcd.setCursor(8, 1);
  lcd.write(2);

  lcd.setCursor(9, 1);
  lcd.write(2);

  lcd.setCursor(10, 1);
  lcd.write(2);

  lcd.setCursor(11, 1);
  lcd.write(2);

  lcd.setCursor(12, 1);
  lcd.write(2);

  /*---------------------------------------*/

  /*---------------------------------------*/

  lcd.setCursor(12, 2);
  lcd.write(7);

  lcd.setCursor(7, 3);
  lcd.write(6);

  lcd.setCursor(8, 3);
  lcd.print("S11.3");
  
  lcd.setCursor(7, 2);
  lcd.print("S4.6");

  Serial.println("/**********************************/");

}
