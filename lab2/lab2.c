#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bench(int r1, int c1, int r2, int c2) {
    int i, j, k;

    int** a = (int**)malloc(r1 * sizeof(int*));
    for (int i = 0; i < r1; i++)
    {
        a[i] = (int*)malloc(r2 * sizeof(int));
    }

    int** b = (int**)malloc(c1 * sizeof(int*));
    for (int i = 0; i < r1; i++)
    {
        b[i] = (int*)malloc(c2 * sizeof(int));
    }

    int** result = (int**)malloc(c1 * sizeof(int*));
    for (int i = 0; i < r1; i++)
    {
        result[i] = (int*)malloc(c2 * sizeof(int));
    }


    for (i = 0; i < r1; ++i)
    {
        for (j = 0; j < c1; ++j)
        {
            a[i][j] = rand() % 100 + 1;
        }
    }

    for (i = 0; i < r2; ++i)
    {
        for (j = 0; j < c2; ++j)
        {
            b[i][j] = rand() % 100 + 1;
        }
    }

    for (i = 0; i < r1; ++i)
    {
        for (j = 0; j < c2; ++j)
        {
            result[i][j] = 0;
        }
    }
    clock_t begin1 = clock();
    
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j)
            for (k = 0; k < c1; ++k)
            {
                result[i][j] += a[i][k] * b[k][j];
            }

    clock_t end1 = clock();
    double time_taken = (double)(end1 - begin1) / CLOCKS_PER_SEC;
    printf("\n \nfunction took %f seconds to execute \n", time_taken);

    for (int i = 0; i < r1; i++)
    {
        free (a[i]);
    }
    free(a);

    for (int i = 0; i < r1; i++)
    {
        free(b[i]);
    }
    free(b);
    
    for (int i = 0; i < r1; i++)
    {
        free(result[i]);
    }
    free(result);
}

void shell(int* items, int count)
{

    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
    int i, j;
    int x, y;



    i = left; j = right;

    /* выбор компаранда */
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}

int compare(const void* x1, const void* x2)
{
    return(*(int*)x1 - *(int*)x2);
}

void zadanie1() { // на случайном наборе значений массива.

    setlocale(0, "rus");

    int n = 0, i;


    printf("Size array: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) arr[i] = rand() % 100 + 1;
    clock_t start = clock();
    shell(arr, n);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\ntime shell: %f s.\n", time_spent);

    for (i = 0; i < n; i++) arr[i] = rand() % 100 + 1;
    start = clock();
    qs(arr, 0, n - 1);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\ntime qs: %f s.\n", time_spent);

    for (i = 0; i < n; i++) arr[i] = rand() % 100 + 1;
    start = clock();
    qsort(arr, n, sizeof(int), compare);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\ntime standart: %f s.\n", time_spent);
}

void mass(int* items, int count)
{
    int i = 0;
    for (i; i < count; i++) items[i] = i;
}

void mass_reverse(int* items, int count)
{
    int i = 0;
    for (i=count; i > 0; i--) items[i-1] = i;
}

void mass_polovina(int* items, int count)
{
    int i = 0;
    for (i; i < count / 2; i++) items[i] = i;
    for (i = count; i >= count / 2; i--) items[i - 1] = i;
}

void zadanie2() { // представл€ющем собой возрастающую последовательность чисел
    setlocale(0, "rus");

    int n = 0, i;
    printf("\n");
    printf("Size array: ");
    scanf("%d", &n);
    

    /*int* arr = new int[n];*/
    int* arr = (int*)malloc(n * sizeof(int));

    mass(arr, n);
    clock_t start = clock();
    shell(arr, n);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\ntime shell: %f s.\n", time_spent);

    mass(arr, n);
    start = clock();
    qs(arr, 0, n - 1);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\ntime qs: %f s.\n", time_spent);

    mass(arr, n);
    start = clock();
    qsort(arr, n, sizeof(int), compare);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\ntime standart: %f s.\n", time_spent);
}

void zadanie3() {
    setlocale(0, "rus");

    int n = 0, i;

    printf("\n");
    printf("Size array: ");
    scanf("%d", &n);

    /*int* arr = new int[n];*/
    int* arr = (int*)malloc(n * sizeof(int));

    mass_reverse(arr, n);
    clock_t start = clock();
    shell(arr, n);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\ntime shell: %f s.\n", time_spent);

    mass_reverse(arr, n);
    start = clock();
    qs(arr, 0, n - 1);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\ntime qs: %f s.\n", time_spent);

    mass_reverse(arr, n);
    start = clock();
    qsort(arr, n, sizeof(int), compare);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\ntime standart: %f s.\n", time_spent);
}

void zadanie4() {
    setlocale(0, "rus");

    int n = 0, i;

    printf("\n");
    printf("Size array: ");
    scanf("%d", &n);
    


    /*int* arr = new int[n];*/
    int* arr = (int*)malloc(n * sizeof(int));



    mass_polovina(arr, n);
    clock_t start = clock();
    shell(arr, n);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\ntime shell: %f s.\n", time_spent);

    mass_polovina(arr, n);
    start = clock();
    qs(arr, 0, n - 1);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\ntime qs: %f s.\n", time_spent);

    mass_polovina(arr, n);
    start = clock();
    qsort(arr, n, sizeof(int), compare);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\ntime standart: %f s.\n", time_spent);
}


int main()
{
    /*bench(100, 100, 100, 100);
    bench(200, 200, 200, 200);
    bench(400, 400, 400, 400);
    bench(1000, 1000, 1000, 1000);
    bench(2000, 2000, 2000, 2000);
    bench(4000, 4000, 4000, 4000);
    bench(10000, 10000, 10000, 10000);*/
    zadanie1();
    zadanie2();
    zadanie3();
    zadanie4();
}