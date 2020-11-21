#include <os.h>
#include <app.h>  
#include <AppCpp.h>

/*
***********************************************************************************************
*                                 LOCAL GLOBAL VARIABLES
***********************************************************************************************
*/
static  OS_TCB           AppTaskStartTCB;
static  CPU_STK          AppTaskStartStk[APP_TASK_START_STK_SIZE];
/*
***********************************************************************************************
*                                  FUNCTION PROTOTYPES
***********************************************************************************************
*/

static  void  AppTaskStart(void* p_arg);

void main(void)
{
    OS_ERR  err;

    //BSP_IntDisAll();                                                               
    OSInit(&err);
    if (err != OS_ERR_NONE) {
        /* Something didn’t get initialized correctly ...                    */
        /* ... check os.h for the meaning of the error code, see OS_ERR_xxxx */
    }

    App_OS_SetAllHooks();

    OSTaskCreate((OS_TCB*)&AppTaskStartTCB,
        (CPU_CHAR*)"App Task Start",
        (OS_TASK_PTR)AppTaskStart,
        (void*)&AppTaskStartTCB,
        (OS_PRIO)APP_TASK_START_PRIO,
        (CPU_STK*)&AppTaskStartStk[0],
        (CPU_STK_SIZE)APP_TASK_START_STK_SIZE / 10,
        (CPU_STK_SIZE)APP_TASK_START_STK_SIZE,
        (OS_MSG_QTY)0,
        (OS_TICK)0,
        (void*)0,
        (OS_OPT)(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
        (OS_ERR*)&err);
    if (err != OS_ERR_NONE) {
        /* The task didn’t get created.  Lookup the value of the error code ... */
        /* ... in os.h for the meaning of the error                             */
    }
    OSStart(&err);
    if (err != OS_ERR_NONE) {
        /* Your code is NEVER supposed to come back to this point.              */
    }
}

static  void  AppTaskStart(void* p_arg)
{
    OS_ERR  err;
    CPU_INT16U i = 0;

    p_arg = p_arg;
                                             
    CPU_Init();
  
    StartApp();

    OSTaskSuspend(p_arg, &err);

}
