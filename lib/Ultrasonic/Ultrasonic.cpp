#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(uint8_t trigPin, uint8_t echoPin) {
    _trig = trigPin;
    _echo = echoPin;
}

void Ultrasonic::begin() {
    pinMode(_trig, OUTPUT);
    pinMode(_echo, INPUT);
    digitalWrite(_trig, LOW);
}

float Ultrasonic::readDistanceMeters() {
    // 触发信号
    digitalWrite(_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trig, LOW);

    // 读取回波时间
    long duration = pulseIn(_echo, HIGH, 23200); // 超时4米
    if (duration == 0) return 4.0; // 超量程返回最大值

    // 换算成米
    float distance = (duration * SOUND_SPEED) / 2000000.0;
    return distance;
}