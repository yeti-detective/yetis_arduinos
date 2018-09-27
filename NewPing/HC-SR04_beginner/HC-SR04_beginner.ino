/*
 HC-SR04 Ping distance sensor:
 VCC to arduino 5v 
 GND to arduino GND
 Echo to Arduino pin 7 
 Trig to Arduino pin 8

 Red LED:
 Arduino pin 13 to 100 mA resistor to positive leg of LED
 Negative leg of LED to ground

 Green LED:
 Arduino pin 10 to 100 mA resistor to positive leg of LED
 Negative leg of LED to ground
 
 This sketch originates from Virtualmix: http://goo.gl/kJ8Gl
 Has been modified by Winkle ink here: http://winkleink.blogspot.com.au/2012/05/arduino-hc-sr04-ultrasonic-distance.html
 And modified further by ScottC here: http://arduinobasics.blogspot.com.au/2012/11/arduinobasics-hc-sr04-ultrasonic-sensor.html
 on 10 Nov 2012.
 
 This sketch was re-worked by Yeti Detective on 9/11/2016 to light a green LED
 when the sensor is not detecting an echo within the specified range and a red
 LED when it does detect an echo within the specified range
 
 */


#define echoPin 9 // Echo Pin
#define trigPin 8 // Trigger Pin
#define REDPin 10 // Red LED
#define GRNPin 13 // Green LED

int maximumRange = 10; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(REDPin, OUTPUT); // Use LED indicator (if required)
 pinMode(GRNPin, OUTPUT); // Green LED, yo
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 Serial.println("-1");
 digitalWrite(REDPin, HIGH);
 digitalWrite(GRNPin, LOW);
 }
 else {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 Serial.println(distance);
 digitalWrite(REDPin, LOW);
 digitalWrite(GRNPin, HIGH); 
 }
 
 //Delay 50ms before next reading.
 delay(50);
}
