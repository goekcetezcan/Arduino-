#include "Motion.h"
#include <Arduino.h>
#include <Servo.h>

Servo myServoLinksBein;
Servo myServoRechtsBein;
Servo myServoLinksFuss;
Servo myServoRechtsFuss;

const uint8_t ServoLinksBeinPin = 8;
const uint8_t ServoRechtsBeinPin = 4;
const uint8_t ServoLinksFussPin = 7;
const uint8_t ServoRechtsFussPin = 3;

int LB0 = 60;
int RB0 = 120;
int LB1 = 180;
int RB1 = 0;
int LBTL = LB0 + 40;
int RBTL = RB0 + 60;
int LBTR = LB0 - 60;
int RBTR = RB0 - 40;

int LFV = 20;
int RFV = 20;
int LFR = 20;
int RFR = 20;

// ------- Gehfunktion ----------

void SetWalk() {
  myServoLinksBein.attach(ServoLinksBeinPin);
  myServoRechtsBein.attach(ServoRechtsBeinPin);
  myServoLinksBein.write(LB0);
  myServoRechtsBein.write(RB0);
  delay(300);
  myServoBeinDetach();
}

void WalkVorwaerts() {
  myServoLinksBein.attach(ServoLinksBeinPin);
  myServoRechtsBein.attach(ServoRechtsBeinPin);
  myServoLinksBein.write(LBTR);
  myServoRechtsBein.write(RBTR);
  delay(300);

  myServoRechtsFuss.attach(ServoRechtsFussPin);
  myServoRechtsFuss.write(90 - RFV);
  delay(300);
  myServoRechtsFuss.detach();
  delay(100);

  myServoLinksBein.write(LBTL);
  myServoRechtsBein.write(RBTL);
  delay(300);

  myServoLinksFuss.attach(ServoLinksFussPin);
  myServoLinksFuss.write(90 + LFV);
  delay(300);
  myServoLinksFuss.detach();
  delay(100);
}

void WalkStop() {
  myServoLinksFuss.write(90);
  myServoRechtsFuss.write(90);
  myServoLinksBein.write(LB0);
  myServoRechtsBein.write(RB0);
}

void myServoBeinDetach() {
  myServoLinksBein.detach();
  myServoRechtsBein.detach();
}

// ------- Tanzfunktion ---------

void DanceBreakdance() { //auf einem Bein drehen
  myServoLinksBein.attach(ServoLinksBeinPin);
  myServoRechtsBein.attach(ServoRechtsBeinPin);
  myServoLinksFuss.attach(ServoLinksFussPin);     
  myServoRechtsFuss.attach(ServoRechtsFussPin);   

  myServoRechtsBein.write(RB0 + 40);
  myServoRechtsFuss.write(90);
  delay(200);

  int maxWinkel = LB0 + 40;
  if (maxWinkel > 180) maxWinkel = 180;
  myServoLinksBein.write(maxWinkel);
  delay(300);

  myServoLinksFuss.write(120);
  delay(3000);

  myServoLinksFuss.write(90);
  delay(300);

  myServoLinksBein.write(LB0);
  myServoLinksFuss.write(90);
  myServoRechtsBein.write(RB0);
  myServoRechtsFuss.write(90);
  delay(300);

  myServoLinksBein.detach();
  myServoRechtsBein.detach();
  myServoLinksFuss.detach();
  myServoRechtsFuss.detach();
  delay(100);
}

void DanceHeadbang() { //heftiges Kopfschütteln nach rechts und Links
  myServoLinksBein.attach(ServoLinksBeinPin);
  myServoRechtsBein.attach(ServoRechtsBeinPin);
  myServoLinksFuss.attach(ServoLinksFussPin);
  myServoRechtsFuss.attach(ServoRechtsFussPin);

  for (int i = 0; i < 8; i++) {
    myServoLinksBein.write(LB0 + 40);
    myServoRechtsBein.write(RB0 + 40);
    delay(150);
    myServoLinksBein.write(LB0 - 20);
    myServoRechtsBein.write(RB0 - 20);
    delay(150);
  }

  myServoLinksBein.write(LB0);
  myServoRechtsBein.write(RB0);
  myServoLinksFuss.write(90);
  myServoRechtsFuss.write(90);
  delay(300);

  myServoLinksBein.detach();
  myServoRechtsBein.detach();
  myServoLinksFuss.detach();
  myServoRechtsFuss.detach();
  delay(100);
}


void DanceSmooth() { //langsame bewegungen auf der stelle
  myServoLinksBein.attach(ServoLinksBeinPin);
  myServoRechtsBein.attach(ServoRechtsBeinPin);
  myServoLinksFuss.attach(ServoLinksFussPin);
  myServoRechtsFuss.attach(ServoRechtsFussPin);

  for (int i = 0; i < 5; i++) {
    myServoLinksFuss.write(60);
    myServoRechtsFuss.write(120);
    delay(200);
    myServoLinksFuss.write(120);
    myServoRechtsFuss.write(60);
    delay(200);
  }

  myServoLinksBein.write(LB0);
  myServoRechtsBein.write(RB0);
  myServoLinksFuss.write(90);
  myServoRechtsFuss.write(90);
  delay(300);

  myServoLinksBein.detach();
  myServoRechtsBein.detach();
  myServoLinksFuss.detach();
  myServoRechtsFuss.detach();
  delay(100);
}

void DanceMoonwalk() { //moonwalk
  myServoLinksBein.attach(ServoLinksBeinPin);
  myServoRechtsBein.attach(ServoRechtsBeinPin);
  myServoLinksFuss.attach(ServoLinksFussPin);
  myServoRechtsFuss.attach(ServoRechtsFussPin);

  myServoLinksFuss.write(60);
  myServoRechtsFuss.write(120);
  delay(200);

  for (int i = 0; i < 6; i++) {
    myServoLinksFuss.write(70 + (i % 2) * 20);
    myServoRechtsFuss.write(110 - (i % 2) * 20);
    delay(200);
  }

  myServoLinksBein.write(LB0);
  myServoRechtsBein.write(RB0);
  myServoLinksFuss.write(90);
  myServoRechtsFuss.write(90);
  delay(300);

  myServoLinksBein.detach();
  myServoRechtsBein.detach();
  myServoLinksFuss.detach();
  myServoRechtsFuss.detach();
  delay(100);
}


// ------- Rollfunktion ---------

void SetRoll(){
  myServoLinksBein.attach(ServoLinksBeinPin);
  myServoRechtsBein.attach(ServoRechtsBeinPin);   
  myServoLinksBein.write(180);
  myServoRechtsBein.write(0);
  delay(300);
  myServoBeinDetach(); 
}

void Roll(){
  myServoLinksBein.attach(ServoLinksBeinPin);
  myServoRechtsBein.attach(ServoRechtsBeinPin);
  myServoLinksFuss.attach(ServoLinksFussPin);     
  myServoRechtsFuss.attach(ServoRechtsFussPin);   
  myServoLinksBein.write(180);
  myServoRechtsBein.write(0);
  delay (300);
  myServoLinksFuss.write(120);
  myServoRechtsFuss.write(60);
  delay (3000);
  myServoLinksBein.detach();
  myServoRechtsBein.detach();
  myServoLinksFuss.detach();     
  myServoRechtsFuss.detach();   
}
