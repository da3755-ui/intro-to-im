const int changePoses = 5;
const int buzzer = 8;

void setup() {
  Serial.begin(9600);
  pinMode(changePoses, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
}
void loop() {
  int songStatus = digitalRead(changePoses);

  Serial.println(songStatus);

  delay(100);

  if (Serial.available()) {
    digitalWrite(LED_BUILTIN, HIGH); // led on while receiving data

    int warning = Serial.parseInt();
  
    if (Serial.read() == '\n') {
      digitalWrite(buzzer, warning);
 
  }
  digitalWrite(LED_BUILTIN, LOW);
}
}