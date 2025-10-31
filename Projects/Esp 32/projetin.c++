#include <Arduino.h>

bool estadoA;
bool estadoBotao;


void setup()
{
    Serial.begin(9600);
    pinMode(0, INPUT);
    pinMode(2, OUTPUT);

}


void loop()
{
    estaBotao = digitalRead(0)
    digitalWrite(2, HIGH);
    Serial.print("alo!!");
}

