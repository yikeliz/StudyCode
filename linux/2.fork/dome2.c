#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	pid_t pida = 0;

	pida = getpid();

	printf("pid = %d\n",pida);
	
	while(1);

	return 0;
}

