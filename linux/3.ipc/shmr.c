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
	
	shmid = shmget(key, 1024*4, 0);
	
	if(shmid == -1){
		printf("shm craet failed\n");
	}
	
	//shmget(key_t key, size_t size, int shmflg);
	
	addr = shmat(shmid, 0, 0);
	printf("start\n");
	printf("shm is %s\n",addr);	
	printf("over\n");
	shmdt(addr);
	


	return 0;
}


