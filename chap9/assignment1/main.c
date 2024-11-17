#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 100

void parse_command(char *cmd, char **args) {
    int i = 0;
    args[i] = strtok(cmd, " ");
    while (args[i] != NULL) {
        i++;
        args[i] = strtok(NULL, " ");
    }
}

void execute_command(char *cmd) {
    char *args[MAX_ARGS];
    int background = 0;

    if (cmd[strlen(cmd) - 1] == '&') {
        background = 1;
        cmd[strlen(cmd) - 1] = '\0';
    }

    parse_command(cmd, args);

    int fd_in = -1, fd_out = -1;
    for (int i = 0; args[i] != NULL; i++) {
        if (strcmp(args[i], "<") == 0) {
            fd_in = open(args[i + 1], O_RDONLY);
            if (fd_in < 0) {
                perror("failed");
                return;
            }
            dup2(fd_in, STDIN_FILENO);
            args[i] = NULL;
        } else if (strcmp(args[i], ">") == 0) {
            fd_out = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd_out < 0) {
                perror("failed");
                return;
            }
            dup2(fd_out, STDOUT_FILENO);
            args[i] = NULL;
        }
    }

    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("failed");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("failed");
    } else {
        if (!background) {
            waitpid(pid, NULL, 0);
        }
    }

    if (fd_in >= 0) close(fd_in);
    if (fd_out >= 0) close(fd_out);
}

int main() {
    char input[MAX_CMD_LEN];
    char *commands[MAX_ARGS];

    while (1) {
        printf("[shell] ");
        if (fgets(input, MAX_CMD_LEN, stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        int i = 0;
        commands[i] = strtok(input, ";");
        while (commands[i] != NULL) {
            i++;
            commands[i] = strtok(NULL, ";");
        }

        for (int j = 0; commands[j] != NULL; j++) {
            execute_command(commands[j]);
        }
    }

    return 0;
}
