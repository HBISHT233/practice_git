#include "header.h"
struct msgbuf {
	long mtype; // Msgtype>0
	char data[20];
};

int main(int argc,char **argv) {
	int id;
	struct msgbuf v;
	id  =msgget(3,IPC_CREAT | 0666);
	perror("msgget");

	v.mtype = atoi(argv[1]);
	strcpy(v.data,argv[2]);
	printf("id = %d \n",id);
	msgsnd(id,&v,strlen(v.data)+1,0);
}
