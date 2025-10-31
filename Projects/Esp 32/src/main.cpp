#include <Arduino.h>

bool estadoA;
bool estadoBotao;
bool statusLed;


void setup()
{
  pinMode(0, INPUT);
  pinMode(2, OUTPUT);

}


void loop()
{
    estadoBotao = digitalRead(0);
    if(estadoA == 1 && estadoBotao == 0){
        statusLed = !statusLed;
    }
}



