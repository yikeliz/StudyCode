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
	int char_sizeof = lseek(fd, 0, SEEK_END);

	printf("file sizeof is %d\n",char_sizeof);
	close(fd);

	return 0;
}



