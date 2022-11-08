#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

//       int sigaction(int signum, const struct sigaction *act,
//                     struct sigaction *oldact);

void handler(int sig, siginfo_t *info, void *ucontext)
{
	printf("sig is %d\n",sig);
	if(ucontext != NULL){
		printf("data is %d\n",info->si_int);
	}
              
}

int main()
{
	struct sigaction act;
	printf("pid is %d\n",getpid());

	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;


	sigaction(SIGUSR1, &act, NULL);
	while(1);

	return 0;
}

