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

	char *readbuf = NULL;

	if(argc != 2){
		printf("parrarm error\n");
		exit(-1);

	}	
	fdScr = open(argv[1],O_RDWR);

	int Scr_size = lseek(fdScr, 0, SEEK_END);
        lseek(fdScr, 0, SEEK_SET);
	
	readbuf = (char *)malloc(sizeof(char)*Scr_size + 8);


	int n_read = read(fdScr, readbuf, Scr_size);
	
	char *p = strstr(readbuf,"LENG=");
	
	if(p == NULL){
		printf("NOT FIND\n");
		exit(-1);
	}			
	
	p += strlen("LENG=");
	*p = '5';

	 
        lseek(fdScr, 0, SEEK_SET);
	write(fdScr, readbuf, strlen(readbuf));
		
	close(fdScr);

	return 0;
}



