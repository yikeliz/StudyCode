#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{

	int fd;
	int data1 = 100;
	int data2;

	fd = open("./file1",O_RDWR|O_CREAT,0600);
		
	write(fd,&data1,sizeof(int));
	
	lseek(fd,0,SEEK_SET);

	read(fd,&data2,sizeof(int));

	printf("read is %d\n",data2);	
	return 0;



}
