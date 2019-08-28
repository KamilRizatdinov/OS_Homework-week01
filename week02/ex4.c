#include <stdio.h>

void swap(int* num1, int* num2) {
    int tmp;
    tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

int main() {
    int num1;
    int num2;

    scanf("%d %d", &num1, &num2);
    swap(&num1, &num2);
    printf("%d %d", num1, num2);
    return 0;
}
