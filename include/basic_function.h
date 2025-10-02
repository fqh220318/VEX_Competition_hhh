#ifndef BASIC_FUNCTIONS_H_
#define BASIC_FUNCTIONS_H_
#include "robot_config.h"

void moveTestMotor(double percent);

// 新增
void turnTo(double tar_angle);
void PIDDistanceForwardRel(double target);

#endif