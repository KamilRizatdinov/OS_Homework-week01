#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void myHandler(int);

int main() {
    int pid;
    pid = fork();
    int fd[2];

    if (pid == 0) { // First child
	raise(SIGSTOP);
	int cpid = 0;

	read(fd[0], &cpid, sizeof(cpid));
	printf("[FIRST CHILD] Get second child's pid\n");
	sleep(3);
	printf("[FIRST CHILD] Sending SIGTERM signal to second child\n");
	kill(cpid, SIGTERM);

    } else if (pid > 0) {
	printf("[MAIN] Created first child\n");
	int cpid = (int)fork();
if (cpid == 0) { // Second child
	    signal(SIGTERM, myHandler);
	    while (1) {
		printf("[SECOND CHILD] I am still alive!\n");
		sleep(1);
	    }

	} else if (cpid > 0) { // Main process
    	    waitpid(pid, NULL, WUNTRACED);
	    printf("[MAIN] Created second child\n");
	    int status;
	    write(fd[1], &cpid, sizeof(cpid));
    	    kill(pid, SIGCONT);
	    waitpid(cpid, &status, 0);
	    wait(NULL);
	}

    } else {
	exit(1); 
    }
}

void myHandler(int signal) {
    printf("[%d] Bye :(", signal);
    exit(0);
}
