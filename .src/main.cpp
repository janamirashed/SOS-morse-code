#include <Arduino.h>

// SOS symbols: "... --- ..."

int timeUnit = 400; // one time unit in milliseconds

// The length of a dot is 1 time unit
int dotTime = timeUnit;

// A dash is 3 time units.
int dashTime = timeUnit * 3;

// The space between symbols (dots and dashes) of the same letter
// is 1 time unit.
int symbolSpaceTime = timeUnit;

// The space between letters is 3 time units.
int letterSpaceTime = timeUnit * 3;

// The space between words is 7 time units.
int wordSpaceTime = timeUnit * 7;

int ledPin = 8; // pin assigned to the LED positive.

void sMorseCode();
void oMorseCode();
void sosMorseCode();

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    sosMorseCode();
}


// S Morse Code Function (3 dots)
void sMorseCode() {
    for (int i = 0; i < 3; ++i) {
        digitalWrite(ledPin, HIGH);
        delay(dotTime);
        digitalWrite(ledPin, LOW);
        delay(symbolSpaceTime);
    }
}

// O Morse Code Function (3 dashes)
void oMorseCode() {
    for (int i = 0; i < 3; ++i) {
        digitalWrite(ledPin, HIGH);
        delay(dashTime);
        digitalWrite(ledPin, LOW);
        delay(symbolSpaceTime);
    }
}

// SOS sequence
void sosMorseCode() {
    sMorseCode();
    delay(letterSpaceTime - symbolSpaceTime);

    oMorseCode();
    delay(letterSpaceTime - symbolSpaceTime);

    sMorseCode();
    delay(wordSpaceTime - symbolSpaceTime);
}
