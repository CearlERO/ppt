#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	FILE * f;
	char buf[1000];
	int len;
	memset(buf,'\0',1000);
	sprintf(buf,"I can say a, b ,c and d.");		
	f=popen("wc -w","w");
	if(f==NULL){
		perror("error in create another process!");
		exit(-1);
	}
	fwrite(buf,sizeof(char),strlen(buf),f);
	printf("finished!");
	pclose(f);
	exit(0);

}
