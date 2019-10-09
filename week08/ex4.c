#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/resource.h>


int main() {
    struct rusage usage;

    for (int i = 0; i < 10; ++i) {
    	int size = 1024*1024*10;
    	int* arr = (int*)malloc(size);
    	memset(arr, 0, size);

	getrusage(RUSAGE_SELF, &usage);
	printf("%ld\n", usage.ru_maxrss);
    	sleep(1);
    }

    return 0;
}
