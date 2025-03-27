#include <stdio.h>
#include <Windows.h>

void main() {

  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  int temp;

  printf("Введите температуру в помещении: ");
  scanf_s("%d", &temp);

  if (temp < 18) {
    printf("Холодно\n");
  } 
  else if (temp >= 18 && temp < 22) {
    printf("Прохладно\n");
  }
  else if (temp >= 22 && temp < 26) {
    printf("Тепло\n");
  }
  else if (temp >= 26) {
    printf("Жарко\n");
  }
}
