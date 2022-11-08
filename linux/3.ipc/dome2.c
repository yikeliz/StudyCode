#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>


//int mkfifo(const char *pathname, mode_t mode);

int main()
{
	if(mkfifo("file",0600) == -1 && errno != EEXIST)
	{
		printf("mkfifo failed\n");
		perror("why");
		
	}
	


	return 0;
}

