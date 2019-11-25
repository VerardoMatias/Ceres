int pedirHoras() {
bool Bot = digitalRead(boton);
  do{
  contador = 0;
  // Lee el estado de la salida A
  estadoA = digitalRead(salidaA);
  // Si el estado previo de la salida A era otro
  // significa que se ha producido un pulso
  if (estadoA != estadoPrevioA) {
    // Si el estado de salida B es diferente del estado
    // de salida A el codificador esta girando a la derecha
    if (digitalRead(salidaB) != estadoA) {
      contador ++;
    } else {
      contador --;
    }
    Serial.print("Posición: ");
    Serial.println(contador);
  }
  // actualiza el estado guardado
  estadoPrevioA = estadoA;

  bool Bot = digitalRead(boton);
  //Serial.print(B);
  }while (!Bot); // si se pulsa el boton su valor va a BAJO
  Serial.println("Boton pulsado: Contador = ");
    Serial.print(contador);
    delay(300);

  return contador;
}
