#include <stdio.h>
#include <windows.h>

void main() {
    float s;
    float price;
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Введите площадь квартиры: ");
    scanf_s("%f", &s);
    printf("Введите стоимость 1 квадратного метра квартиры RUB: ");
    scanf_s("%f", &price);
    float result = s * price;
    printf("Квартира площадью %.1f по цене %.1f RUB за кв.м стоит %.1f RUB", s, price, result);
}