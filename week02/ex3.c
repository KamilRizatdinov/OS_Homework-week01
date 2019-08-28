#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int height = atoi(argv[1]);
    int current = 1;
    int width =  (height * 2) - 1;

    for (int i = 1; i <= height; ++i) {
        for (int k = 0; k < (width - current) / 2; ++k) {
            printf(" ");
        }

        for (int j = 0; j < current; ++j) {
            printf("*");
        }

        printf("\n");
        current+=2;
    }

    return 0;
}
