#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6 // Размер матрицы смежности

void generateMatrix(int matrix[SIZE][SIZE]) {
    srand(time(NULL)); // Инициализация генератора случайных чисел

    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            int random = rand() % 2; // Генерация случайного числа 0 или 1
            matrix[i][j] = random;
            matrix[j][i] = random; // Заполнение элементов и их симметричных пар
        }
    }
}
int calc(int matrix[SIZE][SIZE]){
    int N = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == 1) {
                N += 1;
            }
        }
    }
    printf("Size of graf = %d", N/2);
    return 0;
}

int grafCount(int arr[SIZE][SIZE]) {
    int sum;
    for (int i = 0; i < SIZE; i++)
    {
        sum = 0;
        for (int j = 0; j < SIZE; j++)
        {
            sum += arr[i][j];
        }
        if (sum == 1) {
            printf("\n%d string: %d  vershina - koncevaya\n", i + 1, sum);
        } 
        if (sum == 0) {
            printf("\n%d string: %d  vershina - izolirovanaya\n", i + 1, sum);
        }
        if (sum == SIZE-1) {
            printf("\n%d string: %d  vershina - dominiruyshaya\n", i + 1, sum);
        }
    }
}


void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** GenerateIncidenceMatrix(int** matrix, int size)
{
    int rCount = RebrCount(matrix, size);

    int** incMatrix = GenerateMatrix(size, rCount);

    int curR = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (matrix[i][j] == 1)
            {
                incMatrix[i][curR] = 1;
                incMatrix[j][curR] = 1;
                curR++;
            }
        }
    }

    return incMatrix;
}


int main() {
    int matrix[SIZE][SIZE] = {0};

    generateMatrix(matrix);
    printMatrix(matrix);
    grafCount(matrix);
    calc(matrix);
    GenerateIncidenceMatrix(matrix);

    return 0;
}