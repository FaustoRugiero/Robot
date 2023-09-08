int ir_derecho = 7;
int ir_izquierdo = 6;
int echo = 4;
int trigger = 3;
int duracion;
int distancia;

void setup() {
  Serial.begin(9600);
  pinMode(ir_derecho, INPUT);
  pinMode(ir_izquierdo, INPUT);
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);

}

void loop() {
  int lectura_derecha = digitalRead(ir_derecho);
  int lectura_izquierda = digitalRead(ir_izquierdo);
      //Serial.println(lectura_derecha);
      //Serial.println(lectura_izquierda);
  if (lectura_derecha == 0) {
      Serial.println("Detecto derecha");
  }
  if (lectura_izquierda == 0) {
      Serial.println("Detecto izquierda");
  }
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duracion = pulseIn(echo, HIGH);

  // Distancia en cm
  int distancia = duracion * 0.34 / 2;

  Serial.println("Distancia: " + String(distancia));

  delay(1000);

}
