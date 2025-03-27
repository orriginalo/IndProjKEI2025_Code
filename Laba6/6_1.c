#include <stdio.h>

int main() {
	int i;
	int n;

	printf("n = ");
	scanf_s("%d", &n);

	i = 1;
	do {
		printf("%d ", i);
		i++;
	} while (i <= n);
}