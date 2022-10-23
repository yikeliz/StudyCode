#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
		
	int n_write = write(fd,buf,strlen(buf));
	if(n_write != -1){
		printf("write %d byte to file\n",n_write);
	
	}

	char *readbuf;
	readbuf = (char *)malloc(sizeof(char)*n_write + 1);
	
	lseek(fd, 0, SEEK_SET);

	int n_read = read(fd, readbuf, n_write);

	printf("read %d,context:%s\n",n_read, readbuf);

	close(fd);

	return 0;
}



