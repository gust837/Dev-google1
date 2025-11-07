// #include <Arduino.h>
// #include <BluetoothSerial.h>
// #include <Bounce2.h>
// Bounce Botao = Bounce();
// BluetoothSerial Recebo;
// String Peresa;
// String PeresaAnterior;
// uint8_t receba[] = {0x14, 0x33, 0x5C, 0x52, 0x2E, 0x36};
// bool pisca;
// bool led;
// bool ledAmigo;
// bool ledAmigoAnt;
// bool piscaAmigo;
// unsigned long tempo;
// // void setup() {
// //   Serial.begin(9600);
// //   Serial.setTimeout(5000);
    
  
// //     if(Recebo.begin("EspSlave-gustavinhogameplay")){
// //     Serial.println("Blu ligado");
// //     Serial.print("Endereço Blue ESP: ");
// //     Serial.println(Recebo.getBtAddressString());
// //     //78:42:1C:6D:0C:0E
// //   }



// //   else{
// //     Serial.println("Lascou-se");
// //   }

// // }
// // void loop() {
// //   if(Recebo.available()){
// //     String mensagenCapitada = Recebo.readStringUntil('\n');
// //     mensagenCapitada.trim();
// //     Serial.printf("Recebo: %s", mensagenCapitada);
// //   }

// //   if(Serial.available()){
// //    String mensagemEnviar = Serial.readStringUntil('\n');
// //    mensagemEnviar.trim();
// //    BT.println(mensagemEnviar); 
// //   }


// //   } 

// void setup(){
//   pinMode(12, OUTPUT);
//   Serial.begin(9600);
//   Serial.setTimeout(5000);
//   Botao.attach(0, INPUT_PULLUP);
//   if(Recebo.begin("Esp-Recebo", true)){
//     Serial.println("Deu certo");
//   }
  
//   else{
//     Serial.println("Deu errado");
//   }

//   if(Recebo.connect(receba)){
//     Serial.println("Recebendo");
//   }
//   else{
//     Serial.println("Nao recebendo");
//   }
// }


// String mensagemEnviar;
// void loop(){
//   Botao.update();
//   Botao.read();
//   String mensagenCapitada;
//   if(Recebo.available()){
//     mensagenCapitada = Recebo.readStringUntil('\n');
//     mensagenCapitada.trim();
//     Serial.printf("Recebo: %s\n", mensagenCapitada);
//   }

//   if(Serial.available()){
//     mensagemEnviar = Serial.readStringUntil('\n');
//     mensagemEnviar.trim();
//     Recebo.println(mensagemEnviar); 
//   }
//   if(mensagenCapitada.equals("liga")){
//   Serial.println("acendo o Led");
//   led = true;
//   pisca = false;

// }
// if(mensagenCapitada.equals("desliga")){
//   Serial.println("apaga Led");
//   led = false;
//   pisca = false;
// }
// if(mensagenCapitada.equals("pisca")){
//   Serial.println("faz o Led piscar");
//   pisca = true;
// }

// if(pisca){
//   if(millis() - tempo >= 500){
//     led = !led;
//     tempo = millis();
//   }
// }

// if(Botao.fell()){
//   ledAmigo = !ledAmigo;
//    if(ledAmigo) Peresa = "ligar";
//   else if (!ledAmigo ) Peresa = "desligar";
//   }
 
//   if(Botao.currentDuration() >= 2000 && Botao.read() == 0){
//     Peresa = "piscar";
//   }
// if(Peresa != PeresaAnterior){
//     Recebo.println(Peresa);
// }
  

// PeresaAnterior = Peresa;
// digitalWrite(12, led);
// }

