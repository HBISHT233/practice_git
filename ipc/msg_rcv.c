#include "header.h"
struct msgbuf {
	long mtype;
	char data[20];
};

int main() {
	int id;
	struct msgbuf v;
	id = msgget(3,IPC_CREAT | 0666);
	perror("msgget");

	printf("before receivving the message.. \n");
	msgrcv(id,&v,20,2,0); // what is that "2" "hint: try check msg sent call"
	printf("data = %s\n",v.data);
}
