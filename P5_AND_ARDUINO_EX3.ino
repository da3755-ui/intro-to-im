int ledPin = 2;

void setup() {
  // Start serial communication so we can send data
  // over the USB connection to our p5js sketch
  Serial.begin(9600);

  // We'll use the builtin LED as a status output.
  // We can't use the serial monitor since the serial connection is
  // used to communicate to p5js and only one application on the computer
  // can use a serial port at once.
  pinMode(LED_BUILTIN, OUTPUT);

  // Outputs on these pins
  pinMode(ledPin, OUTPUT);

  // Blink them so we can check the wiring
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);



  // start the handshake
  while (Serial.available() <= 0) {
    digitalWrite(LED_BUILTIN, HIGH); // on/blink while waiting for serial data
    Serial.println("0"); // send a starting message
    delay(300);            // wait 1/3 second
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
  }
}

void loop() {
  // wait for data from p5 before doing something
  if (Serial.available()) {
    digitalWrite(LED_BUILTIN, HIGH); // led on while receiving data

    int bounce = Serial.parseInt();
  
    if (Serial.read() == '\n') {
      digitalWrite(ledPin, bounce);
 

    //   //SEND TO P5
     int pot = analogRead(A1);
     delay(5);
      Serial.println(pot);
    
    // }
  }
  digitalWrite(LED_BUILTIN, LOW);
}}