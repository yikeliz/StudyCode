#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

//int mkfifo(const char *pathname, mode_t mode);

int main()
{	
	char *str = "hello world";
	int cet = 0;
	int nwrite = 0;
	int fd = open("./file",O_WRONLY);
	while(cet<3){
		sleep(1);
		cet++;
		nwrite += write(fd,str,strlen(str));
		
	}
	printf("write %d byte\n",nwrite);
	printf("write succesed\n");

	close(fd);


	return 0;
}

