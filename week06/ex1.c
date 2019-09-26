#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main() {
    char string1[1] = "K";
    char string2[1];
    int fds[2];

    if (pipe(fds) < 0)
   	exit(1); 

    printf("string 1: %s\n", string1);
    printf("string 2: %s\n", string2);

    write(fds[1], string1, 1);
    write(fds[1], string2, 1);
    read(fds[0], string2, 1);
    read(fds[0], string1, 1);

    printf("string 1: %s\n", string1);
    printf("string 2: %s\n", string2);
}
