#include <stdio.h>
#include <windows.h>

#define ARR_SIZE 10

// x2 для последнего четного
// Сколько четных левее минимального

void inputValuesIntoArr(int* arr, int arrSize);
void multiplyAllOdds(int* arr, int arrSize, int num);
void multiplyLastEven(int* arr, int arrSize, int num);
int findMinElement(int* arr, int arrSize);
int howManyItemsMoreThan(int* arr, int arrSize, int moreNumber);
int howManyEvenLeftOfMinimal(int* arr, int arrSize);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr[ARR_SIZE];
	int choice;

	for (int i = 0; i < ARR_SIZE; i++) {
		arr[i] = 0;
	}

	while (1 == 1) {

		printf("\n--------------------------\n");
		printf("Содержимое массива: { ");
		for (int i = 0; i < ARR_SIZE; i++) {
			printf("%d ", arr[i]);
		}
		printf("}\n");
		printf("Выберите нужную операцию:\n");
		printf("1. Ввести с клавиатуры массив\n");
		printf("2. x10 для всех нечетных элементов\n");
		printf("3. Найти минимальный элемент\n");
		printf("4. Сколько элементов больше чем 10\n");
		printf("5. x2 для последнего четного элмента\n");
		printf("6. Сколько четных левее минимального\n");
		printf("\n");
		printf("0. Выйти из программы\n");
		printf(">> ");

		scanf_s("%d", &choice);
		switch (choice)
		{
			case 1: {
				inputValuesIntoArr(arr, ARR_SIZE);
				break;
			}
			case 2: {
				multiplyAllOdds(arr, ARR_SIZE, 10);
				break;
			}
			case 3: {
				int minElement = findMinElement(arr, ARR_SIZE);
				printf("Минимальный элемент: %d", minElement);
				break;
			}
			case 4: {
				int num = howManyItemsMoreThan(arr, ARR_SIZE, 10);
				printf("Чисел больше чем 10: %d\n", num);
				break;
			}
			case 5: {
				multiplyLastEven(arr, ARR_SIZE, 2);
				break;
			}
			case 6: {
				int nums = howManyEvenLeftOfMinimal(arr, ARR_SIZE);
				printf("Четных чисел левее минимального: %d", nums);
				break;
			}
			case 0: {
				exit(0);
				break;
			}
		}
	}
}
int howManyEvenLeftOfMinimal(int* arr, int arrSize) {
	int minimalNumIdx = 0;
	int min = arr[0];
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] < min) {
			min = arr[i];
			minimalNumIdx = i;
		}
	}
	int n = 0;
	for (int i = 0; i < minimalNumIdx; i++) {
		if (arr[i] % 2 == 0) {
			n++;
		}
	}
	return n;
}

void multiplyLastEven(int* arr, int arrSize, int num) {
	for (int i = arrSize - 1; i > 0; i--) {
		if (arr[i] % 2 == 0) {
			arr[i] *= num;
			return;
		}
	}
}

int howManyItemsMoreThan(int* arr, int arrSize, int moreNumber) {
	int n = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > moreNumber) {
			n++;
		}
	}
	return n;
}

void inputValuesIntoArr(int* arr, int arrSize) {
	printf("Введите %d чисел: ", arrSize);
	for (int i = 0; i < arrSize; i++) {
		scanf_s("%d", &arr[i]);
	}
}

void multiplyAllOdds(int* arr, int arrSize, int num) {
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] % 2 != 0) {
			arr[i] *= num;
		}
	}
}

int findMinElement(int* arr, int arrSize) {
	int min = arr[0];
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}