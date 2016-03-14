/*********************************************************************
  Yohalmo Alexander Diaz Ramirez
  DR12004
  EBB-115 Ciclo 1 2016
*********************************************************************/

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16

int SensorPin[] = {A0, A1};
int Vector[] = {0, 0};
int Tamano[] = {83, 47};


void setup()   {
  Serial.begin(9600);

  display.begin();// inicializar
  
  display.setContrast(60);// arreglar el contraste

  display.clearDisplay();   // limpiar patalla y buffer

}


void loop() {
  //  display.clearDisplay();   // limpiar patalla y buffer

  //recorre el vector SensorPin para ver las mediciones hechas y a luego sumarlas a Vector
  for (int i = 0; i < 2; i++) {
    Vector[i] += medir(SensorPin[i]);//suma, resta o queda igual segun el valor retornado por funcion medir
    Vector[i] = constrain(Vector[i], 0, Tamano[i]);//impide recibir valores por encima de los rangos y por debajo de cero
  }

  display.drawPixel(Vector[0], Vector[1], BLACK);//dibuja pixel acumulado en vector

  display.display();//muestra en pantalla

  delay(150);

}

//funcion para retornar el valor, segun posicion del potenciometro
int medir(int pin) {
  
  float lectura = analogRead(pin); 
  int voltaje = map(lectura, 0, 1023, 0, 100);//mapeo para encontrar porcentaje
  voltaje = constrain(voltaje, 0, 100);

  if ( voltaje < 45 ) {
    return -1;
  }
  else if (voltaje < 55) {
    return 0;
  }
  else {
    return 1;
  }
}

