#include <stdio.h>


//FILE *fopen(const char *pathname, const char *mode);
//size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
//size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

int main(void)
{
	FILE *fp;
	char *word = "Hello Wo";
	char Test[128] = {0};
	fp = fopen("./file1","w+");
			
	fwrite(word,sizeof(word),1,fp);
	fseek(fp,0,SEEK_SET);
	fread(Test,sizeof(word),1,fp);

	printf("read char is %s\n",Test);	
	fclose(fp);
	


	return 0;
}
