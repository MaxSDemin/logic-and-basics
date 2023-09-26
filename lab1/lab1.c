#define _CRT_SECURE_NO_WARNINGS
#define M 4
#define N 5
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int task1() {
    /*задание1*/
    printf("/*задание1*/\n");
    int temp, n = 10, i = 0;
    int a[10] = { -9, -8, -7, -6 ,0,1,2,7,8,9 };

    int min = 0, max = 0;
    for (int i = 1; i < 10; ++i) {
        if (a[i] < a[min]) min = i;
        if (a[i] > a[max]) max = i;
    }
    printf("%s %d - %s %d = %s %d\n", "максимальный",a[max], "минимальные",a[min], "разница",a[max] - a[min]);
    i = 0;
    return 0;
}

int task2(){
    /*задание2*/
    printf("/*задание2*/\n");
    srand(time(NULL));
    int mas[10];
    for (int i = 0; i < 10; i++) {
        mas[i] = rand() % 101 - 50; // диапазон случайных чисед от 0 до 100
        printf("%d ", mas[i]);
    }
    return 0;
}

int task3(){
    /*задание3*/
    printf("\n/*задание3*/");
    int razmer, *masive, j = 0;
    printf("\nВведите размер массива: ");
    scanf("%d", &razmer);
    srand(time(0));
    masive = malloc(razmer * sizeof(int));
    printf("Сгенерированный массив:\n");
    for (j = 0; j < razmer; j++) {
        masive[j] = rand() % 101; // диапазон случайных чисед от 0 до 100
        printf("%d ", masive[j]);
    }
    free(masive);
    return 0;
}

int task4(){
    /*задание4*/
    printf("\n/*задание4*/\n");
    srand(time(NULL));
    int element;
    int matrix[M][N];

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            element = rand() % 101 - 50;
            matrix[i][j] = element;
            printf("%d ", element, "\n");
        }
        printf("\n");
    }

    for (int i = 0; i < M; ++i) {
        int strok = 0;
        for (int j = 0; j < N; ++j) {
            element = matrix[i][j];
            strok += element;
        }
        printf("%d\n", strok,"\n");
    }
    return 0;
}

int task5() {
    /*задание5*/
    printf("\n/*задание5*/\n");
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    struct student {
        char famil[20];
        char name[20], facult[20];
        int Nomzach;
    } stud[3];

    // Ввод данных о студентах
    for (int i = 0; i < 3; i++) {
        printf("Введите фамилию студента %d:\n", i + 1);
        scanf("%s", stud[i].famil);

        printf("Введите имя студента %d:\n", i + 1);
        scanf("%s", stud[i].name);

        printf("Введите название факультета студента %d:\n", i + 1);
        scanf("%s", stud[i].facult);

        printf("Введите номер зачётной книжки студента %d:\n", i + 1);
        scanf("%d", &stud[i].Nomzach);
    }

    for (int iii = 0; iii < 2; iii++) {
        // Поиск структуры с заданными параметрами
        char searchFamil[20] = "";
        char searchName[20] = "";
        int searchNomzach = 0;

        printf("Введите 1 для поиска по фамилии, 2 для поиска по имени, 3 для поиска по зачетке\n");
        int asd = 0;
        scanf("%d", &asd);

        if (asd == 1) {
            printf("Введите фамилию для поиска:\n");
            scanf("%s", searchFamil);
        }
        else if (asd == 2) {
            printf("Введите имя для поиска:\n");
            scanf("%s", searchName);
        }
        else if (asd == 3) {
           printf("Введите номер зачётной книжки для поиска:\n");
            scanf("%d", &searchNomzach);
        }
        else {
            printf("поиска не будет");
            return;
        }

        int res[4] = { 1, 1, 1, 1 };

        int found = 0; // Флаг для обозначения, было ли найдено совпадение

        for (int i = 0; i < 3; i++) {
            if (((asd == 1 && !strcmp(stud[i].famil, searchFamil)) ||
                (asd == 2 && !strcmp(stud[i].name, searchName)) ||
                (asd == 3 && stud[i].Nomzach == searchNomzach))
                && res[i] == 1)
            {
                printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d\n",
                    stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);

                found = 1; // Устанавливаем флаг, что нашли совпадение
            }
            else {
                res[i] = 0;
            }
        }
        if (!found) {
            printf("Студенты с заданными параметрами не найдены.\n");
        }
    }
    return 0;
}

int   main(void)
{
    setlocale(0, "rus");
    task1();
    task2();
    task3();
    task4();
    task5();
    return 0;
}
