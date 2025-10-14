#include"usercontrol.h"
// 新增
#include"autonomous.h"
#include<iostream>
#include<cmath>
#include<cstdlib>
#include"vex.h"
using namespace std;
using namespace vex;

#undef deadzone
#define deadzone 5
#undef C
#define C 82.55
#define eps 1.0000000000000000000000000000000000000000000

motor leftfront=motor(PORT18,0);
motor leftback=motor(PORT8,0);
motor rightfront=motor(PORT13,1);
motor rightback=motor(PORT3,1);

void dir(double posy1,double posy2,double& leftspeed,double& rightspeed)
{
    if(abs(posy1)<deadzone)posy1=0;
    if(abs(posy2)<deadzone)posy2=0;

    leftspeed=posy1-posy2;
    rightspeed=posy1+posy2;

    leftspeed=max(leftspeed,-100*eps);
    leftspeed=min(leftspeed,100*eps);
    rightspeed=max(rightspeed,-100*eps);
    rightspeed=min(rightspeed,100*eps);
}

void controldir()
{

    while(1)
    {
        controller Controller1 = controller(primary);
        double L=Controller1.Axis3.position(),R=Controller1.Axis1.position();
        double leftspeed,rightspeed;

        dir(L,R*C*eps/2,leftspeed,rightspeed);

        leftfront.spin(fwd,leftspeed,pct);
        leftback.spin(fwd,leftspeed,pct);
        rightfront.spin(fwd,rightspeed,pct);
        rightback.spin(fwd,rightspeed,pct);

        wait(20,msec);
    }
}

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
   controldir();
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