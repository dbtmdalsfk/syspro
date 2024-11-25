#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <signal.h>

jmp_buf env;

void p10();
void intHandler(int sig);

int main() {
    signal(SIGINT, intHandler);
    if (setjmp(env) != 0) {
        printf("Return due to interrupt\n");
        exit(0);
    } else {
        printf("First pass\n");
        p10();
    }

    return 0;
}

void p10() {
    while (1) {
        printf("Loop\n");
        sleep(1);
    }
}

void intHandler(int sig) {
    printf("Interrupt\n");
    longjmp(env, 1);
}

