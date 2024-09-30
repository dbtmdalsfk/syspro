#include <stdio.h>
#include "copy.h"

char line[MAXLINE];
char longest[MAXLINE]; 

main(){
  int len;
  int max;
  max = 0;
  
  for (i = 0; i < 5; i++){
  while(gets(line) != NULL) {
    len = strlen(line);
  }
  
  for(i =1; i <= 4; i++){
	  for(j = 0; j<5-i; j++){
    if(len > max) {
       max = len;
       copy(line, longest);
      }
    }
  }
  for(i=0; i<5; i++){
  if(max > 0)
    printf("%s \n", longest);
  }
  return 0;
}
