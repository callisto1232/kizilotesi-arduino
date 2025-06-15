#define IR_SEND_PIN 6          // Define IR LED pin before including IRremote.hpp
#include <IRremote.hpp>

const int buttonPin = 10;      // Push button pin

int lastButtonState = HIGH;    // Store previous button state

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);   // Button input with internal pull-up resistor
  IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK);  // Initialize IR sender on pin 6 with LED feedback
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // Detect button press (HIGH to LOW transition)
  if (buttonState == LOW && lastButtonState == HIGH) {
    // Send NEC protocol IR command: address 0x00FF, command 0x01, 32 bits
    IrSender.sendNEC(0x00FF01, 32);

    delay(200);  // Debounce delay to avoid multiple sends
  }

  lastButtonState = buttonState;
}
