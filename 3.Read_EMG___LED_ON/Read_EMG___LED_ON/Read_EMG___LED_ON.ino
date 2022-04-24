const int led = 7;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(led, OUTPUT); // LED
}
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
 
  // print out the value you read:
  Serial.println(sensorValue);
  delay(200);        // delay in between reads for stability

if(sensorValue < 50) 
{
  digitalWrite(led, LOW);                      
         }
else {
  digitalWrite(led, HIGH);
}
  
  }
