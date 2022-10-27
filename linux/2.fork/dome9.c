#include <unistd.h>
#include <stdio.h>



//execl(const char *path, const char *arg, ...

int main(void)
{
	
	if(execl("/bin/ls","ls","-l", NULL)==-1)
	{
		printf("error\n");
		perror("why");

	}
	else{
		printf("over\n");
	}




	return 0;
}



