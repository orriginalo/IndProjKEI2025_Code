#include <stdio.h>
#include <windows.h>

void print_1_10() {
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
}
void print_10_1() {
    for (int i = 10; i >= 1; i--) {
        printf("%d ", i);
    }
}
void printOdds() {
    for (int i = 1; i <= 10; i++) {
        if (i % 2 != 0) {
            printf("%d ", i);
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    do {
        printf("\nВыберите операцию:\n");
        printf("1. Вывести числа от 1 до 10\n");
        printf("2. Вывести числа от 10 до 1\n");
        printf("3. Вывести 5 первых нечетных чисел начиная с 1\n");
        printf("0. Выйти из программы\n");
    
        printf(">> ");
        scanf_s("%d", &n);
    
        switch (n) {
            case 1:
                print_1_10();
                break;
            case 2:
                print_10_1();
                break;
            case 3:
                printOdds();
                break;
        }
    } while (n != 0);
}