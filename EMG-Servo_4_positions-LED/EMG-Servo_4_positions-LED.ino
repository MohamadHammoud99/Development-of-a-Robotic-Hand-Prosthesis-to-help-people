
#include <Servo.h>
Servo myservo;  // create servo object to control a servo

const int led1 = 7;
const int led2 = 8;
const int led3 = 6;


// the setup routine runs once when you press reset:
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

  // read the input on analog pin 0:
  float sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  
  //float voltage = sensorValue * (5.0 / 1023.0);

float voltage = sensorValue;
  
  // print out the value you read:
  Serial.println(voltage);
  delay(300);        // delay in between reads for stability

  if ( voltage > 80 && voltage < 180) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    myservo.write(75);      
    delay(10);
  }
else if (voltage >= 180 && voltage < 450)
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  myservo.write(135);      
  delay(10);

}
else if (voltage >= 450)
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  myservo.write(179);
  delay(10);      

}
else {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  myservo.write(1); 
  delay(10);     
}
     } 
