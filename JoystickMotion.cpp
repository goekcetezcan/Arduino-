#include "JoystickMotion.h"
#include <Servo.h>
#include "JoystickMotion.h"
#include "Motion.h"    // <<< damit die Servos bekannt sind
#include <Servo.h>  
#include <Arduino.h>
#include <Arduino.h>
#include <Servo.h>

extern Servo myServoLinksBein;
extern Servo myServoRechtsBein;
extern Servo myServoLinksFuss;
extern Servo myServoRechtsFuss;



void JoystickVorwaerts() {
  myServoLinksBein.attach(2);
  myServoRechtsBein.attach(3);
  myServoLinksFuss.attach(4);
  myServoRechtsFuss.attach(5);

  myServoLinksBein.write(80);  // leicht nach vorne
  myServoRechtsBein.write(100); // leicht nach vorne
  myServoLinksFuss.write(90);
  myServoRechtsFuss.write(90);
}

void JoystickRueckwaerts() {
  myServoLinksBein.attach(2);
  myServoRechtsBein.attach(3);
  myServoLinksFuss.attach(4);
  myServoRechtsFuss.attach(5);

  myServoLinksBein.write(100);  // leicht nach hinten
  myServoRechtsBein.write(80);  // leicht nach hinten
  myServoLinksFuss.write(90);
  myServoRechtsFuss.write(90);

    delay(500); // gib den Servos 0,5 Sekunden Zeit

  myServoLinksBein.detach();
  myServoRechtsBein.detach();
  myServoLinksFuss.detach();
  myServoRechtsFuss.detach();
}

void JoystickLinks() {
  myServoLinksBein.attach(2);
  myServoRechtsBein.attach(3);
  myServoLinksFuss.attach(4);
  myServoRechtsFuss.attach(5);

  myServoLinksBein.write(100);  // linkes Bein zurück
  myServoRechtsBein.write(100); // rechtes Bein vor
  myServoLinksFuss.write(90);
  myServoRechtsFuss.write(90);

    delay(500); // gib den Servos 0,5 Sekunden Zeit

  myServoLinksBein.detach();
  myServoRechtsBein.detach();
  myServoLinksFuss.detach();
  myServoRechtsFuss.detach();
}

void JoystickRechts() {
  myServoLinksBein.attach(2);
  myServoRechtsBein.attach(3);
  myServoLinksFuss.attach(4);
  myServoRechtsFuss.attach(5);

  myServoLinksBein.write(80);  // linkes Bein vor
  myServoRechtsBein.write(80); // rechtes Bein zurück
  myServoLinksFuss.write(90);
  myServoRechtsFuss.write(90);

    delay(500); // gib den Servos 0,5 Sekunden Zeit

  myServoLinksBein.detach();
  myServoRechtsBein.detach();
  myServoLinksFuss.detach();
  myServoRechtsFuss.detach();
}

void JoystickStop() {
  myServoLinksBein.detach();
  myServoRechtsBein.detach();
  myServoLinksFuss.detach();
  myServoRechtsFuss.detach();

    delay(500); // gib den Servos 0,5 Sekunden Zeit

  myServoLinksBein.detach();
  myServoRechtsBein.detach();
  myServoLinksFuss.detach();
  myServoRechtsFuss.detach();
}
