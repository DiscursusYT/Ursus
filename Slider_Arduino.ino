#include <AccelStepper.h>
AccelStepper stepper(1, 3, 4);
  

  int motorSpeedCoar;
  int motorSpeedFine;
  int pulsesFine;
  int pulsesCoar;
  int pulsesTotal;
  int pulses;
  int plus = 1;
  int minus = -1;
  int direc = 1;

 const int buttonPin1 = 6;
  int buttonState1 = 0;
 const int buttonPin2 = 7;
  int buttonState2 = 0;
 const int switchPin1 = 8;
  int switchState1 = 1;
 const int switchPin2 = 9;
  int switchState2 = 1;


void setup() 
{
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);

  stepper.setMaxSpeed(2000);
  stepper.setSpeed(100);
  
  stepper.setAcceleration(10);  
}

void loop() 
{
  //Read ButtonStates
     buttonState1 = digitalRead(buttonPin1);
     buttonState2 = digitalRead(buttonPin2);
     switchState1 = digitalRead(switchPin1);
     switchState2 = digitalRead(switchPin2);


if (switchState2 == LOW) { //Mode 1 - Timelapse
  
  //Read Potentiometer values
int sensorReadingFine = analogRead(A0);
    motorSpeedFine = map(sensorReadingFine, 0, 1023, 0, 20);
    pulsesFine = (motorSpeedFine*20);
  
int sensorReadingCoar = analogRead(A5);
   motorSpeedCoar = map(sensorReadingCoar, 0, 1023, 0, 20);
   pulsesCoar = (motorSpeedCoar*100);

  pulsesTotal = pulsesFine + pulsesCoar;
  pulses = pulsesTotal * direc;

  if (pulsesTotal = 0) {
    stepper.stop();
    }

  if (buttonState1 == LOW) {
    direc = minus;
    }
  if (buttonState2 == LOW) {
    direc = plus;
    }
    
  stepper.setSpeed(pulses);
 stepper.run();
}


if (switchState1 == LOW) { //Mode 1 - Freehand
  
  int sensorReadingCoar = analogRead(A0);
   motorSpeedCoar = map(sensorReadingCoar, 0, 1023, -10, 10);
   pulsesCoar = (motorSpeedCoar*170);
   

   if (buttonState1 == LOW) {
    direc = minus;
    }
  if (buttonState2 == LOW) {
    direc = plus;
    }

    pulses = pulsesCoar * direc;
   
  stepper.setSpeed(pulses);  
 stepper.run();
 }



}








