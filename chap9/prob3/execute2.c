#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main( ) 
{
   printf(" parental process starat \n");
   if (fork( ) == 0) {
      execl("/bin/echo", "echo", "hello", NULL);
      fprintf(stderr," first x "); 
      exit(1);
   }
   
   if (fork( ) == 0) {
      execl("/bin/date", "date", NULL);
      fprintf(stderr,"second x"); 
      exit(2);
  }

   if (fork( ) == 0) {
      execl("/bin/ls","ls", "-l", NULL);
      fprintf(stderr,"3 x"); 
      exit(3);
   }
   printf(" parental process end\n");
}

