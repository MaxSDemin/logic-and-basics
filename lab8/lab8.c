#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>

void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    //Часть 1
    int size = 0;
    printf("Enter a count of headers: ");
    scanf(" %d", &size);

    srand(time(NULL)); // Инициализация генератора случайных чисел

    int** matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++)
    {
        matrix[i] = (int*)malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }


    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int random = rand() % 2; // Генерация случайного числа 0 или 1
            matrix[i][j] = random;
            matrix[j][i] = random; // Заполнение элементов и их симметричных пар
        }
    }
    printMatrix(matrix, size);


    return 0;
}
