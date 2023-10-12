#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calc(int** matrix,int size) {
    int N = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == 1) {
                N += 1;
            }
        }
    }
    N = N / 2;
    return N;
}

int grafCount(int** arr, int size) {
    int sum;
    for (int i = 0; i < size; i++)
    {
        sum = 0;
        for (int j = 0; j < size; j++)
        {
            sum += arr[i][j];
        }
        if (sum == 1) {
            printf("%d string: %d  vershina - koncevaya\n", i + 1, sum);
        }
        if (sum == 0) {
            printf("%d string: %d  vershina - izolirovanaya\n", i + 1, sum);
        }
        if (sum == size - 1) {
            printf("%d string: %d  vershina - dominiruyshaya\n", i + 1, sum);
        }
    }
}

void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int sizeOfIncGraph(int** incMatrix, int countOfEdges) {
    int count = 0;
    for (int i = 0; i < countOfEdges; i++) {
        count++;
    }
    return count;
}

int incGrafCount(int** arr, int countOfEdges, int size) {
    int sum;
    for (int i = 0; i < size; i++)
    {
        sum = 0;
        for (int j = 0; j < countOfEdges; j++)
        {
            sum += arr[i][j];
        }
        if (sum == 1) {
            printf("%d string: %d  vershina - koncevaya\n", i + 1, sum);
        }
        if (sum == 0) {
            printf("%d string: %d  vershina - izolirovanaya\n", i + 1, sum);
        }
        if (sum == size - 1) {
            printf("%d string: %d  vershina - dominiruyshaya\n", i + 1, sum);
        }
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
        for (int j = i+1; j < size; j++) {
            int random = rand() % 2; // Генерация случайного числа 0 или 1
            matrix[i][j] = random;
            matrix[j][i] = random; // Заполнение элементов и их симметричных пар
        }
    }
    printMatrix(matrix, size);
    grafCount(matrix, size);

    int count = calc(matrix,size);
    printf("Size of graf = %d\n\n", count);


    //Часть 2
    //int incMatrix = GenerateIncidenceMatrix(matrix, count);
    int** incMatrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++)
    {
        incMatrix[i] = (int*)malloc(count * sizeof(int));
    }

    int curEdge = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < count; j++)
        {
            incMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (matrix[i][j] == 1)
            {
                incMatrix[i][curEdge] = 1;
                incMatrix[j][curEdge] = 1;
                curEdge++;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < count; j++) {
            printf("%d ", incMatrix[i][j]);
        }
        printf("\n");
    }
    printf("size of graf = %d\n\n", sizeOfIncGraph(incMatrix, count));
    incGrafCount(incMatrix, count, size);

    return 0;
}