#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	FILE * f;
	char buf[1000];
	int len;
	memset(buf,'\0',1000);
	f=popen("uname -a","r");
	sleep(5);
	if(f==NULL){
		perror("error in create another process!");
		exit(-1);
	}
	len = fread(buf,sizeof(char),1000,f);
	if(len>0){
		printf("the out put of uname -a is:\n%s\n",buf);
	}	
	printf("finished!");
	pclose(f);
	exit(0);

}
