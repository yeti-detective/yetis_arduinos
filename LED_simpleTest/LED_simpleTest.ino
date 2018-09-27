/*
Wire output pin (13 in this sketch) to 10ma resistor
resistor to positive (long) leg of LED
negative leg of LED to ground
 */

void setup() {
  pinMode(13, OUTPUT);

}

void loop() {
  digitalWrite(13, HIGH);
  delayMicroseconds(750);
  digitalWrite(13, LOW);
  delayMicroseconds(750);
}
