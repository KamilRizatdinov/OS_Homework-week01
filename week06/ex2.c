#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h> 

int main() {
    char string[10] = "1234567890";
    char result[10];
    int fds[2], pid;
    
    if (pipe(fds) < 0) exit(1); 
    pid = fork();

    if (pid == 0) {
	read(fds[0], result, 10);
	printf("[CHILD] result: %s\n", result);
    } else if (pid > 0) {
	printf("[MAIN] string: %s\n", string);
	write(fds[1], string, 10);
	wait(NULL);
    } else {
   	exit(1); 
    }
}
