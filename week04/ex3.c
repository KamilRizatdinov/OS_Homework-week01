#include <stdlib.h>
#include <stdio.h>

#define MAX_LEN 100

int main() {
    char str[MAX_LEN];
    fgets(str, MAX_LEN, stdin);

    system(str);
    return 0;
}
