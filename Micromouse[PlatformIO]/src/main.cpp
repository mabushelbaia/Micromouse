#include <Arduino.h>
#include "Motor.h"

#define EN_A 2
#define EN_B 4
#define M1_FORWARD 17
#define M1_BACKWARD 16
#define M2_FORWARD 18
#define M2_BACKWARD 5

#define ENCODERA_R 33
#define ENCODERB_R 32
#define ENCODERA_L 34
#define ENCODERB_L 35

volatile long encoderCount_R = 0;
volatile long encoderCount_L = 0;

void encoderA_R()
{
    if (digitalRead(ENCODERA_R) > digitalRead(ENCODERB_R))
    {
        encoderCount_R++;
    }
    else
    {
        encoderCount_R--;
    }
}

void encoderA_L()
{

    if (digitalRead(ENCODERA_L) > digitalRead(ENCODERB_L))
    {
        encoderCount_L++;
    }
    else
    {
        encoderCount_L--;
    }
}

Motor motor1(EN_A, M1_FORWARD, M1_BACKWARD);
Motor motor2(EN_B, M2_FORWARD, M2_BACKWARD);

void setup()
{
    Serial.begin(115200); // Init Serial at 115200 Baud Rate.

    pinMode(ENCODERA_R, INPUT);
    pinMode(ENCODERB_R, INPUT);
    pinMode(ENCODERA_L, INPUT);
    pinMode(ENCODERB_L, INPUT);

    attachInterrupt(digitalPinToInterrupt(ENCODERA_R), encoderA_R, RISING);
    attachInterrupt(digitalPinToInterrupt(ENCODERA_L), encoderA_L, RISING);
    motor1.setSpeed(255);
    motor2.setSpeed(255);
}

void loop()
{
    while(encoderCount_R < 1000)
    {
        motor1.forward();
        motor2.forward();
    }
    motor1.stop();
    motor2.stop();
}
