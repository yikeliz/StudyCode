#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv)
{

	char *readbuf = NULL;

	int fp = open(argv[1],O_RDWR);
	printf("fp = %d\n",fp);

	int bufsize = lseek(fp,0,SEEK_END);	
	lseek(fp,0,SEEK_SET);

	readbuf = (char *)malloc(sizeof(char)*bufsize + 8);

	read(fp,readbuf,bufsize);
				
	char *p = strstr(readbuf,"LONG=");

	p += strlen("LONG=");
	*p = '5';

	lseek(fp,0,SEEK_SET);
	write(fp,readbuf,strlen(readbuf));
				
	printf("work finsh\n");
	close(fp);

	return 0;
}
			
