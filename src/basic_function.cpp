#include "basic_function.h"

using namespace vex;

void moveTestMotor(double percent) {
    motor_test.spin(forward, percent, percentUnits::pct);
}

// 新增
void turnTo(double tar_angle) {

}

void PIDDistanceForwardRel(double target) {

}