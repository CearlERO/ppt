#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int fd[2];
	pid_t cpid;
	char buf[100];
	char * data="data to be sent.";
	int len;

	memset(buf,'\0',sizeof(buf));

	if(pipe(fd)==0){
		printf("pipe[0]:%d\n",fd[0]);
		printf("pipe[1]:%d\n",fd[1]);
		cpid=fork();
		if(cpid==-1){
			perror("fork error!");
			exit(-1);
		}
	

	if(cpid==0){
		len=read(fd[0],buf,100);
		printf("read %d bytes, it is: %s.\n",len,buf);
		exit(0);	
	}else{
		len=write(fd[1],data,strlen(data));
		printf("wrote %d bytes to another process.\n",len);
	}

	}
	exit(0);

}
