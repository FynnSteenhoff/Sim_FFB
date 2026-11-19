unsigned long previousMillis = 0;
const long interval = 500;
bool state = false;

void setup() {
  // Optional: uncomment the line below to stop USB serial polling from touching the LEDs
  // USBCON &= ~(1 << USBE); // Warning: disables USB upload until you double-tap Reset
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    state = !state;
  }

  // Continuously enforce the state so USB interrupts can't override it for more than a few microseconds
  if (state) {
    RXLED0; // RX ON
    TXLED1; // TX OFF
  } else {
    RXLED1; // RX OFF
    TXLED0; // TX ON
  }
}
