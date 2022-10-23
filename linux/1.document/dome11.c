#include <stdio.h>
#include <string.h>

//FILE *fopen(const char *pathname, const char *mode);
//size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
//size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);


struct student
{
	char *name;
	int   age;  
};

int main(void)
{
	FILE *fp;

	struct student stu1[2] = {{"li",10},{"zhang",12}};

	struct student stu2[2] = {0};

	fp = fopen("./file1","w+");
			
	fwrite(stu1,sizeof(struct student)*2,1,fp);
	fseek(fp,0,SEEK_SET);
	fread(stu2,sizeof(struct student)*2,1,fp);

	printf("name is %s,age is %d\n",stu2[0].name,stu2[0].age);
	printf("name is %s,age is %d\n",stu2[1].name,stu2[1].age);
	
	fclose(fp);
	


	return 0;
}
