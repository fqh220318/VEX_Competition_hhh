#ifndef VEX_H_
#define VEX_H_

#include "v5.h"
#include "v5_vcs.h"

// 新增

/// @brief Robot Operation Mode
enum RobotOperationMode { AUTO, USER_CONTROL };

enum AutoFuncMode { COMPETITION, EMPTY };

extern RobotOperationMode robot_operation_mode;
extern AutoFuncMode auto_func_reg;

#endif