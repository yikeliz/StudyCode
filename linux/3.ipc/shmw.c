#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
//int shmget(key_t key, size_t size, int shmflg);

int main()
{
	pid_t key;

	char *addr;
	int shmid;

	key = ftok(".", 0);
	
	shmid = shmget(key, 1024*4, IPC_CREAT|0666);
	
	if(shmid == -1){
		printf("shm craet failed\n");
	}
	
	//shmget(key_t key, size_t size, int shmflg);
	
	addr = shmat(shmid, 0, 0);

	strcpy(addr,"hello world");
	
	printf("fashion\n");
	sleep(5);
	shmdt(addr);
	
	shmctl(shmid, IPC_RMID, 0);

	printf("over\n");
	return 0;
}


