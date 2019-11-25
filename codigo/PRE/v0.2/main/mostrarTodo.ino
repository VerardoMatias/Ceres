void mostrarTodo(float temp1, float temp2, float hum1, float hum2) {

  float hum2Resta = hum2 - 10;
  float hum1Resta = hum1 - 0;

  //String horaLCD = 0;
  String temp1LCD = (String)temp1;
  String temp2LCD = (String)temp2;
  String hum1LCD  = (String)"%" + hum1Resta;
  String hum2LCD  = (String)"%" + hum2Resta;

  int anio = 0;
  int mes  = 0;
  int dia = 0;
  int hora = 0;
  int minuto = 0;
  int segundo = 0;

  DateTime now = rtc.now();


  anio    = now.year();
  mes     = now.month();
  dia     = now.day();
  hora    = now.hour();
  minuto  = now.minute();
  segundo = now.second();

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  String laFecha = (String)dia + "/" + (String)mes;
  String laHora = (String)hora + ":" + (String)minuto;

  lcd.setCursor(0, 0);
  lcd.print(laFecha);

  lcd.setCursor(15, 0);
  lcd.print(laHora);

  lcd.setCursor(0, 2);
  lcd.write(1);
  lcd.setCursor(1, 2);
  lcd.print(temp1LCD);

  lcd.setCursor(14, 2);
  lcd.write(1);
  lcd.setCursor(15, 2);
  lcd.print(temp2LCD);

  lcd.setCursor(0, 3);
  lcd.print(hum1LCD);

  lcd.setCursor(14, 3);
  lcd.print(hum2LCD);

  imprimirLinea();

}
