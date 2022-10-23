#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
	int fdScr;
	int fdDis;

	char *readbuf = NULL;

	if(argc != 3){
		printf("parrarm error\n");
		exit(-1);

	}	
	fdScr = open(argv[1],O_RDWR);

	int Scr_size = lseek(fdScr, 0, SEEK_END);
        lseek(fdScr, 0, SEEK_SET);
	
	readbuf = (char *)malloc(sizeof(char)*Scr_size + 8);


	int n_read = read(fdScr, readbuf, Scr_size);
	
		
	fdDis = open(argv[2],O_RDWR|O_CREAT|O_TRUNC, 0600);

	write(fdDis, readbuf, strlen(readbuf));
		
	close(fdScr);
	close(fdDis);

	return 0;
}



