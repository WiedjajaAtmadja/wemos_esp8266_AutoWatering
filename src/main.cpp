#include <Arduino.h>
#define PUMP_ON 0
#define PUMP_OFF 1

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D6, INPUT);
  digitalWrite(D7, PUMP_OFF);
}

void loop() {
  int val = analogRead(A0);
  Serial.printf("Soil Moisture: %d -> %d\n", val, digitalRead(D6));
  if (val > 400) {
    digitalWrite(D7, PUMP_ON);
  } else {
    digitalWrite(D7, PUMP_OFF);
  }

  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(900);
}
