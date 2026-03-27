#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

// HC-SR04 驱动
class Ultrasonic {
public:
    Ultrasonic(uint8_t trigPin, uint8_t echoPin);
    void begin();
    float readDistanceMeters(); // 读取距离 单位：米

private:
    uint8_t _trig;
    uint8_t _echo;
    const float SOUND_SPEED = 343.0; // 声速 m/s
};

#endif