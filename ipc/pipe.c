#include "header.h"
int main() {
	int p[2],ret;
	ret=pipe(p);

	if (ret <0){
		perror("pipe_error");
		return; }
	printf("p[0] = %d p[1] = %d\n",p[0],p[1]);

	if(fork() == 0){
		//child
		while(1){
		       sleep(1);
		       char b[20];
	       	       printf("before reading in the child...\n");
		       read(p[0],b,20);
		       printf("after read flag \n");
		       printf("after reading in child: %s\n",b);
		}	       
	}
	else{
		//parent

	while(1){
		printf("before input flag\n");
		sleep(2);
		char a[20];
		printf("enter the data .. \n");
		scanf("%s",a);
		write(p[1],a,strlen(a)+1);
	}
}
}
