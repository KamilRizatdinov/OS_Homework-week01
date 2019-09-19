#include<stdio.h> 
#include<string.h> 
#include<pthread.h> 
#include<stdlib.h> 
#include<unistd.h> 

#define BUFFER_SIZE 10
#define THREADS_NUM 2

int counter = 0;
int buffer[BUFFER_SIZE];
pthread_t thread_ids[THREADS_NUM];
pthread_mutex_t my_mutex;
pthread_cond_t my_cond;


void* producer(void* arg) {
   while(1) {
   	pthread_mutex_lock(&my_mutex);

	if (counter == BUFFER_SIZE) {
	    pthread_cond_signal(&my_cond);
	    pthread_cond_wait(&my_cond, &my_mutex);
	}
	
	pthread_mutex_unlock(&my_mutex);
	buffer[counter++] = 1;	
	printf("[PRODUCER]: Counter = %d\n", counter);	
   }
}


void* consumer(void* arg) {
   while(1) {
   	pthread_mutex_lock(&my_mutex);

	if (counter == 0) {
	    pthread_cond_signal(&my_cond);
	    pthread_cond_wait(&my_cond, &my_mutex);
	}
	
	pthread_mutex_unlock(&my_mutex);
	buffer[--counter] = 0;	
	printf("[CONSUMER]: Counter = %d\n", counter);	
   }
}


int main(void) {
    pthread_mutex_init(&my_mutex, NULL);
    pthread_cond_init(&my_cond, NULL);
       
    pthread_create(&thread_ids[0], NULL, &producer, NULL);
    pthread_create(&thread_ids[1], NULL, &consumer, NULL); 

    for (int i=0; i<THREADS_NUM; ++i) {
        pthread_join(thread_ids[i], NULL);
    }
    
    pthread_mutex_destroy(&my_mutex);
    pthread_cond_destroy(&my_cond);
    return 0;
}
