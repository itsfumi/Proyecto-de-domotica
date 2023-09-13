#include <DHT.h>

#define DHTPIN 2       // what pin we're connected to
#define DHTTYPE DHT22  // DHT22
DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT sensor for normal 16mhz Arduino

float hum;   //Stores humidity value
float temp;  //Stores temperature value

void setup() {
  Serial.begin(9600);

}

void loop() {
  float converted = 0.00;
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
}
