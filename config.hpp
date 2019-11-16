//
// Created by fx on 22/8/2562.
//

#ifndef LINE_FOLLOWER_CONFIG_HPP
#define LINE_FOLLOWER_CONFIG_HPP

//Tuner
#define NUM_SEN 4


//Pid gain
float _Kp = 0.03;
float _Kd = 1.0;
float _baseSpeed = 0.45;
float _limitError = 40;
float _limitDError = 40;
float _limitOutput = 0.6;


//Motor limit
uint16_t _leftMotorLimit = 1000; //0-1000
uint16_t _rightMotorLimit = 1000; //0-1000
float _max_mot_diff = 40/255.0;
float _factor_diff = 4;


//Pin setup
uint8_t LedPIN = 13;

//Motor pin setup
uint8_t MLftDirAPin = 7;
uint8_t MLftDirBPin = 6;
uint8_t MLftSpdPin = 5;
bool  MLftRev = false;


uint8_t MRgtDirAPin = 8;
uint8_t MRgtDirBPin = 9;
uint8_t MRgtSpdPin = 10;
bool  MRgtRev = true;

//Line detector Pin setup

QTRSensors qtr;
const uint8_t _SensorCount = 4;
uint16_t sensorValues[_SensorCount];
uint8_t L1Pin = A0;
uint8_t L2Pin = A1;
uint8_t L3Pin = A2;
uint8_t L4Pin = A3;
uint8_t L5Pin = A4;
int _sens_min[NUM_SEN];
int _sens_max[NUM_SEN];




#endif //LINE_FOLLOWER_CONFIG_HPP
