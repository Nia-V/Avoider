#include <NewPing.h>
#include "UltrasonicSensor.h"  // Include the UltrasonicSensor class

// Define the ultrasonic sensor pins
const uint8_t trigPin = 18;
const uint8_t echoPin = 19;
const unsigned int maxDistance = 400;  // Maximum distance supported by the sensor
int angle = 90;
int steve = 0;
int increment = 15;
int time;
int count;
UltrasonicSensor mySensor(trigPin, echoPin, maxDistance);

void setup() {
  Serial.begin(9600);
  mySensor.init();
}

void loop() {
  // Get the distance from the sensor


while (mySensor.isDistanceLessThanOrEqual(35)) {
    steve = 1;
  mySensor.myCar2.STOP();
    if (count%2==0){
    angle -= increment;  // Increment the angle
    }else{
      angle += increment;} 
    mySensor.myServo2.write(angle);
    if (angle >= 150 || angle <= 30) {
      increment = -increment;  // Reverse the direction at the limits
    }
  }
  while (!mySensor.isDistanceLessThanOrEqual(35)) {
    if (steve == 0) {
        mySensor.myCar2.Forwards(50);
      mySensor.myServo2.write(90);
      angle = 90;
    }
    if (steve == 1 && angle >= 95) {
time = map(angle, 95, 150, 500, 1500);
      mySensor.myCar2.Left(50);
      delay(time);
      steve = 0;
          count++;
      
    }
    if (steve == 1 && angle <= 85) {
time = map(angle, 85, 30, 500, 1500);
      mySensor.myCar2.Right(50);
      delay(time);
      steve = 0;
          count++;
    }
  }
}

