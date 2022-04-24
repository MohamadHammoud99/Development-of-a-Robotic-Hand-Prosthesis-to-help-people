# Development-of-a-Robotic-Hand-Prosthesis-to-help-people

- Workshop Project

- Team of 6 students

•	The framework of this project is the study of robotic prostheses to restore or increase the autonomy of people with a physical disability (loss or reduction of motor skills in a limb such as an arm, hand, leg, etc.).

•	We started with the bibliography in order to understand all the ins and outs of the project and to be able to frame our study in a precise direction.

•	Then, the robotic hand we took is composed of five mobile fingers controlled by servo-motors (5-7V) and is controllable by Arduino.

•	We are divided into three teams:
  1.	The first team is responsible for controlling the servomotors of the hand prostheses using Arduino Mega and improving the design of the robotic hand.
  2.	The second team aims to study the acquisition of EMG signals (using EMG sensors and Arduino) in order to then control the hand prosthesis.
  3.	The latest team is working to provide a simple pressure visualization system so that the user can easily see the level of pressure being applied when holding the device.

•	My work was in the second team, I was responsible for acquiring the EMG signals using the EMG sensors and the Arduino Mega:
  o	First, after some reading of the state of the art and then choosing the EMG method, I started by studying the MyoWare EMG kit and testing their components.
  o	Then, I studied two cases according to the position of the EMG sensor on the hand: forearm and biceps. This was done by reading the sensor values from the Arduino as a function of several selected hand movements (we took 5 movements and 3 pulses in our study, depending on the type and force level of the movement).
  o	After that, I try to differentiate the movements by using 3 LEDs and a servo motor. So, for example, if there is no force, there is no LED light, for a small force or finger movements, one LED lights up, and so on...
  o	Finally, and after several tests with many conditions, I succeeded in differentiating 4 levels of forces (4 thresholds in the acquired values of the sensors (no LED, 1 LED, 2 LED, 3 LED and an angle on the servomotor is made)	

•	In the last part of the project, we merged the work of the first and second team and try to make certain gestures, for example closing the robotic hand when I close my hand and opening it when I open mine. 

•	All the tests of my work were photographed, especially the last result (Videos).

Due to time constraints, we were not able to go further in the project, so we made a technical report to give to the group that will come after us to make more and more improvements.

•	Output of the project: 
  -	Videos (final, trials, …)
  -	Arduino Codes
  -	Report


•	Skills token from this project:
  -	Arduino
  -	EMG sensors (EMG MyoWare Kit)
  -	State of the art of the project

![image](https://user-images.githubusercontent.com/85926752/164971544-174d2cf4-fb11-415e-808d-337841699f75.png)
![image](https://user-images.githubusercontent.com/85926752/164971558-b99c83b7-e5a7-4d16-a73f-33a7a982d310.png)
![image](https://user-images.githubusercontent.com/85926752/164971565-a9aecf3c-7c55-45b0-b2c7-cfe9ab5dcbba.png)


https://user-images.githubusercontent.com/85926752/164972312-23cba7ed-f2b3-4c1d-8d7f-abd14508a87f.mp4


https://user-images.githubusercontent.com/85926752/164972221-7c7d4d98-c7fe-43a6-b77b-390cc2af6c31.mp4

