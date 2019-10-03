#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void* myRealloc(void* ptr, size_t old_size, size_t new_size) {
    if (ptr == NULL) {
   	return malloc(new_size);
    } else if (new_size == 0) {
   	free(ptr);
	return NULL;
    } else if (new_size <= old_size) {
	return ptr;
    } else {
   	void* new_mem = malloc(new_size);
	new_mem = memcpy(new_mem, ptr, old_size);
	return new_mem;
    }
}


int main(){
    int* array;
    array = (int*)calloc(5, sizeof(int));
    array = (int*)myRealloc(array, sizeof(int)*5, sizeof(int)*10);
     
    return 0;
}
