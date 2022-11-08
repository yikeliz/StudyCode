#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
//       typedef void (*sighandler_t)(int);

//     sighandler_t signal(int signum, sighandler_t handler);



int main(int argc,char **argv)
{
	int signum;
	int pid;
	char cmd[128] = {0};

	pid = atoi(argv[2]);
	signum = atoi(argv[1]);
	
	printf("signum is %d,pid is %d\n",signum, pid);
	
	sprintf(cmd,"kill -%d %d",signum,pid);
	system(cmd);
	
//	kill(pid,signum);

	return 0;
}
