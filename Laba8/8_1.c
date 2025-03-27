#include <stdio.h>
#include <windows.h>

void aboutMe() {
	printf("ИМЯ !!!!!\n");
	printf("ФАМИЛИЯ !!!!!\n");
	printf("ОТЧЕСТВО !!!!!\n");
	printf("\n");
	printf("Группа: !!!!!\n");
	printf("Дата: 12.03.25 !!!!!\n");
	printf("Предмет: Основы программирования\n");
	printf("Лабораторная работа №8\n");
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	aboutMe();
}