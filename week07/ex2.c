#include <stdio.h>
#include <stdlib.h>


int main() {
    int number;
    int* array;

    printf("Give me a number\n");
    scanf("%d", &number);
    array = (int*)calloc(number, sizeof(int));

    for (int i = 0; i < number; ++i) {
    	array[i] = i; 
	printf("%d\n", array[i]);
    }
    
    free(array); 
    return 0;
}
