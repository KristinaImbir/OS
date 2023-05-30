#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main ()
{
    struct sched_param shdprm; // значения параметров планирования
    int pid, pid1, pid2, pid3, pid4, pid5, pid6, ppid, status;
    int n, m, l, k, a, b, c; // переменные для задания значений приоритетов,
    // для удобства можно оформить их как аргументы командной
    // строки пр изапуске и
    // как аргумент добавить задаваемую политику планирования
    n=50; m=60; l=10; k=80; a=55; b=19; c=4;// заданные значения приоритетов cполитикой RR//
    //m=60; l=10; k=4;
    //для повторного эксперимента с политикой FIFO
    pid = getpid();
    ppid = getppid();
    printf("FATHER PARAMS: pid=%i ppid=%i\n", pid,ppid);
    shdprm.sched_priority = n;
    if (sched_setscheduler (0, SCHED_RR, &shdprm) == -1)
    {
        perror ("SCHED_SETSCHEDULER");
    }
    if((pid1=fork()) == 0)
    {
        shdprm.sched_priority = m;
        if (sched_setscheduler (pid1, SCHED_RR, &shdprm) == -1)
            perror ("SCHED_SETSCHEDULER_1");
        execl("son1", "son1", NULL);
    }
    if((pid2=fork()) == 0)
    {
    shdprm.sched_priority = l;
    if (sched_setscheduler (pid2, SCHED_RR, &shdprm) == -1)
        perror ("SCHED_SETSCHEDULER_2");
        execl("son2", "son2", NULL);
    }
    if ((pid3=fork()) == 0)
    {
        shdprm.sched_priority = k;
        if (sched_setscheduler (pid3, SCHED_RR, &shdprm) == -1)
            perror ("SCHED_SETSCHEDULER_3");
        execl("son3", "son3", NULL);
    }
    if ((pid4=fork() == 0))
    {
        shdprm.sched_priority = a;
        if (sched_setscheduler(pid4, SCHED_RR, &shdprm) == -1)
            perror("SCHED_SETSCHEDULER_4");
        execl("son4", "son4", NULL);
    }
    if ((pid5=fork()) == 0)
    {
        shdprm.sched_priority = b;
        if (sched_setscheduler (pid5, SCHED_RR, &shdprm) == -1)
            perror ("SCHED_SETSCHEDULER_5");
        execl("son5", "son5", NULL);
    }
    if ((pid6=fork()) == 0)
    {
        shdprm.sched_priority = c;
        if (sched_setscheduler (pid6, SCHED_RR, &shdprm) == -1)
            perror ("SCHED_SETSCHEDULER_6");
        execl("son6", "son6", NULL);
    }

    printf("Процесс с pid = %d завершен\n", wait(&status));
    printf("Процесс с pid = %d завершен\n", wait(&status));
    printf("Процесс с pid = %d завершен\n", wait(&status));
    printf("Процесс с pid = %d завершен\n", wait(&status));
    printf("Процесс с pid = %d завершен\n", wait(&status));
    printf("Процесс с pid = %d завершен\n", wait(&status));


    return 0;
}
