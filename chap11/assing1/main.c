#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void alarmHandler(int signo);

int main() {
    struct sigaction sa;
    
    sa.sa_handler = alarmHandler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGALRM, &sa, NULL);

    alarm(5);
    short i = 0;
    while (1) {
        sleep(1);
        i++;
        printf("%d second\n", i);
    }

    return 0;
}

void alarmHandler(int signo) {
    printf("Wake up\n");
    exit(0);
}

