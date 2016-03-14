#define FASTADC 1

// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif


int sensorPin = A0;
float lectura;
int voltaje;
unsigned long tiempom = 0 , aux = 0;

void setup() {

  #if FASTADC
  // asigna preescala en 4 (010)
  cbi(ADCSRA,ADPS2) ;
  sbi(ADCSRA,ADPS1) ;
  cbi(ADCSRA,ADPS0) ;
  #endif
  
  Serial.begin(9600);

}

void loop() {

  tiempom = micros(); //empieza a contar

  analogRead(sensorPin);

  aux = micros() - tiempom;//deja de contar micros

  Serial.print("Acumulado: ");//Imprime Microsegundos
  Serial.print(tiempom);
  
  Serial.print("\tMicros: ");//Imprime Microsegundos
  Serial.print(aux);

  lectura = analogRead(sensorPin);
  voltaje = medir(lectura);//funcion para medir voltaje

  Serial.print("\tvoltaje: ");
  Serial.println(voltaje);
}

int medir(int lectura){
  
  voltaje = map(lectura, 0, 1023, 0, 5);//(valor que recibo, de Mínimo, de Máximo, a Mínimo, a Máximo)

  return voltaje;
  
}


