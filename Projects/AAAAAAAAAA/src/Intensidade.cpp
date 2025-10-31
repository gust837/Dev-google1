#include <Arduino.h>
#include <Bounce2.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

Bounce Botao = Bounce();
Bounce Botao2 = Bounce();
LiquidCrystal_I2C lcd(0x27,20,4);
bool estadoB1;
bool estadoB2;
int brilho;
int valorLed;
int cont;

     


void setup(){
    Serial.begin(9600);
    pinMode(27, OUTPUT);
    Botao2.attach(0, INPUT_PULLUP);
    Botao.attach(12 , INPUT_PULLUP); 
    lcd.init();
    lcd.backlight();
    lcd.print("Nivel:");
}

void loop(){
    Botao.read();
    Botao.update();
    Botao2.update();
    if(Botao.fell()){
        cont +=10;
        if(cont>=100){
            cont = 100;
        }
    }

    if(Botao2.fell()){
        cont -=10;
        if(cont <0){
            cont = 0;
        }
    }


brilho = map(cont, 0, 100, 0, 255);
analogWrite(27, brilho); 
Serial.println(cont);
lcd.setCursor(7,0);
lcd.print(cont);
lcd.print("%   ");
}