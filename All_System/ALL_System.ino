#include <Servo.h>
#include <String.h>
Servo Saservo;
Servo Sbservo;
Servo Scservo;
Servo Sdservo;
Servo Seservo;
int Aa = 160;  // default Position 90    160
int Ab = 140;  //50    140
int Ac = 150;  //50    150
int Ad = 130;  //40     130
int Ae = 150;  //40   150

String cmd = "";
bool cmdComplete = false;
int i=0; int j=0; int k=0; int l=0; int n=0;  

void single1();void single2();void single3();
void single4();void single5();
void openServo();
void closeServo();
void stopServo();
  //servo.read();     //Read the current angle of the servo
void setup()
{  
  Serial.begin(9600);  //Serial Baudrate
//  definition of digital pin - signal PWM
  Saservo.attach(6);   //1 thumb - sa  
  Sbservo.attach(7);  //2 index finger - sb
  Scservo.attach(8);  //3 middle finger - sc
  Sdservo.attach(9);  //4 ring finger - sd
  Seservo.attach(10);   //5 little finger - se
// initialisation of angle
  Saservo.write(Aa);   //thumb 90     
  Sbservo.write(Ab);   //index finger  50
  Scservo.write(Ac);   //middle finger 50
  Sdservo.write(Ad);   //ring finger 40
  Seservo.write(Ae);   //little finger 40     
}
      
void loop()
{     
  int sensorValue = analogRead(A0); // EMG signal
  Serial.println(sensorValue);
  delay(200);        // delay in between reads for stability
  
 // traitement de signal EMG
  if(sensorValue < 180) {
      openServo();
    }
  else{
      closeServo();
    }
      
 // communication UART
  while (Serial.available() > 0)  {
        char cmdChar = char(Serial.read());
        cmd += cmdChar ;
        delay(2);
        if (cmdChar == '\n'){
            cmdComplete = true ;
          }
    }
    
  // choix des commandes
  if (cmdComplete){
      Serial.println(cmd);
      posChoice();
      cmd = "";
      cmdComplete = false ;
    }
}

void stopServo()
{
  Serial.println("case stop!");
  Aa = Saservo.read();
  Ab = Sbservo.read();
  Ac = Scservo.read();
  Ad = Sdservo.read();
  Ae = Seservo.read();
  Saservo.write(Aa);   //thumb 
  Sbservo.write(Ab);   //index finger 
  Scservo.write(Ac);   //middle finger 
  Sdservo.write(Ad);   //ring finger 
  Seservo.write(Ae);   //little finger 
  cmd = " ";
}

void closeServo()
{
  Serial.println("case close!");
  i = Saservo.read();
  j = Sbservo.read();
  k = Scservo.read();
  l = Sdservo.read();
  n = Seservo.read();
  if (i>40 && j>60 && k>60 && l>50 && n>60){
      for(i=130,j=140,k=150,l=130,n=150;i>=30,j>=50,k>=50,l>=40,n>=50;i--,j--,k--,l--,n--){
          if (cmd != " "){
              Saservo.write(i);//thumb
              Sbservo.write(j);//index finger
              Scservo.write(k);//middle finger
              Sdservo.write(l);//ring finger
              Seservo.write(n);//little finger
              delay(10);
            }
        }
  }
  else{
      Serial.println("main deja fermee");
  }
}

void openServo()
{
  Serial.println("case close!");
  i = Saservo.read();
  j = Sbservo.read();
  k = Scservo.read();
  l = Sdservo.read();
  n = Seservo.read();
  if (i<120 && j<130 && k<140 && l<120 && n<140){
      for(i=30,j=50,k=50,l=40,n=50;i<=130,j<=140,k<=150,l<=130,n<=150;i++,j++,k++,l++,n++){ 
          if (cmd != "  "){
              Saservo.write(i);//thumb
              Sbservo.write(j);//index finger
              Scservo.write(k);//middle finger
              Sdservo.write(l);//ring finger
              Seservo.write(n);//little finger
              delay(10);
            }
      }
  }
  else {
    Serial.println("main deja ouverte");
  }
}
void single1()
{
  for(j=0; j<=1;j++){
      for(i = 30; i<=130;i++){
          Saservo.write(i);
          delay(10);
          }
      for(i = 130; i>=30;i--){
          Saservo.write(i);
          delay(10);
        } 
  }
}

void single2()
{
  for(j=0; j<=1;j++){
      for(i = 50; i<=140;i++){
          Sbservo.write(i);
          delay(10);
        }
      for(i = 140; i>=50;i--){
          Sbservo.write(i);
          delay(10);
        } 
    }
}

void single3()
{
  for(j=0; j<=1;j++){
      for(i = 50; i<=150;i++){
          Scservo.write(i);
          delay(10);
        }
      for(i = 150; i>=50;i--){
          Scservo.write(i);
          delay(10);
        } 
    }
}

void single4()
{
  for(j=0; j<=1;j++){
      for(i = 40; i<=130;i++){
          Sdservo.write(i);
          delay(10);
        }
      for(i = 130; i>=40;i--){
          Sdservo.write(i);
        delay(10);
        } 
    }
}

void single5()
{
  for(j=0; j<=3;j++){
      for(i =40; i<=160;i++){
          Seservo.write(i);
          delay(10);
        }
      for(i = 160; i>=40;i--){
          Seservo.write(i);
          delay(10);
        } 
    }
}
void posChoice()
{
  if (cmd == "open\n"){
      openServo();
    }
  else if (cmd == "close\n"){
      closeServo();
    }
    else if (cmd == "stop\n"){
      stopServo();
    }
    else if (cmd == "single1\n"){
      single1();
    }
    else if (cmd == "single2\n"){
      single2();
    }
    else if (cmd == "single3\n"){
      single3();
    }
    else if (cmd == "single4\n"){
      single4();
    }
    else if (cmd == "single5\n"){
      single5();
    }
    else{
      Serial.println("Hello, it is a wrong command !");
    }
    cmd = "";
}

 
