#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void myHandler(int);

int main() {
    int pid;
    pid = fork();

    if (pid == 0) {
	signal(SIGTERM, myHandler);
	while(1) {
	    printf("I am alive!\n");
	    sleep(1);
	}
    } else if (pid > 0) {
	sleep(10);
	kill(pid, SIGTERM);
    } else {
	exit(1); 
    }
}

void myHandler(int signal) {
    printf("[%d] Bye :(", signal);
    exit(0);
}
