#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAXARG 64

int main() {
    char command[MAX_CMD_LEN];
    char *args[MAXARG];
    char *saveptr;

    while (1) {
        printf("[Shell] ");
        fflush(stdout);

        if (!fgets(command, sizeof(command), stdin)) {
            break;
        }

        size_t len = strlen(command);
        if (command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        int arg_count = 0;
        char *token = strtok_r(command, " ", &saveptr);
        while (token != NULL) {
            args[arg_count++] = token;
            if (arg_count >= MAXARG - 1) break;
            token = strtok_r(NULL, " ", &saveptr);
        }
        args[arg_count] = NULL;

        if (arg_count == 0) continue;

        int background = 0;
        if (strcmp(args[arg_count - 1], "&") == 0) {
            background = 1;
            args[--arg_count] = NULL;
        }

        pid_t pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            perror("failed");
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            if (!background) {
                waitpid(pid, NULL, 0);
            }
        } else {
            perror("failed");
        }
    }

    return 0;
}

