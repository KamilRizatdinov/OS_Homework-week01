#include <stdio.h>
#include <string.h>

char** swap(char* arr[]) {
    char* tmp = arr[1];
    arr[1] = arr[2];
    arr[2] = tmp;
    return arr;
}

int main(int argc, char* argv[]) {
    char** string = swap(argv);
    printf("%s %s", string[1], string[2]);
    return 0;
}
