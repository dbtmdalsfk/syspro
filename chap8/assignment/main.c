#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_v(char *v_name) {
    if (v_name) {
        char *value = getenv(v_name);
        if (value) {
            printf("%s=%s\n", v_name, value);
        } else {
            printf("no.\n", v_name);
        }
    } else {
        printf("no name.\n");
    }
}

void print_user_ids() {
    printf("Actual User ID: %d\n", getuid());
    printf("Valid User ID: %d\n", geteuid());
}

void print_group_ids() {
    printf("Actual Group ID: %d\n", getgid());
    printf("Valid Group ID: %d\n", getegid());
}

void print_process_id() {
    printf("Process ID: %d\n", getpid());
}

void print_parent_process_id() {
    printf("Parent Process ID: %d\n", getppid());
}

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'e':
                    if (i + 1 < argc && argv[i + 1][0] != '-') {
                        print_v(argv[++i]);
                    } else {
                        print_v(NULL);
                    }
                    break;

                case 'u':
                    print_user_ids();
                    break;

                case 'g':
                    print_group_ids();
                    break;

                case 'i':
                    print_process_id();
                    break;

                case 'p':
                    print_parent_process_id();
                    break;

                default:
                    return 1;
            }
        } else {
            return 1;
        }
    }

    return 0;
}

