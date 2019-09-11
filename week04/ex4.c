#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    pid_t id = fork();

    if (id == 0) {
	char** array = malloc((argc-1) * sizeof(char));

	for (int i = 1; i <= argc-1; ++i) {
	    array[i-1] = argv[i]; 
	}

	execvp(argv[0], array);
    } else if (id > 0) {
	pid_t status;
	waitpid(id, &status ,0);
    } else {
	return -1;
    }

    return 0;
}
