
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINES 10  
#define MAX_LENGTH 100 

char savedText[MAX_LINES][MAX_LENGTH]; 


int readFileIntoArray(const char *filename) {
    int fd, i = 0, j = 0;
    char buf;
    
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }


    while (read(fd, &buf, 1) > 0) {
        if (buf == '\n') {
            savedText[i][j] = '\0'; 
            i++; 
            j = 0;
        } else {
            savedText[i][j++] = buf;
        }

        
        if (i >= MAX_LINES) break;
    }
    close(fd);
    return i; 
}

void printLine(int lineNumber, int totalLines) {
    if (lineNumber >= 0 && lineNumber < totalLines) {
        printf("Line %d: %s\n", lineNumber + 1, savedText[lineNumber]);
    } else {
        printf("Invalid line number: %d\n", lineNumber + 1);
    }
}


void printRange(int start, int end, int totalLines) {
    if (start < 0 || end >= totalLines || start > end) {
        printf("Invalid range: %d-%d\n", start + 1, end + 1);
        return;
    }
    for (int i = start; i <= end; i++) {
        printLine(i, totalLines);
    }
}


void printList(char *list, int totalLines) {
    char *token = strtok(list, ",");
    while (token != NULL) {
        int lineNumber = atoi(token) - 1; 
        printLine(lineNumber, totalLines);
        token = strtok(NULL, ",");
    }
}

void printAll(int totalLines) {
    for (int i = 0; i < totalLines; i++) {
        printLine(i, totalLines);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }


    int totalLines = readFileIntoArray(argv[1]);

    char input[50];
    printf("Enter the line number(s) (* for all, n, n-m, or n,...,m): ");
    scanf("%s", input);

    if (strcmp(input, "*") == 0) {

        printAll(totalLines);
    } else if (strchr(input, '-') != NULL) {
	 (n-m)
        int start, end;
        sscanf(input, "%d-%d", &start, &end);
        printRange(start - 1, end - 1, totalLines); 
    } else if (strchr(input, ',') != NULL) {
         (n,m,...)
        printList(input, totalLines);
    } else {

        int lineNumber = atoi(input);
        printLine(lineNumber - 1, totalLines); 
    }

    return 0;
}
