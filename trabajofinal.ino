#define relemotor 5
#define Trigger 35
#define Echo 37
#define in1 23
#define in2 25
bool bandera=true;
// include the library code:
#include <LiquidCrystal.h>
#include <Wire.h> 
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 13, en = 12, d4 = 10, d5 = 11, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include "DHT.h"
/*Definimos que el Pin de Datos del sensor estará conectado al pin 2 del Arduino UNO*/
#define DHTPIN  3        
/*Definimos que el tipo de sensor que estamos utilizando es un DHT11*/
#define DHTTYPE DHT22     // DHT 11
/*Se actualizan algunos parámetros del DHT11 con los puntos definidos anteriormente*/ 
DHT dht(DHTPIN, DHTTYPE);

float hum;   //Stores humidity value
float temp;  //Stores temperature value

void setup() {
      Serial.begin(9600);
pinMode(Trigger, OUTPUT); 
pinMode(Echo, INPUT);  
pinMode(relemotor, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
pinMode(6, OUTPUT);
 Serial.println("Medición inciada");
  Serial.println("DHT22 Encendido");
  /*Iniciamos nuestro sensor DHT11 y agregamos un retardo de 1 segundo*/
  dht.begin();
  delay(1000);
   /*Iniciamos nuestra pantalla LCD*/

  lcd.begin(16, 2);
   

}

void loop() {
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(200);
  
if (d<20){
 girohor(5000);
 delay(100);
 giroanti(5000);
}
else{
 PARO(100);
}
    hum = dht.readHumidity();
  temp = dht.readTemperature();
  float a = dht.readHumidity();
  float b = dht.readTemperature();
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("Temp");
  lcd.setCursor(0,1); 
  lcd.print("Hum");
  lcd.setCursor(11,0); 
  lcd.print(b);
  lcd.setCursor(11,1); 
  lcd.print(a);   
  delay(2000);
  Serial.print("Temperatura registrada: ");
  Serial.print(b);
  Serial.println("°C");
  Serial.print("Humedad registrada: ");
  Serial.print(a);
  Serial.println("%");
  Serial.println("-----------------------------------------");
  delay(1000);
  if (temp < 26) {
    delay(1000);
digitalWrite(4, HIGH);
  delay(1000);
} else {
digitalWrite(4, LOW);
delay(1000);
}

}




void girohor(int tiempo){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    Serial.println("giro horario");
    delay(tiempo);
  //  digitalWrite(relemotor, HIGH);
   // delay(tiempo);  
}
void giroanti(int tiempo){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  Serial.println("giro antihorario");
  delay(tiempo);
}
void PARO(int tiempo){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    Serial.println("PARO");
    delay(tiempo);
  //  digitalWrite(6, HIGH); 
  //  delay(tiempo);  
}