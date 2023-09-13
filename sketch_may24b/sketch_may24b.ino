const int Trigger = 7;   
const int Echo = 5;   
 
#include <DHT.h>
//////////////// final de carrera
///////////////////////
//Constants
#define DHTPIN 2       // what pin we're connected to
#define DHTTYPE DHT22  // DHT22
DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT sensor for normal 16mhz Arduino

float hum;   //Stores humidity value
float temp;  //Stores temperature value

void setup() {
  Serial.begin(9600);
  Serial.println("DHT22 sensor testing");
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode (Trigger, OUTPUT);
  pinMode (Echo, INPUT);
  pinMode (10, OUTPUT);
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
 pinMode (11, OUTPUT);

  //Initialize the DHT sensor
  dht.begin();
}

void loop()
{
    float converted = 0.00;

  //Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  temp = dht.readTemperature();

  Serial.print("Celsius = ");
  Serial.print(temp);
  //Print degree symbol
  Serial.write(176);
  Serial.println("C");
  Serial.print("Humidity =");
  Serial.println(hum);
  delay(2000);
 if (temp > 27) {
    digitalWrite(4, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(1000);
  }
  if (hum > 80) {
    digitalWrite(3, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(1000);
  } else {
    digitalWrite(4, LOW);  // turn the LED off by making the voltage LOW
    delay(1000);
    digitalWrite(3, LOW);  // turn the LED off by making the voltage LOW
    delay(1000);
  }
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
  delay(100);          //Hacemos una pausa de 100ms
  //////////////////////////////////////////////////////////////////////
  delay(2000);
  if (digitalRead(14)){
      digitalWrite(10, HIGH);
  }
   if (digitalRead (11)){
    digitalWrite(10, LOW);
    }

}
