#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void * sellTicket(void *args);
pthread_mutex_t mut;	
int ticket=10;
int main(){
	int res;
	pthread_t th[3];
	pthread_t thP;
	void * th_rz;
	res = pthread_mutex_init(&mut,NULL);
	if(res!=0){
		perror("Mutex initialization failed.");	
		exit(EXIT_FAILURE);
	}
	int arg=0;
	res=pthread_create(&th[0],NULL,sellTicket,&arg);
	if(res!=0){
		perror("thread[0] creation failed.");	
		exit(EXIT_FAILURE);
	}
	int arg1=1;
	res=pthread_create(&th[1],NULL,sellTicket,&arg1);
	if(res!=0){
		perror("thread[1] creation failed.");	
		exit(EXIT_FAILURE);
	}
	int arg2=2;
	res=pthread_create(&th[2],NULL,sellTicket,&arg2);
	if(res!=0){
		perror("thread[2] creation failed.");	
		exit(EXIT_FAILURE);
	}

	pthread_join(th[0],&th_rz);
	pthread_join(th[1],&th_rz);
	pthread_join(th[2],&th_rz);
	pthread_mutex_destroy(&mut);
	exit(EXIT_SUCCESS);
}
void * sellTicket(void *args){
	int i= *(int *)args;
	while(1){
		pthread_mutex_lock(&mut);
		if(ticket<1){ 
			pthread_mutex_unlock(&mut);
			break;
		}
		printf("thread %d is selling ticket %d.\n",i,ticket);
		ticket--;
		pthread_mutex_unlock(&mut);
		sleep(1);
	}
	pthread_exit(NULL);
}


