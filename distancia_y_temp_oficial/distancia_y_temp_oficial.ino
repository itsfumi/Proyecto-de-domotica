#include <DHT.h>

//////////////// final de carrera
///////////////////////
//Constants
#define Trigger 37
#define Echo 35
#define DHTPIN 3     // what pin we're connected to
#define DHTTYPE  DHT22  // DHT22void setup() {
#define reletemp 2
  DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT sensor for normal 16mhz Arduino
float hum;   //Stores humidity value
float temp;  //Stores temperature value
  // put your setup code here, to run once:
void setup() {
    Serial.begin(9600);
    pinMode(reletemp, OUTPUT);

  dht.begin();

}


void loop() {
  //Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  temp = dht.readTemperature();
    Serial.print(temp);
  Serial.println(hum);
    digitalWrite(reletemp, HIGH);//Inicializamos el pin con 0
  Serial.print("Celsius = ");
  Serial.print(temp);
  //Print degree symbol
  Serial.write(176);
  Serial.println("C");
  Serial.print("Humidity =");
  Serial.println(hum);
delay(2000);
if (temp < 26) {
    delay(1000);
digitalWrite(4, HIGH);
  delay(1000);
} else {
digitalWrite(4, LOW);
delay(1000);
}


 // put your main code here, to run repeatedly:
  //////////////////////////////////////////////////////////////////////////////////// DISTANCIA
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
}
