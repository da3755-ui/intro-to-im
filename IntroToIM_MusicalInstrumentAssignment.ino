#include "mainNotes.h"
int melody[]={
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4
};

int noteDurations[] = {

  1, 1, 1, 1, 1, 1, 1
};

int thisNote = 0;
const int potentiometerPin = A0;
const int pianoTile1 = 3;
const int pianoTile2 = 5;
const int pianoTile3 = 13;
const int buzzer = 8;
int tileOneState = HIGH;
int tileTwoState = HIGH;
int tileThreeState = HIGH;
int lastTileOneState = HIGH;
int lastTileTwoState = HIGH;
int lastTileThreeState = HIGH;



void setup() {
  // put your setup code here, to run once:
  pinMode(pianoTile1, INPUT_PULLUP);
  pinMode(pianoTile2, INPUT_PULLUP);
  pinMode(pianoTile3, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

    int tileOneState = digitalRead(pianoTile1);
    int tileTwoState = digitalRead(pianoTile2);
    int tileThreeState = digitalRead(pianoTile3);
    int potValue = analogRead(potentiometerPin);
    Serial.println(potValue);


    
    if(
      (tileOneState==LOW&&lastTileOneState==HIGH)||
      (tileTwoState==LOW&&lastTileTwoState==HIGH)||
      (tileThreeState==LOW&&lastTileThreeState==HIGH)){  //so the buzzer doesn't play multiple notes in one single step/low reading
            int originalNote = melody[thisNote];
            float factor = map(potValue, 0, 1023, 50, 200)/100.0; // mapped potentiometer values to 50, 200 and divided by 100 in order to switch the pitches within the same category so eg. A4 can become A3 since the A3 is 0.5*A4. multiply by 2 → one octave higher| multiply by 0.5 → one octave lower
            int finalNote = originalNote * factor; //multiplied the original note by the factor so it changes the pitch according to the potentiometer change
            thisNote++;
            if(thisNote>=7){
              thisNote=0;
            }
            int noteDuration = 1000 / noteDurations[thisNote];
            tone(8, finalNote, noteDuration); //play the specific note with the factored frequency
            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);
           }
              
        
    
      lastTileOneState = tileOneState;;
      lastTileTwoState = tileTwoState; 
      lastTileThreeState = tileThreeState;
      
}
