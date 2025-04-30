#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>
#include "Sounds.h"
#include "Eyes.h"
#include "Motion.h"
#include "BluetoothControl.h"
#include "JoystickMotion.h"


// ---------- Setup Module ----------
const int tasterPin = 11; 
const int voltagePin = A2;
const float referenzSpannung = 4.8;  //gemessen
const float schwelleAkkuLeer = 3.5;
bool akkuLeer = false; 
unsigned long letzteMessung = 0;
const unsigned long messIntervall = 1000;
// Taster
enum Mode { Gehen, Rollen };
Mode currentMode = Gehen;
unsigned long lastButtonPressTime = 0;
unsigned long lastDebounceTime = 0;
const int debounceDelay = 50;
int lastButtonReading = LOW;
int stableButtonState = LOW;
bool buttonIsPressed = false;
bool longPressDetected = false;
unsigned long buttonDownTime = 0;
const int Long_Press_Time = 1000;
int buttonPressCount = 0;
bool singleClickPending = false;


void setup() {
initEyes();
eyesSleepy();
initBluetooth();
pinMode(tasterPin, INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
  String btMessage = receiveBluetoothMessage();

  if (btMessage.length() > 0) {
    btMessage.trim();
    Serial.print("BT empfangen: ");
    Serial.println(btMessage);

    if (btMessage == "FORWARD") {
      Serial.println("→ Bewegung: VORWÄRTS");
      JoystickVorwaerts();
    } else if (btMessage == "BACKWARD") {
      Serial.println("→ Bewegung: RÜCKWÄRTS");
      JoystickRueckwaerts();
    } else if (btMessage == "LEFT") {
      Serial.println("→ Bewegung: LINKS");
      JoystickLinks();
    } else if (btMessage == "RIGHT") {
      Serial.println("→ Bewegung: RECHTS");
      JoystickRechts();
    } else if (btMessage == "STOP") {
      Serial.println("→ Bewegung: STOP");
      JoystickStop();
    } else if (btMessage == "MODE_SWITCH") {
      Serial.println("→ Moduswechsel empfangen");
      toggleMode();
    } else {
      Serial.print("❓ Unbekannter Befehl: ");
      Serial.println(btMessage);
    }
  }

  // ----- Spannung prüfen mit HYSTERESE -----
  unsigned long jetzt = millis();
  if (jetzt - letzteMessung >= messIntervall) {
    letzteMessung = jetzt;

    int rawVoltage = analogRead(voltagePin);
    float spannung = (rawVoltage / 1023.0) * referenzSpannung;

    if (!akkuLeer && spannung < 3.5) {
      akkuLeer = true;
      eyesSad();
      playSadWhistle();
    } else if (akkuLeer && spannung > 3.6) {
      akkuLeer = false;
      eyesSleepy();
    }
  }

  // ----- Tasterverarbeitung --------
  int rawButton = digitalRead(tasterPin);
  unsigned long now = millis();

  if (rawButton != lastButtonReading) {
    lastDebounceTime = now;
  }

  if ((now - lastDebounceTime) > debounceDelay) {
    if (rawButton != stableButtonState) {
      stableButtonState = rawButton;

      if (stableButtonState == HIGH) {
        buttonDownTime = now;
        longPressDetected = false;
      } else if (stableButtonState == LOW) {
        if (!longPressDetected) {
          buttonPressCount++;
          if (buttonPressCount == 1) {
            lastButtonPressTime = now;
            singleClickPending = true;
          } else if (buttonPressCount == 2) {
            toggleMode();
            if (currentMode == Gehen) {
              playSwitch();
              eyesEyes();
              SetWalk();
              delay(1000);
            } else {
              playSwitch();
              eyesHappy();
              SetRoll();
              delay(1000);
            }
            eyesSleepy();
            buttonPressCount = 0;
            singleClickPending = false;
          }
        }
      }
    }

    if (stableButtonState == HIGH && !longPressDetected && (now - buttonDownTime > Long_Press_Time)) {
      longPressDetected = true;
      eyesLove();
      playLoveWhistle();
      DanceSmooth();
      DanceBreakdance();
      DanceMoonwalk();
      eyesAngry();
      playAngryWhistle();
      DanceHeadbang();
      eyesDizzy();
      delay(2000);
      eyesSleepy();
      buttonPressCount = 0;
      singleClickPending = false;
    }
  }

  if (singleClickPending && (now - lastButtonPressTime > 400)) {
    if (buttonPressCount == 1) {
      if (currentMode == Gehen) {
        eyesEyes();
        WalkVorwaerts();
        WalkVorwaerts();
        WalkVorwaerts();
        WalkVorwaerts();
        WalkStop();
      } else {
        eyesHappy();
        Roll();
      }
      eyesSleepy();
    }
    buttonPressCount = 0;
    singleClickPending = false;
  }

  lastButtonReading = rawButton;
}

// -------- Modus Switch ------------

void toggleMode() {
  currentMode = (currentMode == Gehen) ? Rollen : Gehen;
  Serial.print("Neuer Modus: ");
  Serial.println(currentMode == Gehen ? "GEHEN" : "ROLLEN");
}

// -------- Bewegungsfunktion --------

void Home() {
  myServoLinksFuss.write(90);
  myServoRechtsFuss.write(90);
  myServoLinksBein.write(LB0);
  myServoRechtsBein.write(RB0);
  delay(400);
  myServoLinksFuss.detach();
  myServoRechtsFuss.detach();
  myServoLinksBein.detach();
  myServoRechtsBein.detach();
}
