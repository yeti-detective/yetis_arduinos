unsigned long echo = 0;
int ultraSoundSignal = 4; // Ultrasound signal pin (receives echo from ping)
int ultraSoundTrigger = 9; // Pin to trigger ultrasonic ping
int ultraSoundValue = 0; // stores return value of echo

void setup(){
  Serial.begin(9600); // starts the serial
  pinMode(ultraSoundSignal,OUTPUT); // sets the trigger pin as an output
  pinMode(ultraSoundTrigger, INPUT); // sets the signal pin as an input
}

void loop() {
  digitalWrite(ultraSoundTrigger, HIGH); 
  ultraSoundValue = analogRead(ultraSoundSignal);
  Serial.println(ultraSoundValue);
}

