const int pwmY = 5;
const int pwmX = 6;
char control;

void setup() {
  pinMode(pwmY, OUTPUT);
  pinMode(pwmX, OUTPUT);
  analogWrite(pwmY, 135);
  analogWrite(pwmX, 135);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    control = Serial.read();

    switch (control) {
      case 'd':
        analogWrite(pwmX, 80);
        Serial.print("Direita \n");
        break;
      case 'a':
        analogWrite(pwmX, 190);
        Serial.print("Esquerda \n");
        break;
      case 'w':
        analogWrite(pwmY, 190);
        Serial.print("Frente \n");
        break;
      case 's':
        analogWrite(pwmY, 80);
        Serial.print("Tras \n");
        break;
      default:
        analogWrite(pwmY, 135);
        analogWrite(pwmX, 135);
        Serial.print("Parado \n");
        break;
    }
    delay(1000);
  }
}
