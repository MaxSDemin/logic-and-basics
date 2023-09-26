#define _CRT_SECURE_NO_WARNINGS
#define M 4
#define N 5
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int task1() {
    /*�������1*/
    printf("/*�������1*/\n");
    int temp, n = 10, i = 0;
    int a[10] = { -9, -8, -7, -6 ,0,1,2,7,8,9 };

    int min = 0, max = 0;
    for (int i = 1; i < 10; ++i) {
        if (a[i] < a[min]) min = i;
        if (a[i] > a[max]) max = i;
    }
    printf("%s %d - %s %d = %s %d\n", "������������",a[max], "�����������",a[min], "�������",a[max] - a[min]);
    i = 0;
    return 0;
}

int task2(){
    /*�������2*/
    printf("/*�������2*/\n");
    srand(time(NULL));
    int mas[10];
    for (int i = 0; i < 10; i++) {
        mas[i] = rand() % 101 - 50; // �������� ��������� ����� �� 0 �� 100
        printf("%d ", mas[i]);
    }
    return 0;
}

int task3(){
    /*�������3*/
    printf("\n/*�������3*/");
    int razmer, *masive, j = 0;
    printf("\n������� ������ �������: ");
    scanf("%d", &razmer);
    srand(time(0));
    masive = malloc(razmer * sizeof(int));
    printf("��������������� ������:\n");
    for (j = 0; j < razmer; j++) {
        masive[j] = rand() % 101; // �������� ��������� ����� �� 0 �� 100
        printf("%d ", masive[j]);
    }
    free(masive);
    return 0;
}

int task4(){
    /*�������4*/
    printf("\n/*�������4*/\n");
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
    /*�������5*/
    printf("\n/*�������5*/\n");
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    struct student {
        char famil[20];
        char name[20], facult[20];
        int Nomzach;
    } stud[3];

    // ���� ������ � ���������
    for (int i = 0; i < 3; i++) {
        printf("������� ������� �������� %d:\n", i + 1);
        scanf("%s", stud[i].famil);

        printf("������� ��� �������� %d:\n", i + 1);
        scanf("%s", stud[i].name);

        printf("������� �������� ���������� �������� %d:\n", i + 1);
        scanf("%s", stud[i].facult);

        printf("������� ����� �������� ������ �������� %d:\n", i + 1);
        scanf("%d", &stud[i].Nomzach);
    }

    for (int iii = 0; iii < 2; iii++) {
        // ����� ��������� � ��������� �����������
        char searchFamil[20] = "";
        char searchName[20] = "";
        int searchNomzach = 0;

        printf("������� 1 ��� ������ �� �������, 2 ��� ������ �� �����, 3 ��� ������ �� �������\n");
        int asd = 0;
        scanf("%d", &asd);

        if (asd == 1) {
            printf("������� ������� ��� ������:\n");
            scanf("%s", searchFamil);
        }
        else if (asd == 2) {
            printf("������� ��� ��� ������:\n");
            scanf("%s", searchName);
        }
        else if (asd == 3) {
           printf("������� ����� �������� ������ ��� ������:\n");
            scanf("%d", &searchNomzach);
        }
        else {
            printf("������ �� �����");
            return;
        }

        int res[4] = { 1, 1, 1, 1 };

        int found = 0; // ���� ��� �����������, ���� �� ������� ����������

        for (int i = 0; i < 3; i++) {
            if (((asd == 1 && !strcmp(stud[i].famil, searchFamil)) ||
                (asd == 2 && !strcmp(stud[i].name, searchName)) ||
                (asd == 3 && stud[i].Nomzach == searchNomzach))
                && res[i] == 1)
            {
                printf("C������ %s %s ��������� �� ���������� %s, ����� �������� ������ %d\n",
                    stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);

                found = 1; // ������������� ����, ��� ����� ����������
            }
            else {
                res[i] = 0;
            }
        }
        if (!found) {
            printf("�������� � ��������� ����������� �� �������.\n");
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
