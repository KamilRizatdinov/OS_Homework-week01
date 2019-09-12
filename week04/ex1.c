#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/* Program which forks process into two: Parent and Child
 * If fork() functon returns value greater than 0 - it is a Parent process
 * If fork() function returns 0 - it is a Child process*/

int main() {
    pid_t n = fork();

    if (n == 0) {
        printf("Hello from child [PID - %d]\n", getpid());
    } else if (n > 0) {
        printf("Hello from parent [PID - %d]\n", getpid());
    }

    return 0;
} 
