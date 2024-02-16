#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
public:
    Motor(int en, int forwardPin, int backwardPin);
    void setSpeed(float percent);
    void forward();
    void backward();
    void stop();

private:
    int en;
    int forwardPin;
    int backwardPin;
};

#endif
