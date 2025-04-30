#include "Sounds.h"
#include <Arduino.h>

const int piezoPin = 13;

void playSwitch() {
  for (int freq = 500; freq <= 1200; freq += 10) {
    tone(piezoPin, freq);
    delay(5);
  }
  noTone(piezoPin);
}

void playAlertSound() {
  for (int i = 0; i < 3; i++) {
    tone(piezoPin, 1000, 100); delay(150);
    noTone(piezoPin); delay(50);
  }
}

void playAngryWhistle() {
  for (int i = 0; i < 6; i++) {
    tone(piezoPin, 400 + (i % 2) * 300);
    delay(100);
  }
  noTone(piezoPin);
  delay(100);
  tone(piezoPin, 200, 500); delay(500);
  noTone(piezoPin);
}

void playSadWhistle() {
  for (int freq = 1000; freq >= 400; freq -= 4) {
    tone(piezoPin, freq);
    delay(6);
  }
  noTone(piezoPin);
  delay(300);
  tone(piezoPin, 300, 400); delay(500);
  noTone(piezoPin);
}

void playLoveWhistle() {
  for (int freq = 600; freq <= 1000; freq += 3) {
    tone(piezoPin, freq);
    delay(5);
  }
  delay(100);
  noTone(piezoPin);
  for (int i = 0; i < 4; i++) {
    tone(piezoPin, 800); delay(80);
    tone(piezoPin, 1000); delay(80);
  }
  noTone(piezoPin);
  delay(200);
}

void playHappyWhistle() {
  for (int freq = 700; freq <= 1200; freq += 5) {
    tone(piezoPin, freq);
    delay(4);
  }
  delay(100);
  noTone(piezoPin);
  delay(200);
  for (int i = 0; i < 10; i++) {
    tone(piezoPin, 900 + (i % 2) * 100);
    delay(80);
  }
  noTone(piezoPin);
  delay(200);
  for (int freq = 1100; freq >= 600; freq -= 5) {
    tone(piezoPin, freq);
    delay(3);
  }
  noTone(piezoPin);
  delay(1000);
}
