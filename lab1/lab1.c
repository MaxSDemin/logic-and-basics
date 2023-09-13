#include <stdio.h>


int   main(void)
{
    int temp, n = 10, i = 0;

    int a[10] = { 0,1,2,3,4,5,6,7,8,9 };

    /*while (i < n / 2)
    {
        temp = a[i];
        a[i] = a[9 - i];
        a[9 - i] = temp;
        i++;
    }*/

    int min = 0, max = 0;
    for (int i = 1; i < 10; ++i) {
        if (a[i] < a[min]) min = i;
        if (a[i] > a[max]) max = i;
    }
    printf("%d - %d = %d\n", a[max], a[min], a[max] - a[min]);
    i = 0;
    while (i < n) printf(" %d", a[i++]);
}
