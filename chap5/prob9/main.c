#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINES 100  
#define MAX_LENGTH 256 

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


void printAllReversed(int totalLines) {
    for (int i = totalLines - 1; i >= 0; i--) {
        printf("%s\n", savedText[i]); 
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    int totalLines = readFileIntoArray(argv[1]);
    printAllReversed(totalLines);

    return 0;
}
