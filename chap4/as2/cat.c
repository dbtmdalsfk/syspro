#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFile(const char *filename, int lineNumbers) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[1024];
    int lineCount = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        lineCount++;
        if (lineNumbers) {
            printf("%d\t", lineCount);
        }
        printf("%s", buffer);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    int lineNumbers = 0;

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        lineNumbers = 1;
        argv++;
        argc--;
    }

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-n] <file1> <file2> ... <fileN>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        printFile(argv[i], lineNumbers);
    }

    return 0;
}

