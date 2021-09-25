#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int i=0;
void dosome(char *name)
{
	for(;i<5;i++)
	{
		printf("done %dth iteration for %s\n",i,name);
		sleep(rand() %4);
	}
}
int main(int argc ,char *argv[])
{
	printf("this is porcess with id =%d\n",(int) getpid());
	pid_t newid = fork();
	printf("fork retuned: %d\n", (int) newid);
	if(newid<0){
		perror("fork error occured");
	}
	if (newid ==0)
	{
		printf("this is child with pid %d\n", (int) getpid());
		dosome("child");
		exit(21); // we can exit with any value and we can also see this return value in parent
}
	/////this below section is parent
	int status=0;
	printf("this is parent\n");
	dosome("parent");
	pid_t childpid =wait(&status);
	printf("parent know child with id =%d is finishes\n", (int)childpid);
	// to see the exit value( returned value) use this command
	status = WEXITSTATUS(status);
	printf("the returned value is %d\n",status);
}
