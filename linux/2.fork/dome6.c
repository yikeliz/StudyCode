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
		wait(&status);
		printf("child quit,child status = %d\n",WEXITSTATUS(status));
		while(1){
			printf("This is father fork,pid = %d\n",getpid());	
			sleep(1);
		}
	}
	else if(pida == 0){
		while(1){
			printf("This is child fork,pid = %d\n",getpid());
			sleep(1);
			data++;
			if(data == 3){	
				exit(2);
			}
		}
	}
	
	return 0;
}

