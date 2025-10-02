#include "my-timer.h"

#include <math.h>

#include "robot_config.h"

MyTimer::MyTimer() { start_time = my_brain->Timer.value(); }

MyTimer::MyTimer(double init) { start_time = my_brain->Timer.value() + init / 1000; }

void MyTimer::reset() { start_time = my_brain->Timer.value(); }

/// @brief Return the time from the start_time in milliseconds
/// @return int
int MyTimer::getTime() const {
    return floor((my_brain->Timer.value() - start_time) * 1000);  // return time (msec) from start_time
}

/// @brief Return the time from the start_time in seconds
/// @return double
double MyTimer::getTimeDouble() const {
    return my_brain->Timer.value() - start_time;  // return time (sec) from start_time
}

/// @brief Return the time in milliseconds
/// @return 
double MyTimer::getTimeMs() const {
    return my_brain->Timer.time(msec);
}