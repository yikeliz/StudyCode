#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	pid_t pida = 0;
	int data = 0;
	int status = 10;
	pida = fork();

	if(pida >0 )
	{
		printf("child quit,child status = %d\n",WEXITSTATUS(status));
	}
	else if(pida == 0){
		while(1){
			printf("This is child fork,pid = %d,father pid = %d\n",getpid(),getppid());
			sleep(1);
			data++;
			if(data == 4){	
				exit(2);
			}
		}
	}
	
	return 0;
}

