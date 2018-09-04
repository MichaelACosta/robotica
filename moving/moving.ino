const int pwmY = 5; //Esquerda, Direita //Verde
const int pwmX = 6;  //Frente, Trans //Azul
char control;

 void setup() {
  pinMode(pwmY,OUTPUT);
  pinMode(pwmX, OUTPUT);    // Declara saidas PWM
  analogWrite(pwmY, 135);
  analogWrite(pwmX, 135);   // Mantem tensao no meio (inicia controle)
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    control = Serial.read();   // Read the incoming byte:

    switch (control) {
      case 'd':
        analogWrite(pwmY, 70);    // Passa valor para PWM (0 a 255)
        Serial.print("Esquerda \n");
        delay(500);
        control = 'p';
        break;
      case 'a':
        analogWrite(pwmY, 215);
        Serial.print("Direita \n");
        delay(500);
        control = 'p';
        break;
      case 'w':
        analogWrite(pwmX, 215);
        Serial.print("Frente \n");
        delay(500);
        control = 'p';
        break;
      case 's':
        analogWrite(pwmX, 70);
        Serial.print("Tras \n");
        delay(500);
        control = 'p';
        break;
      default:
        analogWrite(pwmY, 135);
        analogWrite(pwmX, 135);   // Mantem tensao no meio (inicia controle)
        Serial.print("Parado \n");
    }
    delay(1000);
  }
}
