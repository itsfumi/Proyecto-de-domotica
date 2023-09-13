const int buttonPin = 7;  // Pin del pulsador

#define IN1 4

#define IN2 2

int buttonState = 0;      // Estado actual del pulsador
int lastButtonState = 0;  // Estado anterior del pulsador


bool statusSpin = 0;

bool statusButton = 0;

void setup() {

  pinMode(buttonPin, INPUT_PULLUP);     // Pin del pulsador como entrada

  pinMode(IN1,OUTPUT);

  pinMode(IN2,OUTPUT);
  Serial.begin(9600);

      digitalWrite(IN2,LOW);
    digitalWrite(IN1,LOW);
}

void giroIZQ(int tiempo){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    delay(tiempo);
}

void giroDER(int tiempo){
    digitalWrite(IN2,HIGH);
    digitalWrite(IN1,LOW);
    delay(tiempo);
}

void paro (int tiempo){
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,LOW);
    delay(tiempo);
}


bool bandera=0;

void loop() {

  
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);

 if (buttonState==1) {
   Serial.println("paro");
    paro(1000);
        digitalWrite(IN2,LOW);
    digitalWrite(IN1,LOW);
 }
  else{
    if (bandera){
      giroDER(2000);
      Serial.println("DER");

      bandera=0;
    }
    else{
      giroIZQ(2000);
        Serial.println("IZQ");
      bandera=1;
    }
    } 
 }
      // if(statusButton==HIGH){

  //   statusSpin = !statusSpin;

  // }

  

  // if(statusSpin == 1){

  //   digitalWrite(IN1,HIGH);

  //   digitalWrite(IN2,LOW);

  // } else {

  //   digitalWrite(IN1,LOW);

  //   digitalWrite(IN2,HIGH);

  // }



  // delay(150);


