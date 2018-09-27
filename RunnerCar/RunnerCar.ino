#define driveR 3 // right motor control
#define driveL 5 // left motor control
#define trig 8 // ultrasonic trigger pin
#define echo 9 // ultrasonic echo pin

int maxRange = 20; // Maximum sensor range
int minRange = 0; // Minimum sensor range
long duration, distance; // Duration used to calculate distance

void setup() {
  Serial.begin (9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(driveR, OUTPUT);
  pinMode(driveL, OUTPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delay(2);

  digitalWrite(trig, HIGH);
  delay(10);

  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);

  distance = duration/58.2;

  if (distance <= maxRange && distance > minRange) {
    Serial.println("in range");
    digitalWrite(driveR, HIGH);
    digitalWrite(driveL, HIGH);
  }
  else {
    Serial.println("not in range");
    digitalWrite(driveR, LOW);
    digitalWrite(driveL, LOW);
  }
}
