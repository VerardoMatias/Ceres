int led13=4;
//int estado=0;
String readString;
char Dato;

#include <IRremote.h>

IRsend irsend;

void setup() {
  Serial.begin(9600);
  pinMode(led13, OUTPUT);
}

void loop() {
  leer_Dato();
  if (readString.length()>0) {
    if (readString == "TV1") {
    irsend.sendNEC(0x20DF8877, 32); //  TV CHANNEL 1
      delay(40);
      Serial.println("TV CHANNEL 1");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    readString = "";
    }
    if (readString == "TV2") {
    irsend.sendNEC(0x20DF48B7, 32); // TV CHANNEL 2
      delay(40);
      Serial.println("TV CHANNEL 2");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    readString = "";
    }
  }
}   
      
/////////////////////////////////////////////////////////<<<<<<< TV CONTROL >>>>>>>////////////////////////////////////////////////////////////////////    
    
void leer_Dato(){
  while (Serial.available()){
    delay (10);
    if (Serial.available()>0){
      Dato = Serial.read();
      readString += Dato;
    }
  }
}


/*
    case'TV3':
    irsend.sendNEC(0x20DFC837, 32); // TV CHANNEL 3
      delay(40);
      Serial.println("TV CHANNEL 3");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'TV4':
    irsend.sendNEC(0x20DF28D7, 32); // TV CHANNEL 4
      delay(40);
      Serial.println("TV CHANNEL 4");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'TV5':
    irsend.sendNEC(0x20DFA857, 32); // TV CHANNEL 5
      delay(40);
      Serial.println("TV CHANNEL 5");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'TV6':
    irsend.sendNEC(0x20DF6897, 32); // TV CHANNEL 6
      delay(40);
      Serial.println("TV CHANNEL 6");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'TV7':
    irsend.sendNEC(0x20DFE817, 32); // TV CHANNEL 7
      delay(40);
      Serial.println("TV CHANNEL 7");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'TV8':
    irsend.sendNEC(0x20DF18E7, 32); // TV CHANNEL 8
      delay(40);
      Serial.println("TV CHANNEL 8");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'TV9':
    irsend.sendNEC(0x20DF9867, 32); // TV CHANNEL 9
      delay(40);
      Serial.println("TV CHANNEL 9");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'TV0':
    irsend.sendNEC(0x20DF08F7, 32); // TV CHANNEL 0
      delay(40);
      Serial.println("TV CHANNEL 0");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'TVON':
    irsend.sendNEC(0x20DF10EF, 32); // TV POWER
      delay(40);
      Serial.println("TV POWER");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    /*case'TVCUP':
    irsend.sendNEC(0x20DFC03F, 32); // TV CHANNEL UP
      delay(40);
      Serial.println("TV CHANNEL UP");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'TVVOLDO':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL DOWN
      delay(40);
      Serial.println("TV VOL DOWN");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'TVVOLUP':
    irsend.sendNEC(0x20DF40BF, 32); // TV VOL UP
      delay(40);
      Serial.println("TV VOL UP");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
 */
    
    /*case'TVCDO':
    irsend.sendNEC(0x20DFC03F, 32); // TV CHANNEL DOWN
      delay(40);
      Serial.println("TV CHANNEL DOWN");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
  
//////////////////////////////////////////////////////<<<<<<< DECO CONTROL>>>>>///////////////////////////////////////  
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(200);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(400);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(400);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(400);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(400);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(400);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(400);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    case'2':
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(400);
    digitalWrite(led13, LOW);
    estado = 0;
    break;
    
    
  }
}
    
    
    
  
  /*  
  if (estado =='1') {
    irsend.sendNEC(0x20DF10EF, 32); //  TV POWER
      delay(40);
      Serial.println("TV POWER");
    digitalWrite(led13, HIGH);
    delay(400);
    digitalWrite(led13, LOW);
    
  }
  if(estado =='2') {
    irsend.sendNEC(0x20DFC03F, 32); // TV VOL -
      delay(40);
      Serial.println("TV VOL -");
    digitalWrite(led13, HIGH);
    delay(400);
    digitalWrite(led13, LOW);
  }

}*/
