#include <stdio.h>
#include <string.h>  
#define MAXLINE 100 

char lines[5][MAXLINE];  
char temp[MAXLINE];      

int main(){
    int len;
    int i, j;

    for(i = 0; i < 5; i++){
        fgets(lines[i], MAXLINE, stdin);}

  
    for(i = 0; i < 4; i++){
        for(j = i + 1; j < 5; j++){
            if(strlen(lines[i]) < strlen(lines[j])){ 
                strcpy(temp, lines[i]);              
                strcpy(lines[i], lines[j]);
                strcpy(lines[j], temp);
            }
        }
    }


    for(i = 0; i < 5; i++){
        printf("%s", lines[i]);
    }

    return 0;
}
