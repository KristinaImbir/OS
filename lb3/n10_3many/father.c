#include <stdio.h>
#include <sys/types.h>
#include <wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>



int main() {
    struct sched_param shdprm; // значения параметров планирования
    int pid, pid1, pid2, pid3, ppid, status;
    int n, m, l, k;

    n=50; m=60; l=70; k=80;
    // 

    pid = getpid();
    ppid = getppid();
    printf("FATHER PARAMS: pid=%i ppid=%i\n", pid,ppid);
    shdprm.sched_priority = n;
    if (sched_setscheduler (0, SCHED_RR, &shdprm) == -1) {
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

    if((pid3=fork()) == 0)
    {
        shdprm.sched_priority = k;
        if (sched_setscheduler (pid3, SCHED_RR, &shdprm) == -1)
            perror ("SCHED_SETSCHEDULER_3");
        execl("son3", "son3", NULL);
    }

    printf("Процесс с pid = %d завершен\n", wait(&status));
    printf("Процесс с pid = %d завершен\n", wait(&status));
    printf("Процесс с pid = %d завершен\n", wait(&status));
    return 0;
}
