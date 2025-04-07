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
    for (int i = 0; i < strlen(s); i++) {
        s[i] = toupper(s[i]);
    }
    printf("Строка после обработки: %s", s);
}