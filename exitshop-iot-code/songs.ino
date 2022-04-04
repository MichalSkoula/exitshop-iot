
// super mario ----------------------------------------------------------------------------------
// https://github.com/robsoncouto/arduino-songs/blob/master/supermariobros/supermariobros.ino
int notes_mario[] = {
    NOTE_E4, NOTE_E4, REST, NOTE_E4, 
    REST, NOTE_C4, NOTE_E4, REST,
    NOTE_G4, REST, REST, NOTE_G3, REST,
    NOTE_C4, REST, REST, NOTE_G3,
    REST, NOTE_E3, REST,
    REST, NOTE_A3, REST, NOTE_B3,   
    REST, NOTE_AS3, NOTE_A3, REST,
    NOTE_G3, NOTE_E4, NOTE_G4,
    NOTE_A4, REST, NOTE_F4, NOTE_G4, 
    REST, NOTE_E4, REST, NOTE_C4, 
    NOTE_D4, NOTE_B3, REST
};
int duration_mario[] = {
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 2, 4, 2, 2,
    4, 4, 4, 4,
    2, 4, 4,
    4, 4, 4, 4,  
    4, 4, 4, 4,
    4, 2, 4,
    4, 4, 4, 4,
    4, 4, 4, 4, 
    4, 4, 2
};
int length_mario = (sizeof(notes_mario)/sizeof(int));
void playSuperMarioMelody() {
  for (int thisNote = 0; thisNote < length_mario; thisNote++) {
    int noteDuration = 500/duration_mario[thisNote];
    tone(buzzer, notes_mario[thisNote], noteDuration);
    
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzer);
  }
}

// take on me -------------------------------------------------------------------------------------
// https://create.arduino.cc/projecthub/GeneralSpud/passive-buzzer-song-take-on-me-by-a-ha-0f04a8
int notes_takeonme[] = {
  NOTE_FS5, NOTE_FS5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_E5, 
  NOTE_E5, NOTE_E5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5, 
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_E5, NOTE_D5, NOTE_FS5, 
  NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5
};
int duration_takeonme[] = {
  8, 8, 8, 4, 4, 4, 
  4, 5, 8, 8, 8, 8, 
  8, 8, 8, 4, 4, 4, 
  4, 5, 8, 8, 8, 8
};
int length_takeonme = (sizeof(notes_takeonme)/sizeof(int));
void playTakeOnMeMelody() {
  for (int thisNote = 0; thisNote < length_takeonme; thisNote++) {
    int noteDuration = 1000/duration_takeonme[thisNote];
    tone(buzzer, notes_takeonme[thisNote], noteDuration);
    
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzer);
  }
}

// star wars -----------------------------------------------------------------------------------
// https://github.com/robsoncouto/arduino-songs/blob/master/imperialmarch/imperialmarch.ino
int melody_starwars[] = {
  NOTE_A4,4, NOTE_A4,4, NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16,
  NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,//4
  NOTE_E5,4, NOTE_E5,4, NOTE_E5,4, NOTE_F5,-8, NOTE_C5,16,
  NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
};
int length_starwars = sizeof(melody_starwars) / sizeof(melody_starwars[0]) / 2;
void playStarWarsMelody() {
  int tempo = 120;
  int wholenote = (60000 * 4) / tempo;
  int divider = 0, noteDuration = 0;

  for (int thisNote = 0; thisNote < length_starwars * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody_starwars[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody_starwars[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}

// lion sleeps ------------------------------------------------------------------------
// https://github.com/robsoncouto/arduino-songs/blob/master/thelionsleepstonight/thelionsleepstonight.ino
int melody_lion[] = {
  NOTE_F4, 4, NOTE_G4, 4, NOTE_A4, 8, NOTE_G4, 4, NOTE_A4, 8, //1
  NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 8, NOTE_F4, 4, NOTE_G4, 8,
  NOTE_A4, 4, NOTE_C4, 8, NOTE_C4, 4, NOTE_C4, 8, NOTE_C4, 4,
  NOTE_C4, 1, //1st ending
};
int length_lion = sizeof(melody_lion) / sizeof(melody_lion[0]) / 2;
void playLionMelody() {
    int tempo = 122;
  int wholenote = (60000 * 4) / tempo;
  int divider = 0, noteDuration = 0;

  for (int thisNote = 0; thisNote < length_lion * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody_lion[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody_lion[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}

// doom -----------------------------------------------------------------------------------------
// https://github.com/robsoncouto/arduino-songs/blob/master/doom/doom.ino
int melody_doom[] = {
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //1
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, -2,
};
int length_doom = sizeof(melody_doom) / sizeof(melody_doom[0]) / 2;
void playDoomMelody() {
  int tempo = 225;
  int wholenote = (60000 * 4) / tempo;
  int divider = 0, noteDuration = 0;

  for (int thisNote = 0; thisNote < length_doom * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody_doom[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody_doom[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}
