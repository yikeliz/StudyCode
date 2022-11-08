#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char **argv)
{	

	int pid;
	int signum;

	if(argc < 2)
	{
		printf("fialed\n");
	
	}
	signum = atoi(argv[1]);
	pid = atoi(argv[2]);

//	int sigqueue(pid_t pid, int sig, const union sigval value);
	printf("pid is %d\n",getpid());

	union sigval value;
	value.sival_int = 200;

	sigqueue(pid,signum,value);
	
	return 0;
}
