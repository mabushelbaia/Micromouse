#include <Arduino.h>
#include "Motor.h"

#define EN_A 2
#define EN_B 4
#define M1_FORWARD 16
#define M1_BACKWARD 17
#define M2_FORWARD 5
#define M2_BACKWARD 18

#define ENCODER1_A 34
#define ENCODER1_B 35
#define ENCODER2_A 32
#define ENCODER2_B 33

Motor motor1(EN_A, M1_FORWARD, M1_BACKWARD);
Motor motor2(EN_B, M2_FORWARD, M2_BACKWARD);

void setup() {
    Serial.begin(115200); // Init Serial at 115200 Baud Rate.
    Serial.println("Serial Working"); // Test to check if serial is working or not
    motor1.setSpeed(0.4);
    motor2.setSpeed(0.4);
    motor1.forward();
    motor2.forward();

}

void loop() {


    // put your main code here, to run repeatedly:


}
