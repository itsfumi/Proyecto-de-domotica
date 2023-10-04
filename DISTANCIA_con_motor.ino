#define relemotor 5
#define Trigger 37
#define Echo 35
bool bandera=true;
void setup() {
      Serial.begin(9600);

    pinMode(relemotor, OUTPUT);
    digitalWrite(relemotor, HIGH);
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

  if (d<5 and bandera){
    bandera=false;
    digitalWrite(relemotor, LOW);
    Serial.print("motor encendido");
    delay(2000);
    digitalWrite(relemotor, HIGH);
  }
}

