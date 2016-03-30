/********************************************************************************************************************************
  (2016/03/31)
  Universidad Nacional de El Salvador, Facultad de Ingenieria Y Arquitectura.
  EBB-115 Ciclo 1 2016. 
  
  MSc. e Ing. Wilber Calderon.

  Yohalmo Alexander Diaz Ramirez    DR12004.

  OBJETIVO: crear un osciloscopio con LCD Nokia-5110 (84x48)

  CIRCUITO:
  -Potenciometro (Analogico 0)
  -A Tierra y 5V
  
  LCD De Izquierda a derecha(al 4050):
  -RST al PIN 2 del 4050
  -CE al PIN 4 del 4050
  -DC al PIN 6 del 4050
  -DIN al PIN 15 del 4050
  -CLK al PIN 12 del 4050
  -VCC a 3.3V
  -LIGHT a Tierra
  -GND a Tierra

  4050 a Arduino:
  -PIN 1 a 3.3V
  -PIN 3 a Digital 3
  -PIN 5 a Digital 4
  -PIN 7 a Digital 5
  -PIN 8 a Tierra
  -PIN 11 a Digital 6
  -PIN 14 a Digital 7

  REFERENCIAS:
  https://github.com/Megamemnon/Arduino-Oscilloscope/blob/master/Uno3VOScope.ino
  http://www.thingiverse.com/thing:184218
  http://blog.novaeletronica.com.br/en/osciloscopio-usando-arduino/
********************************************************************************************************************************/

#include "Adafruit_GFX.h"
#include "Adafruit_PCD8544.h"
#define   LARGO   250

Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

int channelAI = A0;      // entrada
int delayAI = A1;       // potenciometro delay

float delayVariable = 5; 
float scale = 0;
int xContar = 0;
int yPosicion = 0;
int lecturas[ LARGO ];
int counter = 0;

void setup() {
    
  Serial.begin(9600);
  
  display.begin();
  display.setContrast(50); 
  display.clearDisplay();     // limpiar pantalla y buffer

  // Texto de Introduccion
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Bienvenidos");
  display.println("");
  display.println("Osciloscopio");
  display.println("");
  display.println("Yohalmo");
  display.println("      EBB-115");
  display.display();
  delay(1000);
  display.clearDisplay();
 
}


void loop() 
{  
  
  delayVariable = analogRead(delayAI);
  delayVariable = delayVariable/100;
  scale = 47.0/1023.0;  
  
  //guarda lecturas
  for(xContar = 0; xContar < LARGO ; xContar += 1){                                 
      yPosicion = analogRead(channelAI);
      lecturas[xContar] = (yPosicion*scale);
      delay (delayVariable);
    }
  
  display.clearDisplay();
  
  DibujarEjes(); // Funcion para dibujar los ejes

  for(xContar = 0; xContar < 85; xContar += 1){
       display.drawPixel(xContar, 47-lecturas[xContar], BLACK);
       
       if(xContar>1){
         display.drawLine(xContar-1, 47-lecturas[xContar-1], xContar, 47-lecturas[xContar], BLACK);
       }
    }
  
  display.display();     
} 


