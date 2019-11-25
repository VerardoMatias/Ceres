/*  Codificador rotativo Keyes KY-040
    ( KY-007 para algunos vendedores )
    Prueba de conteo, direccion y  pulsador
    No se filtra los ruidos de contacto
*/

#define salidaA 2 //CLK
#define salidaB 3 //DT
#define boton 4   //SW

int contador = 0;
int estadoA;
int estadoPrevioA;
void setup() {
  pinMode (salidaA, INPUT); // pin 2
  pinMode (salidaB, INPUT); // pin 3
  // el pulsador debe ser polarizado a valor ALTO
  pinMode (boton, INPUT_PULLUP);

  Serial.begin (9600);
  // Lee el estado inicial de la salida A
  estadoPrevioA = digitalRead(salidaA);
}
void loop() {

  int horasModif;

  horasModif = pedirHoras();

  Serial.println(horasModif);

  
  
  
}
