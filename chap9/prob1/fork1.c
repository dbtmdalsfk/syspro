#include <stdio.h>
#include <unistd.h>
int main()
{ 
   int pid;
   printf("[%d] proses start\n", getpid());
   pid = fork();
   printf("[%d] proses reture%d\n", getpid(), pid);
}

