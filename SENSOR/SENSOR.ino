// Experiment of DHT22 digital temperature reader

//DHT11 Data line connected to Arduino digital IO 2

// Name:- M.Pugazhendi
// Date:-  19thAug2016
// Version:- V0.1
// e-mail:- muthuswamy.pugazhendi@gmail.com

//Libraries
#include <DHT.h>

//Constants
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT22

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino

//Variables
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup() 
{
  //Initialize serial port
  Serial.begin(9600);

  Serial.println("DHT22 sensor testing");
  pinMode (7, OUTPUT); 
  pinMode (8, OUTPUT);


  //Initialize the DHT sensor
  dht.begin();  
}

void loop() 
{ 
    float converted = 0.00;
    
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();

    Serial.print("Celsius = ");
    Serial.print(temp);
    //Print degree symbol
    Serial.write(176); 
    Serial.println("C");
Serial.print("Humidity =");
    Serial.println(hum);
    delay(2000);
if (temp>27){
  digitalWrite(7, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000); 

  
}
if (hum>80){
    digitalWrite(8, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000); 
}
else {
    digitalWrite(7, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);      
    digitalWrite(8, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);      
}
                     // wait for a secon                  // wait for a second
    
    //2000mS delay between reads

}