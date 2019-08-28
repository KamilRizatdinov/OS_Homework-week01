#include <stdio.h>
#include <string.h>
     
int main() {
    char arr[100];

    printf("Enter a string\n");
    fgets(arr, 100, stdin);

    for (int i = strlen(arr); i >= 0; --i) {
        printf("%c", arr[i]);
    }
    printf("\n");

    return 0;
}
