#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = getpid();
    int ppid = getppid();
    printf("SON1 PARAMS: pid=%i ppid=%i\n",pid,ppid);
    //sleep(2);
    return 0; // статус завершения 0
}
