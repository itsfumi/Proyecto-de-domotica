
 
#include <DHT.h>
//////////////// final de carrera
///////////////////////
//Constants
#define DHTPIN 3       // what pin we're connected to
#define DHTTYPE DHT22  // DHT22
DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT sensor for normal 16mhz Arduino

float hum;   //Stores humidity value
float temp;  //Stores temperature value

void setup() {
  Serial.begin(9600);
  Serial.println("DHT22 sensor testing");
  pinMode(2, OUTPUT);
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
 if (temp >= 21) {
    digitalWrite(2, LOW);  // turn the LED on (HIGH is the voltage level)
    delay(1000);
  }
  if (hum >= 80) {
    digitalWrite(4, LOW);  // turn the LED on (HIGH is the voltage level)
    delay(1000);
  } else {
    digitalWrite(2, HIGH);  // turn the LED off by making the voltage LOW
    delay(1000);
    digitalWrite(4, HIGH);  // turn the LED off by making the voltage LOW
    delay(1000);
  }


}
