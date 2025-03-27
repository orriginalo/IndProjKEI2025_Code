#include <stdio.h>
#include <Windows.h>

void main() {
  int a, b, c, max;

  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  printf("Введите 3 числа: ");
  scanf_s("%d %d %d", &a, &b, &c);

  max = a;
  if (b > max) {
    max = b;
  }
  if (c > max) {
    max = c;
  }

  printf("max = %d", max);
}
