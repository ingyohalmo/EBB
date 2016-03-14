/********************************************************************************************************************************
  (2016/03/14)
  Universidad Nacional de El Salvador, Facultad de Ingenieria Y Arquitectura.
  EBB-115 Ciclo 1 2016. 
  
  Ing. Wilber Calderon.

  Yohalmo Alexander Diaz Ramirez.
  DR12004.

  El siguiente codigo ha sido creado con el fin aprender la manera corecta 
  para utiliza la pantalla LCD Nokia-5110, utilizando 2 potenciometros se trazan
  rectas y diagonales de manera automatica y se establece un porcentaje para su movimiento
  de 0-45 se mueve hacia la derecha y arriba
  de 45-55 no hay ningun movimiento
  de 55-100 se mueve a la  izquierda y abajo

  REFERENCIAS:
  https://learn.sparkfun.com/tutorials/graphic-lcd-hookup-guide
  https://masamuneshin.wordpress.com/2011/04/30/proyecto-arduino-i-lectura-limpia-de-potenciometro-para-control-de-servomotor/
  https://learn.adafruit.com/downloads/pdf/nokia-5110-3310-monochrome-lcd.pdf
********************************************************************************************************************************/

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

int SensorPin[] = {A0, A1};//se guardan los pines de los potenciometros
int Vector[] = {0, 0};//vector inicializado para guardar coordenadas X,Y
int Tamano[] = {83, 47};//vector que guarda los tamaños maximos de X,Y


void setup()   {
  Serial.begin(9600);

  display.begin();//inicializar
  
  display.setContrast(60);//arreglar el contraste

  display.clearDisplay();//limpiar patalla y buffer

}


void loop() {
  //  display.clearDisplay();   //limpiar patalla y buffer

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

