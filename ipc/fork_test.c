#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>


int i=0; // i is the global variable, this to chech whether the child and parent are on same memory or not

void test(char *name)
{
	for (;i<5;i++)
	{
		printf("%d th iterration for %s\n",i,name);
	}

}


int main (int argc,char *argv[])
{
	pid_t pid = fork();
	if(pid ==0)
	{
		printf("this is child\n");
		printf("fork return the value to child =  %d\n",(int) pid);
		test("child");

	}
	if(pid > 0)
	{
		printf("this is parent\n");
		printf("for return the value to parent = %d\n",(int) pid);
		test("parent");
	}
}

