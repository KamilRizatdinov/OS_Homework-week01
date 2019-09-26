#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void myHandler(int);

int main(void) {
    signal(SIGINT, myHandler);
    signal(SIGSTOP, myHandler);
    signal(SIGUSR1, myHandler);
    getchar(); // This line is needed to make program run infinitely
    return 0;
}

void myHandler(int signal) {
    printf("[%d] Bye :(", signal);
    exit(0);
}
