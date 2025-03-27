#include <stdio.h>
#include <Windows.h>

void main() {
  int a, b, min, max;

  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  printf("Введите первое число: ");
  scanf_s("%d", &a);
  printf("Введите второе число: ");
  scanf_s("%d", &b);

  if (a < b) {
    min = a;
    max = b;
  }
  else {
    min = b;
    max = a;
  }
  printf("Большее число = %d\n", max);
  printf("Меньшее число = %d\n", min);
}
