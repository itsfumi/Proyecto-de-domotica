// Definición de pines
const int sensorSonidoPin = 8;  // Pin analógico donde está conectado el sensor de sonido
const int ledPin =9 ;           // Pin del LED incorporado en la mayoría de placas Arduino

// Umbral para detectar el sonido (ajústalo según la sensibilidad del sensor)
const int umbralSonido = 1;

void setup() {
  // Inicialización de los pines
  pinMode(sensorSonidoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Inicialización del puerto serie para mensajes de depuración (opcional)
  Serial.begin(9600);
}

void loop() {
  // Lee el valor del sensor de sonido
  int valorSensor = digitalRead(sensorSonidoPin);
    Serial.println(valorSensor);

  // Enciende el LED si se detecta un sonido por encima del umbral
  if (valorSensor==0) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
    delay(50);
  }
}
