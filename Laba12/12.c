#include <stdio.h>
#include <Windows.h>

void Task1() {
	printf("Task1() START\n");
	int n, m;
	printf("n=");
	scanf_s("%d", &n);
	printf("m=");
	scanf_s("%d", &m);
	int i = 1;
	do {
		int j = 1;
		do {
			printf("%d ", i * 10 + j);
			j++;
		} while (j <= m);
		printf("\n");
		i++;
	} while (i <= n);
	printf("Task1() FINISH\n");
}

void Task2() {
	printf("Task2() START\n");
	int i = 1;
	do {
		int j = 1;
		do {
			printf("%3d ", i * j);
			j++;
		} while (j <= 10);
		printf("\n");
		i++;
	} while (i <= 10);
	printf("Task2() FINISH\n");
}

void Task3() {
	printf("Task3() START\n");
	int i = 1;
	do {
		int j = 1;
		do {
			printf("%d ", j);
			j++;
		} while (j <= i);
		printf("\n");
		i++;
	} while (i <= 5);
	printf("Task3() FINISH\n");
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int variant = 0;
	printf("\n");
	printf("Выберие нужную вам операцию:\n");
	printf("1. Задача 1 (i * 10 + j)\n");
	printf("2. Задача 2 (Таблица Пифагора)\n");
	printf("3. Задача 3 (Рисунок по варианту)\n");
	printf("\n0. Выйти из программы.\n");
	printf(">> ");

	scanf_s("%d", &variant);

	switch (variant)
	{
	case 1:
		Task1();
		break;
	case 2:
		Task2();
		break;
	case 3:
		Task3();
		break;
	}
}