int book = 2;
int ledPin = 13;

void setup() {
  pinMode(book, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int state = digitalRead(book);

  if (state == LOW) {   
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  // digitalWrite(ledPin, HIGH);
}

