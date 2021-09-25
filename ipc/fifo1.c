#include "header.h"
int main() {
	int fd,fd1;
	char a[20];
	mkfifo("f1",0666);
	perror("mkfifo");
	mkfifo("f2",0666);
	perror("mkfifo");

	fd=open("f1",O_RDWR);
	fd1=open("f2",O_RDWR);

	printf("pid= %d\n",getpid());

	if(fork()) {
		while(1) {
			printf("enter the data.. \n");
			scanf("%s",a);
			write(fd,a,strlen(a)+1);
		}

	}

	else {
		while(1) {
			read(fd1,a,sizeof(a));
			printf("data = %s \n",a);
		}
	}
}
