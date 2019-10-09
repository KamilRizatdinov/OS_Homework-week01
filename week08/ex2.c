#include <string.h>
#include <unistd.h>
#include <stdlib.h>


int main(){
    int size = 1024*1024*10;
    int* arr = (int*)malloc(size);

    memset(arr, 0, size);
    sleep(10);
    return 0;
}
