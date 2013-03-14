 /*
 * Programmer: Josh Deese
 * Date: March, 14, 2013
 * Purpose: Receive serial command 'F' or 'S' from iPhone via Bluetooth 4.0
 * Problems: Camera will not take picture until it decides it is focused if lens 
 *    is in af mode. There is no way of determining if the camera is focused, 
 *    even after the 5000ms of focus after an 'F' command.
 */
 
#include <SoftwareSerial.h>

SoftwareSerial bleShield(2, 3);

long previousMillis = 0; 
long interval = 1000;
int led = 13;
int focus = 4;
int shutter = 5;

void setup(){
  // set the data rate for the SoftwareSerial port
  bleShield.begin(19200);
  Serial.begin(19200);
  pinMode(focus, OUTPUT);
  pinMode(shutter, OUTPUT);  
}

void loop(){
  if(bleShield.available()) {
    char command;
    command = bleShield.read();
    if(command == 'F'){
      // Focus Camera
      digitalWrite(focus, HIGH);
      delay(5000);
      digitalWrite(focus, LOW);
    } else if(command == 'S'){
      // Take Picture
      digitalWrite(shutter, HIGH);
      delay(100);
      digitalWrite(shutter, LOW);
    }
  }
}
