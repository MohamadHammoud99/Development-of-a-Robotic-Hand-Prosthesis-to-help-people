#include <Servo.h>
Servo myservo;  // create servo object to control a servo

const int led = 7;

// the setup routine runs once when you press reset:
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
   pinMode(led, OUTPUT);
   
}

// the loop routine runs over and over again forever:
void loop() {
myservo.write(0);    digitalWrite(led, HIGH);             
  delay(10);
  digitalWrite(led, LOW);
  delay(2000);
  myservo.write(89);  digitalWrite(led, HIGH);   
  delay(10);
  digitalWrite(led, LOW);             
  delay(2000);
  myservo.write(179);   digitalWrite(led, HIGH);   
  delay(10);
  digitalWrite(led, LOW);           
  delay(2000);
  myservo.write(89);  digitalWrite(led, HIGH);    
  delay(10);
  digitalWrite(led, LOW);           
  delay(2000);
} 
