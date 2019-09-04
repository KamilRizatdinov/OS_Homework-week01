#include <stdio.h>


void bubble_sort(int arr[], int length) {
    for (int i = 0; i < length-2; ++i) {
        for (int j = 0; j < length-1; ++j) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}


int main() {
    int length = 10;
    int array[10] = {5, 7, 9, 2, 1, 0, 3, 4, 6, 8};
    bubble_sort(array, length);

    for (int i = 0; i < length; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
