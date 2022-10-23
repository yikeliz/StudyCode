#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main(void)
{
	int fd;
	
	fd = open("./file1",O_RDWR);

	if(fd == -1){
		
		printf("open file1 fail\n");
		fd = open("./file1",O_RDWR|O_CREAT,0600);
		if(fd > 0){
		
			printf("creat file1\n");
		}
	
	
	}

	return 0;
}



