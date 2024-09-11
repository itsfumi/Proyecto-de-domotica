
#define Trigger1 2
#define Echo1 3
#define Trigger2 4 
#define Echo2 5
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10
#define nose 6


  long t1; //timepo que demora en llegar el eco
  long d1; //distancia en centimetros
 long t2; //timepo que demora en llegar el eco
  long d2; //distancia en centimetros
void setup() {
      Serial.begin(9600);
  pinMode (Trigger1, OUTPUT);
  pinMode (Echo1, INPUT); 
  pinMode (Trigger2, OUTPUT);
  pinMode (Echo2, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode (nose, INPUT);
}

void loop() {
        Serial.begin(9600);

  digitalWrite(Trigger1, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger1, LOW);
  
  t1 = pulseIn(Echo1, HIGH); //obtenemos el ancho del pulso
  d1 = t1/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia giroantih: ");
  Serial.print(d1);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(10);
  // ///////////////////////////////
 

  digitalWrite(Trigger2, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger2, LOW);
  
  t2 = pulseIn(Echo2, HIGH); //obtenemos el ancho del pulso
  d2 = t2/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia atras: ");
  Serial.print(d2);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(10);

  if (d1<60){
    enfrente (1000);
Serial.println("frente");
  }
  
  else if (d2<60){
    atras (1000);
    Serial.println("atras");

  }
    
  else {
      giroantih(1000);
      Serial.println("giro");

    }
  if (digitalRead(nose) ){
    // giroantih(3000);
    // enfrente(3000);
    Paro(10000);
    Serial.println("fuera");

  }
}
void Paro(int tiempo){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("paro");
  delay(tiempo);
}
void enfrente(int tiempo){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    Serial.println("giro DER");
    delay(tiempo);
}
void giroantih(int tiempo){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    Serial.println("giroantih");
    delay(tiempo);
}
  void atras(int tiempo){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    Serial.println("giroantih");
    delay(tiempo);

}