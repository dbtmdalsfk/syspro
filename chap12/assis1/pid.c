#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) { 
        printf("parent process ID: %d, child process ID: %d\n", getpid(), pid);
    } else if (pid == 0) { 
        printf("child process ID: %d, parent process ID: %d\n", getpid(), getppid());
    } else { 
        perror(" failed");
    }
    return 0;
}

