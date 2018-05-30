#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	mkfifo("/tmp/myfifo",0777);

	int fd = open("/tmp/myfifo",O_WRONLY);

	int i=0;
	char c = 'a';
	for(i=0;i<20;i++){
		
		write(fd,&c,1);
		c++;
		sleep(1);
	}
	close(fd);
	exit(0);
}
