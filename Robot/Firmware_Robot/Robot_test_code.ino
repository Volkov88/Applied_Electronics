#include <AccelStepper.h>

#define FULLSTEP 4

AccelStepper myStepper_right(FULLSTEP, 2, 3, 4, 5);
AccelStepper myStepper_left(FULLSTEP, 6, 7, 8, 9);

const int ir = A2;
const int ir2 = A3;

void setup() {
  Serial.begin(115200);
  myStepper_left.setPinsInverted (false,true,true);
}

void loop() {
   int r = analogRead(ir);
   int l = analogRead(ir2);
   Serial.println(r);
//   Serial.println(l);

   if ((r > 500) && (l > 500)) {
//    Serial.println("FORWARD");   
    myStepper_left.setMaxSpeed(1000);
    myStepper_left.setSpeed(70);
    myStepper_left.runSpeed();
    myStepper_right.setMaxSpeed(1000);
    myStepper_right.setSpeed(70);
    myStepper_right.runSpeed();
    }

   if ((r < 500) && (l > 500)) {
//    Serial.println("TURN RIGHT");
    myStepper_left.setMaxSpeed(1000);
    myStepper_left.setSpeed(70);
    myStepper_left.runSpeed();
    myStepper_right.stop();
   }
   if ((l < 500) && (r > 500)) {
//    Serial.println("TURN LEFT");
    myStepper_right.setMaxSpeed(1000);
    myStepper_right.setSpeed(70);
    myStepper_right.runSpeed();
    myStepper_left.stop();
   }

    if ((r < 500) && (l < 500)) {
//    Serial.println("STOP"); 
    myStepper_left.stop();
    myStepper_right.stop();
    delay(300);
   }
}

   
