#include<stdio.h> 
#include<string.h> 
#include<pthread.h> 
#include<stdlib.h> 
#include<unistd.h> 

pthread_t threads[5]; 
pthread_mutex_t lock; 

void* func(void *arg) { 
    pthread_mutex_lock(&lock);
    printf("CHILD: Hello from thread %lu!\n", pthread_self()); 
    printf("CHILD: Bye from thread %lu!\n", pthread_self()); 
    pthread_mutex_unlock(&lock);
    
    return NULL; 
} 

int main(void) { 
    int i = 0; 
    if (pthread_mutex_init(&lock, NULL) != 0)
	printf("MAIN: Something went wrong while initializint the lock");

    for (int i = 0; i < 5; ++i) { 
	int status = pthread_create(&(threads[i]), NULL, &func, NULL); 

	if (status == 0) 
	    printf("MAIN: Created tread: %lu\n", threads[i]);
	else if (status != 0) 
	    printf("MAIN: Exception occured while creating the thread\n"); 
	sleep(1);
    } 


    for (int i = 0; i < 5; ++i) {
	pthread_join(threads[i], NULL); 
    }

    pthread_mutex_destroy(&lock);
    return 0; 
} 

