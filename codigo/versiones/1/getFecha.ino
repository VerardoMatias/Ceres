String getFecha() {

  int anio = 0;
  int mes  = 0;
  int dia = 0;
  int hora = 0;
  int minuto = 0;
  int segundo = 0;

  DateTime now = rtc.now();

  String fecha = (String)dia + "/" + (String)mes ;

  anio    = now.year();
  mes     = now.month();
  dia     = now.day();
  hora    = now.hour();
  minuto  = now.minute();
  segundo = now.second();

  Serial.println(fecha);
  
  return fecha;
}
