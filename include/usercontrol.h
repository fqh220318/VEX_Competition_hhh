#ifndef USERCONTROL_H_
#define USERCONTROL_H_
#include "vex.h"
#include "basic_function.h"
#include "controller.h"

void motorTestControl();

// 新增
void testTurnTo();
void testPIDDistanceForward();
void testAuton();

void allDeviceControl();
void userControl();

#endif
