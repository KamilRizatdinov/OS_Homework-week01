#include <stdio.h>
#include <limits.h>
#include <float.h>


int main() {
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
	
    printf("Max values: %d, %f, %lf\n", a, b, c);
	printf("Sizes: %lu, %lu, %lu\n", sizeof(a), sizeof(b), sizeof(c));
	return 0;
}
