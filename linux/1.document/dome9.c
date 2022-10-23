#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>



struct Test
{
	int len;
	char name;


};
int main(void)
{

	int fd;
	struct Test  data1[2] = {{10,'a'},{11,'b'}};
	struct Test  data2[2];

	fd = open("./file1",O_RDWR|O_CREAT,0600);
		
	write(fd,&data1,sizeof(struct Test)*2);
	
	lseek(fd,0,SEEK_SET);

	read(fd,&data2,sizeof(struct Test)*2);

	printf("read is %d,%c\n",data2[0].len,data2[0].name);	
	printf("read is %d,%c\n",data2[1].len,data2[1].name);	
	return 0;



}
