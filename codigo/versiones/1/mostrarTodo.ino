void mostrarTodo(float temp1, float temp2, float hum1, float hum2) {

  //String horaLCD = 0;
  String temp1LCD = (String)temp1 + "C";
  String temp2LCD = (String)temp2 + "C";
  String hum1LCD  = (String)hum1 + "%";
  String hum2LCD  = (String)hum2 + "%";

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

  String laFecha = (String)dia + "/" + (String)mes;
  String laHora = (String)hora + ":" + (String)minuto;

  lcd.setCursor(0, 0);
  lcd.print(laFecha);
  lcd.setCursor(15, 0);
  lcd.print(laHora);
  lcd.setCursor(0, 2);
  lcd.print(temp1LCD);
  lcd.setCursor(14, 2);
  lcd.print(temp2LCD);
  lcd.setCursor(0, 3);
  lcd.print(hum1LCD);
  lcd.setCursor(14, 3);
  lcd.print(hum2LCD);

}
