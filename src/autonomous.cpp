#include "autonomous.h"
// 新增
#include "my-timer.h"


using namespace std;
using namespace vex;

void autonTest() {

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