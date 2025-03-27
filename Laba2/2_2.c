#include <stdio.h>
#include <windows.h>

void main() {
    float height;
    float g = 9.81;
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Введите высоту в метрах: ");
    scanf_s("%f", &height);
    printf("Предмет падает с высоты %.1f метров", height);
    float result = height / g;
    printf("Он коснется с земли через %.1f", result);
}