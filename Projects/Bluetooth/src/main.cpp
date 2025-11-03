#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial Recebo;
uint8_t receba[] = {0x14, 0x33, 0x5C, 0x52, 0x2E, 0x36};
bool pisca;
bool led;
unsigned long tempo;
// void setup() {
//   Serial.begin(9600);
//   Serial.setTimeout(5000);
    
  
//     if(Recebo.begin("EspSlave-gustavinhogameplay")){
//     Serial.println("Blu ligado");
//     Serial.print("Endereço Blue ESP: ");
//     Serial.println(Recebo.getBtAddressString());
//     //78:42:1C:6D:0C:0E
//   }



//   else{
//     Serial.println("Lascou-se");
//   }

// }
// void loop() {
//   if(Recebo.available()){
//     String mensagenCapitada = Recebo.readStringUntil('\n');
//     mensagenCapitada.trim();
//     Serial.printf("Recebo: %s", mensagenCapitada);
//   }

//   if(Serial.available()){
//    String mensagemEnviar = Serial.readStringUntil('\n');
//    mensagemEnviar.trim();
//    BT.println(mensagemEnviar); 
//   }


//   } 

void setup(){
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(5000);
  if(Recebo.begin("Esp-Recebo", true)){
    Serial.println("Deu certo");
  }
  
  else{
    Serial.println("Deu errado");
  }

  if(Recebo.connect(receba)){
    Serial.println("Recebendo");
  }
  else{
    Serial.println("Nao recebendo");
  }
}



void loop(){
  String mensagenCapitada;
  if(Recebo.available()){
    mensagenCapitada = Recebo.readStringUntil('\n');
    mensagenCapitada.trim();
    Serial.printf("Recebo: %s\n", mensagenCapitada);
  }

  if(Serial.available()){
   String mensagemEnviar = Serial.readStringUntil('\n');
   mensagemEnviar.trim();
   Recebo.println(mensagemEnviar); 
  }
  if(mensagenCapitada.equals("liga")){
  Serial.println("acendo o Led");
  led = true;
  pisca = false;

}
if(mensagenCapitada.equals("desliga")){
  Serial.println("apaga Led");
  led = false;
  pisca = false;
}
if(mensagenCapitada.equals("pisca")){
  Serial.println("faz o Led piscar");
  pisca = true;
}

if(pisca){
  if(millis() - tempo >= 500){
    led = !led;
    tempo = millis();
  }
}

digitalWrite(12, led);
}

