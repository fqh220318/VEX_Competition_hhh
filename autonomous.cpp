#include "autonomous.h"
// 新增
#include "my-timer.h"


using namespace std;
using namespace vex;

#include "usercontrol.h"
// 新增
#include <iostream>
#include<cmath>
#include<cstdlib>
#include"vex.h"

#define pi 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679 

motor frontleft=motor(PORT18,1);
motor frontright=motor(PORT13,1);
motor backleft=motor(PORT8,0);
motor backright=motor(PORT3,0);


double motord=82.00;
double motorc=motord*pi;

#undef eps
#define eps 1.000000000000000000000000000000000000000000000 

const double kp=0.8*eps;
const double ki=0.001*eps;
const double kd=0.3*eps;

const double err=1*eps;

double curpos()
{
	double degfl=frontleft.position(degrees);
	double degfr=frontright.position(degrees);
	double degbl=backleft.position(degrees);
	double degbr=backright.position(degrees);
	
	return (degfl+degfr+degbl+degbr)*eps/4;
}

void go(double target)
{
	frontleft.resetPosition();
	frontright.resetPosition();
	backleft.resetPosition();
	backright.resetPosition();
	
	double targetdegree=target*eps*360/motorc;
	
	double curdistance=targetdegree-0*eps;
	double prevdistance=targetdegree-0*eps;
	double sumi=0*eps;
	double sumd=0*eps;
	
	while(abs(curdistance)>err)
	{
		curdistance=targetdegree-curpos();
		sumi+=curdistance;
		sumd=curdistance-prevdistance;
		prevdistance=curdistance;
		
		double curspeed=kp*curdistance+ki*sumi+kd*sumd;
		
		curspeed=max(curspeed,-100*eps);
		curspeed=min(curspeed,100*eps);
		
		frontleft.spin(fwd,curspeed,percent);
		frontright.spin(fwd,curspeed,percent);
		backleft.spin(fwd,curspeed,percent);
		backright.spin(fwd,curspeed,percent);
		
		wait(20,msec);
	}
	
	frontleft.stop();
	frontright.stop();
	backleft.stop();
	backright.stop();
}

void turn90de()//90degrees
{
	const double rspeed=25.0;
	const int ROTATE_TIME_MS = 850;
	
	frontleft.spin(fwd,rspeed,percent);
	frontright.spin(fwd,rspeed,percent);
	backleft.spin(fwd,rspeed,percent);
	backright.spin(fwd,rspeed,percent);

	wait(ROTATE_TIME_MS,msec);

	frontleft.stop();
	frontright.stop();
	backleft.stop();
	backright.stop();
}

void autonTest()
{
	turn90de();
    go(10000.00);
	
}



void autonomous() {
    cout << "Entering autonomous" << endl;
    robot_operation_mode = RobotOperationMode::AUTO;
    MyTimer auto_timer;

    // 下面写自动函数名
    autonTest();

    cout << "AUTONOMOUS end: " << auto_timer.getTime() << endl;

    // 路线结束后不要退出自动函数
    while (true) {
        this_thread::sleep_for(10);
    }
}