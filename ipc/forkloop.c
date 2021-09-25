#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	for (int i=1; i<=2 ;i++){
		fork();
		printf("%d : my pid =%d\n",i,(int) getpid());
	}

	sleep(1);
	printf("--> my pid is = %d\n",(int) getpid);
	return 0;
}

