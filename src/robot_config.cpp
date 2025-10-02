#include "robot_config.h"
#include "vex.h"

using namespace vex;
MyBrain *my_brain = MyBrain::getInstance();
controller Controller = controller(primary);
inertial Inertial = inertial(PORT1);

motor motor_test = motor(PORT2, ratio6_1, false);

