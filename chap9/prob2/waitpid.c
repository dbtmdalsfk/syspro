#include <sys/types.h>
	
   int main() 
   {
int pid1, pid2, child, status;
	
printf("[%d] parental process starat \n", getpid( ));
pid1 = fork();
if (pid1 == 0) {
	 printf("[%d] child process start [1] start \n", getpid( ));
	 printf("[%d] child process start [1] end \n", getpid( ));
	 exit(1);
}
	
 pid2 = fork();
	 if (pid2 == 0) {
	     printf("[%d] child process start #2 start \n", getpid( ));
	     sleep(2);
	     printf("[%d] child process start #2 end \n", getpid( ));
	     exit(2);
	 }
	 	 child = waitpid(pid1, &status, 0); 
	 printf("[%d] child process start #1 %d end \n", getpid( ), child);
	 printf("\t end code%d\n", status>>8);
	}

