#include "AppCpp.h"
#include <os.h>
#include <iostream>

static  OS_TCB           Task1TCB;
static  CPU_STK          Task1Stk[TASK1_STK_SIZE];

static  OS_TCB           Task2TCB;
static  CPU_STK          Task2Stk[TASK2_STK_SIZE];

using namespace std;

void CreateTask1();
void CreateTask2();

void Task1(void* p_arg);
void Task2(void* p_arg);

void StartApp(void) {

	CreateTask1();

	CreateTask2();

}


void CreateTask1() {

    OS_ERR err;

    OSTaskCreate((OS_TCB*)&Task1TCB,
        (CPU_CHAR*)"Task1",
        (OS_TASK_PTR)Task1,
        (void*)0,
        (OS_PRIO)TASK1_PRIO,
        (CPU_STK*)&Task1Stk[0],
        (CPU_STK_SIZE)TASK1_STK_SIZE / 10,
        (CPU_STK_SIZE)TASK1_STK_SIZE,
        (OS_MSG_QTY)0,
        (OS_TICK)0,
        (void*)0,
        (OS_OPT)(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
        (OS_ERR*)&err);

}



void CreateTask2() {

    OS_ERR err;

    OSTaskCreate((OS_TCB*)&Task2TCB,
        (CPU_CHAR*)"Task2",
        (OS_TASK_PTR)Task2,
        (void*)0,
        (OS_PRIO)TASK2_PRIO,
        (CPU_STK*)&Task2Stk[0],
        (CPU_STK_SIZE)TASK2_STK_SIZE / 10,
        (CPU_STK_SIZE)TASK2_STK_SIZE,
        (OS_MSG_QTY)0,
        (OS_TICK)0,
        (void*)0,
        (OS_OPT)(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
        (OS_ERR*)&err);
}



void Task1(void* p_arg) {
    OS_ERR err;

    CPU_INT16U i = 0;

    while (1) {

        OSTimeDlyHMSM((CPU_INT16U)0,
            (CPU_INT16U)0,
            (CPU_INT16U)0,
            (CPU_INT32U)100,
            (OS_OPT)OS_OPT_TIME_HMSM_STRICT,
            (OS_ERR*)&err);
        if (err != OS_ERR_NONE) {

        }
        else {
            cout << "Task1 : " << i << endl;
            i++;
        }


    }
}

void Task2(void* p_arg) {
    OS_ERR err;

    CPU_INT16U i = 0;

    while (1) {

        OSTimeDlyHMSM((CPU_INT16U)0,
            (CPU_INT16U)0,
            (CPU_INT16U)0,
            (CPU_INT32U)100,
            (OS_OPT)OS_OPT_TIME_HMSM_STRICT,
            (OS_ERR*)&err);
        if (err != OS_ERR_NONE) {

        }
        else {
            cout << "Task2 : " << i << endl;
            i++;
        }


    }
}