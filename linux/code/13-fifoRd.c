#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
	int fd = open("/tmp/myfifo",O_RDONLY);
	char buf;
	int len=read(fd,&buf,1);
	while(len>0){
		printf("the fifo content is:%c\n",buf);
		len=read(fd,&buf,1);
	}
	close(fd);
	exit(0);
		
}
