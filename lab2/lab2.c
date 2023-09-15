#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bench(int r1, int c1, int r2, int c2) {
    int i, j, k;

    int** a = (int**)malloc(r1 * r2 * sizeof(int*));
    double(*b) = malloc(c1 * c2 * sizeof(double(b)));
    double(*result)[r1][c2] = malloc(sizeof * result);

    for (i = 0; i < r1; ++i)
    {
        for (j = 0; j < c1; ++j)
        {
            (*a)[i][j] = rand() % 100 + 1;
        }
    }

    for (i = 0; i < r2; ++i)
    {
        for (j = 0; j < c2; ++j)
        {
            (*b)[i][j] = rand() % 100 + 1;
        }
    }

    for (i = 0; i < r1; ++i)
    {
        for (j = 0; j < c2; ++j)
        {
            (*result)[i][j] = 0;
        }
    }
    clock_t begin1 = clock();
    
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j)
            for (k = 0; k < c1; ++k)
            {
                (*result)[i][j] += (*a)[i][k] * (*b)[k][j];
            }

    clock_t end1 = clock();
    double time_taken = (double)(end1 - begin1) / CLOCKS_PER_SEC;
    printf("\n \nfunction took %f seconds to execute \n", time_taken);
    free(a);
    free(b);
    free(result);
}

int main()
{
    bench(1000, 1000, 1000, 1000);
    bench(2000, 2000, 2000, 2000);
}