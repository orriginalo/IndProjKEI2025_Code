#include <stdio.h>
#include <math.h>

int main() {
	int stepen = 0;
	int result = 0;

	do {
		result = pow(2, stepen);
		printf("2^%d = %d\n", stepen, result);
		stepen++;
	} while (stepen <= 5);
}