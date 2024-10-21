#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include"db.dat"

int main(int argc,char*argv[])
{
	int fd;
	struct book record;
	if(argc < 2){
		fprintf(stderr,"How to use:&s file\n",argv[0]);
		exit(1);
	}
	if((fd = open(argv[1],O_WRONLY|O_CREAT|O_EXCL,0640))==-1){
		perror(argv[1]);
		exit(2);
	}
	printf("%-9s %-8s %-4s %-4s %-4s %-4s\n","Number","Bkname","Huname",
			"Year","Lonum","Loava");
	while(scanf("%d%s%s%d%d%s",&record.number,record.bkname,record.huname,
				&record.year,&record.lonum,record.loava)==6){
		lseek(fd,(record.number - START_ID)*sizeof(record),SEEK_SET);
		write(fd,(char *)&record,sizeof(record));
	}
	close(fd);
	exit(0);
	}

