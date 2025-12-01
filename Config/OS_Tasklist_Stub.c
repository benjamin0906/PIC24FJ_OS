#include "OS_Taskconfig_Stub.h"

uint16 Task_Stack[256];
uint16 Task2_Stack[256];

dtTaskInfo TaskList[TASK_NUMBER] =
{
    TASK(Task, Task_Stack),
    TASK(Task2, Task2_Stack),
};
