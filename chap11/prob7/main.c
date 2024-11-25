#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;

void p10();
void p20();

int main() {
    if (setjmp(env) != 0) {
        printf("Exception handling after return due to error\n");
        exit(0);
    } else {
        printf("First pass\n");
        p10();
    }

    return 0;
}

void p10() {
    p20();
}

void p20() {
    int error;
    error = 1;
    if (error) {
        printf("Error\n");
        longjmp(env, 1);
    }
}

