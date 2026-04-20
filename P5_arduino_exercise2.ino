const int led1pin = 5;
int var;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int brightnessState;

  brightnessState=Serial.read();
  brightnessState=Serial.parseInt();
  brightnessState = constrain(brightnessState, 0, 255);
  if (Serial.available() >=0){
  analogWrite(led1pin, brightnessState);
  }
}
