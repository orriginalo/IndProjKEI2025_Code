#include <stdio.h>
#include <windows.h>

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float height = 12;
    float g = 9.81;
    float result = height / g;
    printf("Предмет падает с высоты %.1f метров", height);
    printf("Он коснется земли через %.2f секунд", result);
}