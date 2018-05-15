#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
void * consumer(void *args);
void * productor(void *args);
sem_t sem;	
sem_t sem2;
char * buf;
int main(){
	int res;
	pthread_t thC;
	pthread_t thP;
	void * th_rz;
	buf = (char *) malloc(100);
	res = sem_init(&sem,0,0);
	if(res!=0){
		perror("Semaphore initialization failed.");	
		exit(EXIT_FAILURE);
	}
	res = sem_init(&sem2,0,1);
	if(res!=0){
		perror("Semaphore initialization failed.");	
		exit(EXIT_FAILURE);
	}
	res=pthread_create(&thC,NULL,consumer,NULL);
	if(res!=0){
		perror("threadC creation failed.");	
		exit(EXIT_FAILURE);
	}
	res=pthread_create(&thP,NULL,productor,NULL);
	if(res!=0){
		perror("threadA creation failed.");	
		exit(EXIT_FAILURE);
	}

	pthread_join(thC,&th_rz);
	pthread_join(thP,&th_rz);
	sem_destroy(&sem);
	sem_destroy(&sem2);
	exit(EXIT_SUCCESS);
}

void * consumer(void * args){
	while(1){
		sem_wait(&sem);
		printf("consumer:\n");	
		printf("the content in buf is:%s.\n",buf);
		sem_post(&sem2);
	}
	pthread_exit(NULL);
}
void * productor(void * args){
	while(1){
		sem_wait(&sem2);
		printf("productor:\n");	
		printf("input something:\n");
		fgets(buf,100,stdin);
		sem_post(&sem);
	}
	pthread_exit(NULL);
}
