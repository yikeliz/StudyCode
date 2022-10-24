#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	pid_t pida = 0;
	pid_t pidb = 0;
 	int data;


	pida = getpid();
	printf("before fork pid = %d\n",pida);

	pidb = fork();

	if(pidb > 0)
	{
		printf("father fork,%d\n",getpid());
		data = 10;
	}
	else{

		printf("child fork,%d\n",getpid());
		data = 20;
        }
	
	printf("data=%d,地址是%p这个\n",data,&data);
	return 0;
}

