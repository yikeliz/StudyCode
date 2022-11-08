#include <signal.h>
#include <stdio.h>
//       typedef void (*sighandler_t)(int);

//     sighandler_t signal(int signum, sighandler_t handler);


void handler(int signum)
{
	printf("signum is %d\n",signum);
	printf("never stop\n");
}

int main()
{
	signal(SIGINT, handler);
	while(1);

	return 0;
}
