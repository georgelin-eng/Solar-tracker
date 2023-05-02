#include <Servo.h>
#include <math.h>
#define CALLIBRATION 20

int pos = 90;
int time = 0;
int difference = 0;

int light1;
int light2;

Servo servo;

void printData (int light1, int light2, int pos, int time);

void setup() {
  Serial.begin (9600);
  servo.attach (7);
}

void loop() {
  light1 = analogRead (A0);
  light2 = analogRead (A1) + CALLIBRATION;
  time = millis ();

  difference = light1 - light2;

  printData (light1, light2, pos, time);
  
  if (abs (difference) >= 15 ) {
    if (light1 > light2) {
      pos += 5;
      servo.write (pos);
    }
    
    if (light1 < light2) {
      pos -= 5;
      servo.write (pos);
    }

    if (pos > 180) {
      pos = 180;
    }

    if (pos < 0) {
      pos = 0;
    }

  }

  delay (30);

}

void printData (int light1, int light2, int pos, int time)
{
  Serial.print ( (String) "Light1: " + light1 + "\n");
  Serial.print ( (String) "Light2: " + light2 + "\n");
  Serial.print ( (String) "Position: " + pos + "\n");
  Serial.print ( (String) "Time: " + time + "\n\n");
}