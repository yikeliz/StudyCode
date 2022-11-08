#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//int mkfifo(const char *pathname, mode_t mode);

int main()
{
	char buf[128] = {0};
	int cet = 0;
	int nread;
	if(mkfifo("./file",0600) == -1 && errno != EEXIST)
	{
		printf("mkfifo failed\n");
		perror("why");
		
	}
	
	int fd = open("./file",O_RDONLY);
	while(cet<3){
		cet++;
		sleep(2);
		nread += read(fd,buf,30);
	}
	printf("read %d byte,conent is %s \n",nread,buf);
	
	printf("read succesed\n");
	
	close(fd);
	return 0;
}

