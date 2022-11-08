#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
//int msgget(key_t key, int msgflg);
//int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
//ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);


struct msgbuf {
         long mtype;       /* message type, must be > 0 */
         char mtext[128];    /* message data */
};


int main()
{
	struct msgbuf getbuf; 
	struct msgbuf sebuf = {988,"hello world too"};
	key_t key = ftok(".", 2);
	int msID = msgget(key ,IPC_CREAT|0777);

	if(msID == -1){
		printf("megget creat failed\n");
	}
 
	msgrcv(msID, &getbuf, sizeof(getbuf.mtext), 888, 0);

	printf("get is:%s\n",getbuf.mtext);

	msgsnd(msID, &sebuf, strlen(sebuf.mtext), 0);
	
	msgctl(msID, IPC_RMID,NULL);
	return 0;
}
