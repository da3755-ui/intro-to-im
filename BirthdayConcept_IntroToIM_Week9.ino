const int led1Pin=3;
const int led2Pin=8;
const int led3Pin=13;
const int buttonPin= 5;
int photocellPin = analogRead(A2);
int ldrVal=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(photocellPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int state = digitalRead(buttonPin);
  int led1State = digitalRead(led1Pin);
  int led2State = digitalRead(led2Pin);
  int led3State = digitalRead(led3Pin);
  int brightnessState = analogRead(photocellPin);
  Serial.println(brightnessState);
  delay(100);


if (state == LOW) {   // if the button is pressed, the leds/candles will light up one after the other
  digitalWrite(led1Pin, HIGH);
  delay(2000);
  digitalWrite(led2Pin, HIGH);
  delay(2000);
  digitalWrite(led3Pin, HIGH);
  delay(2000);
}

if (brightnessState>440){ //if i blow on the "candles", they should turn off
  digitalWrite(led1Pin, LOW);
  delay(2000);
  digitalWrite(led2Pin, LOW);
  delay(2000);
  digitalWrite(led3Pin, LOW);
  delay(2000);
}
}