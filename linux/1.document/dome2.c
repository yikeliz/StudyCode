#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
	int fd;
	char *buf = "一颗例子";
	fd = open("./file1",O_RDWR);

	if(fd == -1){
		
		printf("open file1 fail\n");
		fd = open("./file1",O_RDWR|O_CREAT,0600);
		if(fd > 0){
		
			printf("creat file1\n");
		}
	
	}

	printf("success! fd = %d\n",fd);

	write(fd,buf,strlen(buf));

	close(fd);

	return 0;
}



