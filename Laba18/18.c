#include <stdio.h>
#include <windows.h>

#define ARR_SIZE 20

int n = ARR_SIZE / 2;

void inputValuesIntoArr(int* arr, int arrSize);
void multiplyAllOdds(int* arr, int arrSize, int num);
void multiplyLastEven(int* arr, int arrSize, int num);
int findMinElement(int* arr);
int findMaxElement(int* arr);
int howManyItemsMoreThan(int* arr, int arrSize, int moreNumber);
int howManyEvenLeftOfMinimal(int* arr, int arrSize);
void deleteElement(int* arr, int delIndex);
void insertElement(int* arr, int idx, int value);
void printElements(int* arr);
void multiplyAllOddsRightOfMinimal(int* arr, int num);
void switchMinMax(int* arr);
int getMinElementIdx(int* arr);
int getMaxElementIdx(int* arr);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr[ARR_SIZE] = {0};
	int choice;

	while (1 == 1) {

		printf("\n--------------------------\n");
		printf("Содержимое массива:");
		printElements(arr);
		printf("Выберите нужную операцию:\n");
		printf("1. Ввести с клавиатуры массив\n");
		printf("2. x10 для всех нечетных элементов\n");
		printf("3. Найти минимальный элемент\n");
		printf("4. Сколько элементов больше чем 10\n");
		printf("5. x2 для последнего четного элмента\n");
		printf("6. Сколько четных левее минимального\n");
		printf("7. x10 для нечетных правее минимального\n");
		printf("8. Переставить местами min и max\n");
		printf("11. Удалить заданный элемент\n");
		printf("12. Вставить новый элемент в заданное место\n");
		printf("13. Удалить минимальный элемент\n");
		printf("\n");
		printf("0. Выйти из программы\n");
		printf(">> ");

		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: {
			inputValuesIntoArr(arr, n);
			break;
		}
		case 2: {
			multiplyAllOdds(arr, n, 10);
			break;
		}
		case 3: {
			int minElement = findMinElement(arr);
			printf("Минимальный элемент: %d", minElement);
			break;
		}
		case 4: {
			int num = howManyItemsMoreThan(arr, n, 10);
			printf("Чисел больше чем 10: %d\n", num);
			break;
		}
		case 5: {
			multiplyLastEven(arr, n, 2);
			break;
		}
		case 6: {
			int nums = howManyEvenLeftOfMinimal(arr, n);
			printf("Четных чисел левее минимального: %d", nums);
			break;
		}
		case 7: {
			multiplyAllOddsRightOfMinimal(arr, 10);
			break;
		}
		case 8: {
			switchMinMax(arr);
			break;
		}
		case 11: {
			printf("Укажите индекс элемента для удаления: ");
			int idx;
			scanf_s("%d", &idx);
			deleteElement(arr, idx);
			break;
		}
		case 12: {
			int idx, val;
			printf("Укажите индекс элемента для вставки: ");
			scanf_s("%d", &idx);
			printf("Укажите значение: ");
			scanf_s("%d", &val);
			insertElement(arr, idx, val);
			break;
		}
		case 13: {
			int minNumIdx = getMinElementIdx(arr);
			deleteElement(arr, minNumIdx);
			break;
		}
		case 0: {
			exit(0);
			break;
		}
		}
	}
}

int getMinElementIdx(int* arr) {
	int minNumIdx = 0;
	int min = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
			minNumIdx = i;
		}
	}
	return minNumIdx;
}

int getMaxElementIdx(int* arr) {
	int maxNumIdx = 0;
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
			maxNumIdx = i;
		}
	}
	return maxNumIdx;
}

void insertElement(int* arr, int idx, int value) {
	for (int i = n; i > idx; i--) {
		arr[i] = arr[i - 1];
	}
	n++;
	arr[idx] = value;
}

void printElements(int* arr) {
	printf("< ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf(">\n");
}

void deleteElement(int* arr, int delIndex) {
	for (int i = 0; i < n; i++) {
		if (i >= delIndex) {
			arr[i] = arr[i + 1];
		}
	}
	n--;
}

void multiplyAllOddsRightOfMinimal(int* arr, int num) {
	int minimalNumIdx = 0;
	int min = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
			minimalNumIdx = i;
		}
	}
	for (int i = n; i > minimalNumIdx; i--) {
		if (arr[i] % 2 != 0) {
			arr[i] *= num;
		}
	}
}

void switchMinMax(int* arr) {
	int max = findMaxElement(arr);
	int min = findMinElement(arr);

	int maxIdx = getMaxElementIdx(arr);
	int minIdx = getMinElementIdx(arr);

	arr[minIdx] = max;
	arr[maxIdx] = min;
}

int howManyEvenLeftOfMinimal(int* arr, int arrSize) {
	int minNumIdx = getMinElementIdx(arr);
	int n = 0;
	for (int i = 0; i < minNumIdx; i++) {
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
	n = ARR_SIZE / 2;
}

void multiplyAllOdds(int* arr, int arrSize, int num) {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0) {
			arr[i] *= num;
		}
	}
}

int findMinElement(int* arr) {
	int min = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

int findMaxElement(int* arr) {
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}