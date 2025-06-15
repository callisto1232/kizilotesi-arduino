#define IR_RECEIVE_PIN 9      // IR receiver connected to pin 9
#include <IRremote.hpp>

const int ledPin = 3;          // LED connected to pin 3

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Initialize IR receiver on pin 9 with LED feedback enabled
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {
    // IR signal received - turn LED on
    digitalWrite(ledPin, HIGH);

    // Process received IR data here if needed, e.g.:
    // uint16_t command = IrReceiver.decodedIRData.command;
    // Serial.println(command);

    IrReceiver.resume();  // Receive next IR signal
  } else {
    // No IR signal detected - turn LED off
    digitalWrite(ledPin, LOW);
  }
}
