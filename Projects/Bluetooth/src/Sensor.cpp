#include "DHT.h"
#include <BluetoothSerial.h>
#include <Arduino.h>
#include <ArduinoJson.h>
BluetoothSerial Gus;

DHT dht(13, DHT22);
uint8_t Luccas[] = {0x14, 0x33, 0x5C, 0x52, 0x2E, 0x36};
JsonDocument oc;
int valorgas;
bool statusLed;
void setup(){
Serial.begin(9600);
pinMode(26, OUTPUT);
pinMode(2, OUTPUT);
Serial.println(F("DHTxx test!"));
dht.begin();
if(Gus.begin("Esp-Recebo", true)){
    Serial.println("Deu certo");
  }
  
  else{
    Serial.println("Deu errado");
  }

   if(Gus.connect(Luccas)){
    Serial.println("Recebendo");
    digitalWrite(2, HIGH);
   }
  else{
    Serial.println("Nao recebendo");
  }
 }


String mensagemEnviada;
void loop(){
    delay(2000);
  
  valorgas = analogRead(27);
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  float hif = dht.computeHeatIndex(f);
  float hic = dht.computeHeatIndex(t,  false);


  // if (isnan(t)|| isnan(f)) {
  // Serial.println(F("Failed to read from DHT sensor!"));
  //  return;
  // }
  
  // oc["celsius"] = t;
  // oc["fahrenheit"] = f;
  // oc["umidade"] = 0.0;
  oc["gas"] = valorgas;
  serializeJson(oc, mensagemEnviada);
  Gus.print(mensagemEnviada);
  Serial.println(mensagemEnviada);
  if(valorgas > 2500){
    digitalWrite(26, HIGH);
  }
  else{
    digitalWrite(26, LOW);
  }

}