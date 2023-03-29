#include "DHT.h"
#include "DHT_U.h"

int sensor = 32;
float temperatura;

DHT dht(sensor,DHT22);

int ventilador = 4;
int calefactor = 5;

void setup() {
  Serial.begin(115200);
  
  dht.begin();
  
  pinMode(sensor,INPUT);
  pinMode(ventilador,OUTPUT);
  pinMode(calefactor,OUTPUT);
}

void loop() {
  temperatura = dht.readTemperature();

  Serial.print("La temperatura es: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  if (temperatura >= 29.8){
    digitalWrite(calefactor, HIGH);
    digitalWrite(ventilador, LOW);
    Serial.println("Ventilador encendido");
  }
  if (temperatura <= 29.2){
    digitalWrite(ventilador, HIGH);
    digitalWrite(calefactor, LOW);
    Serial.println("Calefactor encendido");
  }
  delay(2000);
}
