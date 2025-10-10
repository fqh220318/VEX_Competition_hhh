#include "usercontrol.h"
// 新增
#include "autonomous.h"
#include <iostream>
using namespace std;
using namespace vex;

void motorTestControl() {
    // 电机控制示例代码，仅作参考
    if(R1) {
        moveTestMotor(100);
    }
    else{
        moveTestMotor(0);
    }
}

// 新增
// 测试函数，按键可以替换，测试完成可将函数注释，不额外占用按键
void testTurnTo() {
    if(press_A) {
        press_A = false;
        turnTo(90);
    }
}

void testPIDDistanceForward() {
    if(press_B) {
        press_B = false;
        PIDDistanceForwardRel(60);
    }
}

void testAuton() {
    if(press_X) {
        press_X = false;
        autonTest();
    }
}

void allDeviceControl() {
    // 在这里添加对所有设备的控制代码
    // 例如，控制电机、传感器等
    motorTestControl();

    // 新增
    testTurnTo();
    testPIDDistanceForward();
    testAuton();
}

void userControl() {
    // 新增
    // 用户控制代码
    while (true) {
        if (auto_func_reg == COMPETITION) {
            cout << "User Control" << endl;
            robot_operation_mode = RobotOperationMode::USER_CONTROL;
        }
        allDeviceControl();
        this_thread::sleep_for(2); // 避免占用过多CPU资源
    }
}