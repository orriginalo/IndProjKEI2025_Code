#include <stdio.h>

int main() {
	int sum;
	int year;
	float percent;

	printf("Summa = ");
	scanf_s("%d", &sum);

	printf("Procent = ");
	scanf_s("%f", &percent);

	year = 0;
	do {
		printf("%d RUB in %d year\n", sum, year);
		sum = sum + (sum * (percent / 100));
		year++;
	} while (year <= 10);
}