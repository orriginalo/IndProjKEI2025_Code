#include <stdio.h>
#include <Windows.h>
#include <ctype.h>

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char s[80];
    printf("Введите строку: ");
    fgets(s, 79, stdin);

    printf("Вы ввели строку: %s\n", s);

    int counter = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            s[i] = '$';
        }
    }
    printf("Строка после обработки: %s", s);
}