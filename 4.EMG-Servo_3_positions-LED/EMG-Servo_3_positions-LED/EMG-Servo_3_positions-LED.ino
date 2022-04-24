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

  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
  delay(200);        // delay in between reads for stability

  if ( voltage > 0.3) {
    digitalWrite(led, HIGH);
    myservo.write(180);      
    delay(1000);
  }
else{
  digitalWrite(led,LOW);
  myservo.write(0);      

}
     } 
