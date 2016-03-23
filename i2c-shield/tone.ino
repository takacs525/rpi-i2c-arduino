
#include "tones.h"

// notes in the melody:
int melody[] = { NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4 };
int noteDurations[] = { 4, 8, 8, 4, 4, 4, 4, 4 };

void TonePlay() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(SPEAKER_PIN, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    noTone(SPEAKER_PIN);
  }
}

void ToneBeep() {
  tone(SPEAKER_PIN, NOTE_G3, 500);
  delay(600);
  noTone(SPEAKER_PIN);
}

void ToneCard() {
  tone(SPEAKER_PIN, NOTE_D6, 200);
  delay(250);
  tone(SPEAKER_PIN, NOTE_D6, 200);
  delay(250);
  noTone(SPEAKER_PIN);
}
