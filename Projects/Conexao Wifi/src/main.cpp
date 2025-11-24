#include <Arduino.h>
#include <Wifi.h>
#include <ezTime.h>
#include <LiquidCrystal_I2C.h>
#include <Bounce2.h>

LiquidCrystal_I2C lcd(0x27,20,4);
Bounce Botao = Bounce();

void conexaoWifi();
void reconexaoWifi();
bool alarme;
bool alarmeAtivado;
const char *SSID = "SENAI IoT";
const char *SENHA = "Senai@IoT";
const unsigned long tempoEsperaConexao = 5000;
const unsigned long tempoEsperaReconexao = 5000;

String dia, mes, ano, hora, minuto, segundo, diaAnterior, segundoAnterior, horaAnterior, minutoAnterior, anoAnterior, mesAnterior, horaAlarme, minutoAlarme, texto;
Timezone sp;

void setup(){
  Serial.begin(115200);

  Botao.attach(0, INPUT_PULLUP);

  pinMode(2, OUTPUT);

  lcd.init();

  lcd.backlight();

  lcd.setCursor(0,2);

  lcd.print("Alarme:");

  lcd.setCursor(0,3);

  lcd.print("Status:");

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
  
}



void loop(){
  Botao.update();
  if(Botao.fell()){
    Serial.println("Botao Acionado");
  }

  texto = Serial.readStringUntil('\n');
  texto.trim();
  lcd.setCursor(8,2);
  lcd.printf("%s:%s", horaAlarme, minutoAlarme);
  

  //reconexaoWifi();

  dia = sp.dateTime("d");
  mes = sp.dateTime("M");
  ano = sp.dateTime("Y");

  hora = sp.dateTime("H");
  minuto = sp.dateTime("i");
  segundo = sp.dateTime("s");

  if(segundo != segundoAnterior){
    lcd.setCursor(8,1);
    lcd.print(segundo);
  }

  if(hora != horaAnterior){
    lcd.setCursor(2,1);
    lcd.print(hora);
  }

  if(minuto != minutoAnterior){
    lcd.setCursor(5,1);
    lcd.print(minuto);
  }

  if(dia != diaAnterior){
    lcd.setCursor(0,0);
    lcd.print(dia);
  }

  if(ano != anoAnterior){
    lcd.setCursor(13,0);
    lcd.print(ano);
  }

  if(mes != mesAnterior){
    lcd.setCursor(6,0);
    lcd.print(mes);
  }
if(!texto.equals("")){
  horaAlarme = texto.substring(0,2);
  minutoAlarme = texto.substring(3);
  lcd.setCursor(8,3);
  lcd.print("Ativado   ");
}

if(horaAlarme.equals(hora) && minutoAlarme.equals(minuto)){
  alarme = true;
  alarmeAtivado = true;
    if(alarme == true){
      digitalWrite(2, HIGH);
      lcd.setCursor(8,3);
      lcd.print("Ativo     ");
    }
}

else if(alarmeAtivado == true && Botao.fell()){
  alarme = false;
  Serial.println("Alarme desativado");
}

else{
  alarme = false;
  lcd.setCursor(8,3);
  lcd.print("Desativado");
  digitalWrite(2, LOW);
}

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