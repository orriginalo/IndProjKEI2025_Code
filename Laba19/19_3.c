#include <stdio.h>
#include <Windows.h>

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char s[80];
    printf("Введите строку: ");
    fgets(s, 79, stdin);

    printf("Вы ввели строку: %s\n", s);

    int counter = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ' ') {
            counter++;
        }
    }
    printf("В ней %d пробелов.", counter);
}