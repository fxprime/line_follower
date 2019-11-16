#include <Arduino.h>
#include <QTRSensors.h>
#include "User_Setup.h"
#include "macro.hpp"
#include "config.hpp"
#include "line_sensor.hpp"
#include "motor.hpp"
#include "pid.hpp"


void setup() {
    Serial.begin(115200);
//    while(1) {
//        delay(100);
//        char buff[44];
//        sprintf(buff, "%d %d %d %d", analogRead(A0), analogRead(A1), analogRead(A2), analogRead(A3));
//        Serial.println(buff);
//    }

    line::line_sensor_init();
    motor::motor_init();
    pid::pid_init();

    Serial.println("Start robot!!");
}

void loop() {

    static fime_t last_print = micros();
    if( micros() - last_print > 10000) {
        last_print = micros();

        float pose = -100*(float)line::getLinePos();



        float rotate = pid::getOutput(pose, 0);
        rotate = constrain(rotate, -_limitOutput, _limitOutput);
//        _baseSpeed= 0;
        float leftOut = constrain(_baseSpeed + rotate, -1, 1.0);
        float rightOut = constrain(_baseSpeed - rotate, -1, 1.0);
        motor::motor_cmd(leftOut, rightOut);

//        char buff[44];
//        sprintf(buff, "%d, %d, %d, %d, %d\n", (int)normVal[0], (int)normVal[1], (int)normVal[2], (int)normVal[3], (int)pose);
//        Serial.println(pose);
//        Serial.println(line::getError());

//        Serial.print(pose);
//        Serial.print("\t");
//        Serial.print(rotate);
//        Serial.print("\t");
//        Serial.print(_baseSpeed + rotate);
//        Serial.print("\t");
//        Serial.println(_baseSpeed - rotate);
    }
//
//    motor::motor_cmd(1, 1);
//    delay(1000);
//    motor::motor_cmd(0, 1);
//    delay(1000);
//    motor::motor_cmd(1, 0);
//    delay(1000);
//    motor::motor_cmd(0, 0);
//    delay(5000);
}
