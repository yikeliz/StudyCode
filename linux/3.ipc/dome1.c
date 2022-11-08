#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd[2];
	pid_t pid;
	char buf[128];
//      int pipe(int pipefd[2]);
	
	if(pipe(fd)<0){
		printf("creat pipe failed\n");
	}
	
	pid = fork();
	if(pid < 0){
		printf("creat fork failed\n");
	}
	else if(pid > 0)
	{	
		printf("this is father\n");
		close(fd[0]);
		write(fd[1],"hello world",128);

	}
	else{
		printf("this is child\n");
		close(fd[1]);
		read(fd[0],buf,128);
		printf("read data is:%s\n",buf);
	}

	return 0;
}
