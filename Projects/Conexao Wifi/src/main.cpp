#include <Arduino.h>
#include <Wifi.h>
#include <ezTime.h>

void conexaoWifi();
void reconexaoWifi();

const char *SSID = "SENAI IoT";
const char *SENHA = "Senai@IoT";
const unsigned long tempoEsperaConexao = 5000;
const unsigned long tempoEsperaReconexao = 5000;

Timezone sp;

void setup(){
  Serial.begin(115200);

  conexaoWifi();
  
  waitForSync();
  
  sp.setLocation("America/Sao_Paulo");

  //Serial.println(sp.dateTime());
  //Serial.println(sp.dateTime("d/m/Y H:i:s"));
 // --- Outros códigos úteis ---
  // Y -> Ano completo (2025)
  // y -> Ano com 2 dígitos (25)
  // m -> Mês (01-12)
  // d -> Dia (01-31)
  // H -> Hora (00-23)
  // i -> Minuto (00-59)
  // s -> Segundo (00-59)
  // l -> Dia da semana por extenso (Thursday)
  // D -> Dia da semana abreviado (Thu)
  // F -> Nome completo do mês (November)
  // M -> Nome abreviado do mês (Nov)
  // a/A -> am/pm
  // O/P -> Diferença UTC (-0300 / -03:00)
  // T -> Sigla do fuso (BRT)
  // Z -> Offset em segundos (-10800)
  // z -> Dia do ano (0–365)

  // Serial.println(sp.minute());
  // Serial.println(sp.second());
  // Serial.println(sp.hour());
  // Serial.println(sp.day());
  // Serial.println(sp.month());
  // Serial.println(sp.year());
  // Serial.println(sp.dayOfYear());
  // Serial.println(sp.isDST());
  Serial.print(sp.dateTime("\\Ho\\j\\e é "));
  Serial.print(sp.dateTime("d").toInt() - 1);
  Serial.print(sp.dateTime(" \\d\\e F" ));
  Serial.print(sp.dateTime(" \\e \\a\\g\\or\\a \\s\\a\\o h "));
  Serial.print(sp.dateTime(" i ").toInt() - 20);
  Serial.print(sp.dateTime(" s "));




}



void loop(){

  reconexaoWifi();

}

void conexaoWifi(){
Serial.printf("Conectando ao wifi: %s\n", SSID);

  WiFi.begin(SSID, SENHA);

  unsigned long tempoInicialWifi = millis();

  while (WiFi.status() != WL_CONNECTED && millis() - tempoInicialWifi < tempoEsperaConexao)
  {
    Serial.print(".");
    delay(500);
  }

  if(WiFi.status() == WL_CONNECTED){
    Serial.println("\nWifi conectado com sucesso!");
    Serial.print("Endereço de IP: ");
    Serial.println(WiFi.localIP());
  }

  else{
    Serial.println("Wifi nao conectado, tente novamente!");
  }

}


void reconexaoWifi(){
  unsigned long tempoAtual = millis();
  unsigned long tempoUltimaConexao = 0;

  if(tempoAtual - tempoUltimaConexao > tempoEsperaReconexao)
  {
    if(WiFi.status() != WL_CONNECTED){
      Serial.println("Conexao wifi perdida");
      conexaoWifi();
    }


    tempoUltimaConexao = tempoAtual;
  }
}