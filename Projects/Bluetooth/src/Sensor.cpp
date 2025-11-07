#include "DHT.h"
#include <BluetoothSerial.h>
#include <Arduino.h>
BluetoothSerial Gus;

DHT dht(13, DHT22);
uint8_t Luccas[] = {0x14, 0x33, 0x5C, 0x52, 0x2E, 0x36};

void setup(){
Serial.begin(9600);
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
   }
  else{
    Serial.println("Nao recebendo");
  }
 }


String mensagemEnviada;
void loop(){
    delay(2000);
  
  
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  float hif = dht.computeHeatIndex(f);
  float hic = dht.computeHeatIndex(t,  false);


  if (isnan(t)|| isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
    mensagemEnviada = Serial.readStringUntil('\n');
    mensagemEnviada.trim();
    Gus.printf("Celsius %.2f\n", t); 
    Gus.printf("Fahrenheit %.2f\n", f);
    Serial.print(F(" Temperature: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print(F(" Fahrenheit:  "));
    Serial.print(f);
    Serial.print(F("°F "));

}