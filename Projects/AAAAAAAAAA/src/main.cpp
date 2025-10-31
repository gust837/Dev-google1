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

