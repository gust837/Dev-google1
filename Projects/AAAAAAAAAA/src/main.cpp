/*#include <Arduino.h>
#include <Bounce2.h>
Bounce Botao = Bounce();

bool estadoB;
bool statusLed = LOW;
bool pisca;
int cont = 0;
unsigned long LedI;
unsigned long LedA;

void setup() {
  Serial.begin(9600);
  pinMode(27, OUTPUT);
  Botao.attach(12 , INPUT_PULLUP); 
}

void loop() {
  estadoB = Botao.read();
  LedA = millis();
  Botao.update();

  if(Botao.fell()){
    statusLed = !statusLed;
    pisca = false;
    if(statusLed == HIGH){
      cont++;
    }
  }
  if(estadoB == 0 && Botao.currentDuration() > 2000){
    pisca = true;
  }

  if(pisca == true){
    if(LedA - LedI >=500){
      statusLed = !statusLed;
      LedI = LedA;
    }
  }
  Serial.println(cont);
  digitalWrite(27, statusLed);
}
*/

// #include <Arduino.h>
// #include <Bounce2.h>
// #include <LiquidCrystal_I2C.h>
// #include <Wire.h> 

// Bounce Botao = Bounce();
// Bounce Botao2 = Bounce();
// LiquidCrystal_I2C lcd(0x27,20,4);
// bool estadoB1;
// bool estadoB2;
// int brilho;
// int valorLed;
// int cont;

 // char frase[] = "ESTAMOS APRENDENDO ARDUINO NA AULA";
  // if(strstr(frase, "ARDUINO")){
  //   Serial.println("Conteudo relacionado a arduino encontrado");
  // }

  // else{
  //   Serial.println("Nao encontrado");
  // }



    // Serial.setTimeout(5000);
    // String mensagem = "Temperatura = 27C";
    // mensagem.trim();
    // mensagem.toUpperCase();
    // if(mensagem.substring(14, 16) == "27"){
    //   mensagem = 27;
    //   int valor = mensagem.toInt();
    //   conversao = (valor * 9/5) + 32;
    // }
    // Serial.println(conversao);
    
    

     //Serial.println("Digite ON ou OFF para comandar o Led: ");
    // if(texto.endsWith("ON")){
    //     digitalWrite(27,HIGH);
    //     Serial.println("Ligar led!");
    // }

    // else if(texto.endsWith("OFF")){
    //     digitalWrite(27,LOW);
    //     Serial.println("Desligar led!");

    // }
    // else{
    //     Serial.println("COMANDO INVALIDO!!!");
    // }
     


// void setup(){
//     Serial.begin(9600);
//     pinMode(27, OUTPUT);
//     Botao2.attach(0, INPUT_PULLUP);
//     Botao.attach(12 , INPUT_PULLUP); 
//     lcd.init();
//     lcd.backlight();
//     lcd.print("Nivel:");
// }

// void loop(){
//     Botao.read();
//     Botao.update();
//     Botao2.update();
//     if(Botao.fell()){
//         cont +=10;
//         if(cont>=100){
//             cont = 100;
//         }
//     }

//     if(Botao2.fell()){
//         cont -=10;
//         if(cont <0){
//             cont = 0;
//         }
//     }


// brilho = map(cont, 0, 100, 0, 255);
// analogWrite(27, brilho); 
// Serial.println(cont);
// lcd.setCursor(7,0);
// lcd.print(cont);
// lcd.print("%   ");
// }


//String frase = "sEnAi eSp32 ArDuInO";
  //frase.toLowerCase();
  //frase.toUpperCase();

  //frase.replace("sE", "Se");
  //if(frase.startsWith("Se")){
  //}
  //Serial.println(frase);