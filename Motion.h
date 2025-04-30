#ifndef MOTION_H
#define MOTION_H
#include <Servo.h>

// Servo Objekte
extern Servo myServoLinksBein;
extern Servo myServoRechtsBein;
extern Servo myServoLinksFuss;
extern Servo myServoRechtsFuss;

// Servo Pins
extern const uint8_t ServoLinksBeinPin;
extern const uint8_t ServoRechtsBeinPin;
extern const uint8_t ServoLinksFussPin;
extern const uint8_t ServoRechtsFussPin;

// Positionen
extern int LB0, RB0, LB1, RB1;
extern int LBTL, RBTL, LBTR, RBTR;
extern int LFV, RFV, LFR, RFR;

// Bewegungsfunktionen
void SetWalk();
void SetRoll();
void Roll();
void DanceBreakdance();
void DanceHeadbang();
void DanceSmooth();
void DanceMoonwalk();
void WalkVorwaerts();
void WalkStop();
void myServoBeinDetach();

#endif
