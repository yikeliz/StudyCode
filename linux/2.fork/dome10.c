#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


//execl(const char *path, const char *arg, ...

int main(void)
{
	
	if(system("ls -l")==-1)
	{
		printf("error\n");
		perror("why");

	}
	else{
		printf("over\n");
	}




	return 0;
}



