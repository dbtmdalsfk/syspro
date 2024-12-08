#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    int pipe_fd[2];
    pid_t child1, child2;

    if (pipe(pipe_fd) == -1) {
        perror("failed");
        return 1;
    }

    child1 = fork();
    if (child1 == -1) {
        perror(" failed child1");
        return 1;
    }

    if (child1 == 0) {
        close(pipe_fd[0]);
        char input[BUFFER_SIZE];
        fgets(input, BUFFER_SIZE, stdin);
        input[strcspn(input, "\n")] = '\0';
        write(pipe_fd[1], input, strlen(input) + 1);
        close(pipe_fd[1]);
        exit(0);
    }

    child2 = fork();
    if (child2 == -1) {
        perror("failed  child2");
        return 1;
    }

    if (child2 == 0) {
        close(pipe_fd[1]);
        char buffer[BUFFER_SIZE];
        read(pipe_fd[0], buffer, BUFFER_SIZE);
        to_uppercase(buffer);
        printf("%s\n", buffer);
        close(pipe_fd[0]);
        exit(0);
    }

    close(pipe_fd[0]);
    close(pipe_fd[1]);
    wait(NULL);
    wait(NULL);

    return 0;
}

