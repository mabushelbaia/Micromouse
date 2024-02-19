#include <Arduino.h>
#include "Motor.h"




#define EN_1 4
#define EN_2 16
#define M1_FORWARD 2
#define M1_BACKWARD 0
#define M2_FORWARD 22
#define M2_BACKWARD 23

#define LEFT_ENCODERA 17
#define LEFT_ENCODERB 5
#define RIGHT_ENCODERA 19
#define RIGHT_ENCODERB 18

volatile long left_encoderCount = 0;
volatile long right_encoderCount = 0;

float kp_distance = 4;
float kd_distance = 6;


float lastErrorDistance = 0;
float lastErrorAngle = 0;

long distanceController(int target, float kp, float kd);
long angleController(int angle, float kp, float kd);
void moveForward(int cells);

void left_encoder()
{
    if (digitalRead(LEFT_ENCODERA) > digitalRead(LEFT_ENCODERB))
    {
        left_encoderCount++;
    }
    else
    {
        left_encoderCount--;
    }
}

void right_encoder()
{

    if (digitalRead(RIGHT_ENCODERA) > digitalRead(RIGHT_ENCODERB))
    {
        right_encoderCount++;
    }
    else
    {
        right_encoderCount--;
    }
}

Motor left_motor(EN_1, M1_FORWARD, M1_BACKWARD);
Motor right_motor(EN_2, M2_FORWARD, M2_BACKWARD);

void setup()
{
    Serial.begin(115200); // Init Serial at 115200 Baud Rate.

    pinMode(LEFT_ENCODERA, INPUT);
    pinMode(LEFT_ENCODERB, INPUT);
    pinMode(RIGHT_ENCODERA, INPUT);
    pinMode(RIGHT_ENCODERB, INPUT);

    attachInterrupt(digitalPinToInterrupt(LEFT_ENCODERA), left_encoder, RISING);
    attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODERA), right_encoder, RISING);

    moveForward(10);

}
void loop()
{
    moveForward(1);
}

long distanceController(int target, float kp, float kd)
{

    long encoderCount = (left_encoderCount + right_encoderCount) / 2;
    long error = target - encoderCount;
    if (abs(error) < 3)
    {
        return 0;
    }
    double P = kp * error;
    double D = kd * (error - lastErrorDistance);

    long output = (long) P + D;
    lastErrorDistance = error;
    return output;
}
// long angleController(int angle, float kp, float kd)
// {
//     long angleTicks = angle * 50;
//     long error = angleTicks - (left_encoderCount - right_encoderCount);
//     double P = kp * error;
//     double D = kd * (error - lastErrorDistance);
//     long output = (long) (P + D);
//     lastErrorAngle = error;
//     return output;
// }

void moveForward(int cells)
{
    long target = cells * 500;

    long u = distanceController(target, kp_distance, kd_distance);
    while (u != 0)
    {
        u = distanceController(target, kp_distance, kd_distance);
        int speed = (int) constrain(abs(u), 0, 255);
        Serial.println(speed);
        right_motor.setSpeed(speed);
        left_motor.setSpeed(speed);

        if (u > 0)
        {
            right_motor.forward();
            left_motor.forward();
        }
        else if (u < 0)
        {
            right_motor.backward();
            left_motor.backward();
        }
        else
        {
            right_motor.stop();
            left_motor.stop();
        }
    }


}