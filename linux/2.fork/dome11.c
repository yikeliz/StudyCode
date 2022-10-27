#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


//execl(const char *path, const char *arg, ...

int main(void)
{
	FILE *fp;
	char ret[1024]={0};

	fp = popen("ls -l","r");
		
	int nread = fread(ret,1,1024,fp);

	printf("read %d byte\n %s\n",nread,ret);


	return 0;
}



