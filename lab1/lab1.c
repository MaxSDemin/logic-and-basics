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
    int a[10] = { 0,1,2,3,4,5,6,7,8,9 };

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
        mas[i] = rand() % 101; // �������� ��������� ����� �� 0 �� 100
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
        int strok = 0;
        for (int j = 0; j < N; ++j) {
            element = rand() % 101;
            matrix[i][j] = element;
            strok += element;
        }
        printf("%d\n", strok,"\n");
    }
    return 0;
}

int task5() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    int i;
    struct student
    {
        char famil[20];
        char name[20], facult[20];
        int Nomzach;
    } 
    stud[3];

    for (i = 0; i < 3; i++)
    {
        printf("������� ������� ��������\n"); scanf("%20s", stud[i].famil);
    }
    for (i = 0; i < 3; i++)
    {
        printf("������� ��� �������� %s\n", stud[i].famil); scanf("%20s", stud[i].name);
    }
    for (i = 0; i < 3; i++)
    {
        printf("������� �������� ���������� �������� %s %s\n", stud[i].famil, stud[i].name); scanf("%20s", stud[i].facult);
    }
    for (i = 0; i < 3; i++)
    {
        printf("������� ����� �������� ������ �������� %s %s\n", stud[i].famil, stud[i].name); scanf("%d", &stud[i].Nomzach);
    }

    for (i = 0; i < 3; i++)
    {
        printf("C������ %s %s ��������� �� ���������� %s, ����� �������� ������ %d \n", stud[i].famil, stud[i].name,
            stud[i].facult, stud[i].Nomzach);
    }
    char sname[20], fname[20], numb[20], faq[20];
    printf("\n������� �������: ");
    scanf("%s", &sname);
    printf("\n������� ���: ");
    scanf("%s", &fname);
    printf("\n������� ���������: ");
    scanf("%s", &faq);
    printf("\n������� ����� ��������: ");
    scanf("%s", &numb);

    for (i = 0; i < 3; i++) {
        if (strcmp(sname, stud[i].famil) == 0) {
            printf("C������ %s %s ��������� �� ���������� %s, ����� �������� ������ %d \n", stud[i].famil, stud[i].name,
                stud[i].facult, stud[i].Nomzach);
        }
    }
    
}

int   main(void)
{
    setlocale(0, "rus");
    /*task1();
    task2();
    task3();
    task4();*/
    task5();
    return 0;
}
