#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	pid_t pida = 0;
	pid_t pidb = 0;

	pida = getpid();
	printf("before fork pid = %d\n",pida);

	pidb = fork();

	printf("after fork pid = %d\n",getpid());

	if(getpid() > 0)
	{
		printf("father fork,%d\n",getpid());
	}
	else{

		printf("child fork,%d\n",getpid());
        }

	return 0;
}

