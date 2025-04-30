#include "BluetoothControl.h"

SoftwareSerial BTSerial(9, 10); // RX, TX — HC-05 TX → Pin 10, RX → 11

void initBluetooth() {
  BTSerial.begin(9600);
}

String receiveBluetoothMessage() {
  static String message = "";

  while (BTSerial.available()) {
    char c = BTSerial.read();
    if (c == '\n') {
      String result = message;
      message = "";
      return result;
    } else {
      message += c;
    }
  }

  return ""; // Keine vollständige Nachricht empfangen
}
