#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	pid_t pida = 0;
	int data = 0;

	while(1){		
		printf("please input your data\n");
		scanf("%d",&data);
		if(data == 1)
		{
			pida = fork();
			if(pida >0 )
			{
			}
			else if(pida == 0){
				while(1)
				{
					printf("witing child data,pid is %d\n",getpid());
					sleep(3);
				}
			}
		}
		else{
			printf("witing father data\n");

        	}



	}
	return 0;
}

