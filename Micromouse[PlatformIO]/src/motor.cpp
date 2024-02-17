
#include "Motor.h"

Motor::Motor(int en, int forwardPin, int backwardPin) {
    this->en = en;
    this->forwardPin = forwardPin;
    this->backwardPin = backwardPin;
    pinMode(en, OUTPUT);
    pinMode(forwardPin, OUTPUT);
    pinMode(backwardPin, OUTPUT);
}

void Motor::setSpeed(int speed) {   
    analogWrite(en, speed);
}

void Motor::forward() {
    digitalWrite(forwardPin, HIGH);
    digitalWrite(backwardPin, LOW);
}

void Motor::backward() {
    digitalWrite(forwardPin, LOW);
    digitalWrite(backwardPin, HIGH);
}

void Motor::stop() {
    digitalWrite(forwardPin, LOW);
    digitalWrite(backwardPin, LOW);
}
