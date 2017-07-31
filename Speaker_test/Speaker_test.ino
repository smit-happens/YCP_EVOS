#include <Arduino.h>

/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 32

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

volatile byte state = false;

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void btnPress() {
  state = !state;
}

void setup() {
  //32 is pin the button is connected to
  pinMode(32, INPUT);
  attachInterrupt(digitalPinToInterrupt(32), btnPress, CHANGE);

  //status LED on pin 13
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); 
  
}

void loop() {
  // no need to repeat the melody.

  while(state) {
    // iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 8; thisNote++) {
  
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(35, melody[thisNote], noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(35);
    }
  }
  
}
