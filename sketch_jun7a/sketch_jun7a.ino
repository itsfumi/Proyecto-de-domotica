int pulsadorPin = 14; // Variable que guarda el número del pin al que conectamos el pulsador.
int valorPulsador = 0; // Variable donde almacenaremos la lectura del estado del pulsador.
 
void setup() {
  Serial.begin(9600); // Inicializamos el puerto serie.
  pinMode(14, INPUT_PULLUP); 
  pinMode(7,OUTPUT);// Declaramos la variable inputPin como entrada y activamos su resistencia interna Pullup.
}
 
void loop(){
  valorPulsador = digitalRead(pulsadorPin);  // Lectura digital de pulsadorPin
  pinMode(7, HIGH);
 
  if (valorPulsador == HIGH) {
      Serial.println("Pulsado"); // Si detecta que pulsamos el pulsador imprime por el monitor serie "pulsado".
  }
  if (valorPulsador == HIGH) 
  else {
      Serial.println("No pulsado"); // En caso contrario imprime por el monitor serie "No pulsado".
  
  }
  delay(1000); // Espera un segundo al final del bucle
}