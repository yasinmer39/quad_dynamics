#ifndef _MW_CUSTOM_RTOS_HEADER_H_
#define _MW_CUSTOM_RTOS_HEADER_H_
#define MW_BASERATE_PRIORITY           250
#define MW_BASERATE_PERIOD             0.01
#define MW_NUMBER_SUBRATES             0
#define MW_NUMBER_APERIODIC_TASKS      0
#define MW_IS_CONCURRENT               0
#define MW_NUMBER_TIMER_DRIVEN_TASKS   0

extern void exitFcn(int sig);
extern void *terminateTask(void *arg);
extern void *baseRateTask(void *arg);
extern void *subrateTask(void *arg);

#define MW_NEEDS_BACKGROUND_TASK
#define MW_BACKGROUNDTASK_PRIORITY     249

extern void *backgroundTask(void *arg);
extern pthread_t backgroundThread;
extern pthread_t schedulerThread;
extern pthread_t baseRateThread;
extern pthread_t subRateThread[];
extern px4_sem_t stopSem;
extern px4_sem_t baserateTaskSem;
extern px4_sem_t subrateTaskSem[];
extern int taskId[];
extern int subratePriority[];

#endif

#define MW_MAX_TASKNAME                16
