#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>

#define NO_PRINT

typedef struct node {
	int x;
	struct node* next; // ������ �� ��������� �������
} node;

void printMatrix(int** matrix, int size) {
	printf("# ");
	for (int i = 0; i < size; i++) {
		printf("%d ", i + 1);
	}
	printf("\n");

	for (int i = 0; i < size; i++) {
		printf("%d ", i + 1);
		for (int j = 0; j < size; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setbuf(stdout, NULL);

	//����� 1
	int size = 0;
	printf("Enter a count of headers: ");
	scanf(" %d", &size);

	srand(time(NULL)); // ������������� ���������� ��������� �����

	int** matrix = (int**)calloc(size, sizeof(int*));
	for (int i = 0; i < size; i++) {
		matrix[i] = (int*)calloc(size, sizeof(int));
	}

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			int random = rand() % 2; // ��������� ���������� ����� 0 ��� 1
			matrix[i][j] = random;
			matrix[j][i] = random; // ���������� ��������� � �� ������������ ���
		}
	}
	//	int matrix[6][6] = {
	//			{0, 1, 1, 0, 0, 1},
	//			{1, 0, 0, 1, 0, 0},
	//			{1, 0, 0, 0, 1, 0},
	//			{0, 1, 0, 0, 0, 0},
	//			{0, 0, 1, 0, 0, 0},
	//			{1, 0, 0, 0, 0, 0},
	//	};

	#ifndef NO_PRINT
	printMatrix(matrix, size);
	#endif

	//	2
	int* num = (int*)calloc(size, sizeof(int)); // 1.1
	int i = 1;
	#ifndef NO_PRINT
		printf("enter start vertex number:\n");
		scanf("%d", &i);
		printf("----\n");
	#endif
	i--;


	setvbuf(stdout, NULL, _IOFBF, 16384);
	clock_t time_start = clock();
	while (true) { // 1.2.
		bool done = true;
		for (; i < size; i++) {
			if (num[i] == 0) {
				done = false;
				break;
			}
		}
		if (done)
			break;
		// 1.3.
		node* q_first = calloc(1, sizeof(struct node)); // 2.1.
		node* q_last = q_first;

		q_first->x = i; // 2.2.
		q_first->next = NULL;
		num[i] = true; // 2.3.

		while (q_first != NULL) { // 2.4.
			node* f = q_first; // 2.5.

			q_first = f->next; // 2.6.
			if (q_first == NULL)
				q_last = NULL;

			#ifndef NO_PRINT
			printf("%d\n", f->x + 1); // 2.7.
			#endif
			free(f);
			for (int i2 = 1; i2 < size; i2++) { // 2.8.
				if (matrix[i][i2] == 1 && num[i2] == false) { // 2.9.
					if (q_last) {
						q_last->next = calloc(1, sizeof(struct node)); // 2.11
						q_last = q_last->next;
					}
					else {
						q_first = calloc(1, sizeof(struct node)); // 2.11
						q_last = q_first;
					}

					q_last->x = i2;
					q_last->next = NULL;

					num[i2] = true; // 2.12.
				}
			}
		}

	}
	clock_t time_end = clock();

	fflush(stdout);
	setbuf(stdout, NULL);

	double diff = time_end - time_start;
	printf("time elapsed: %fms", diff);


	for (int i = 0; i < size; i++)
		free(matrix[i]);
	free(matrix);
	free(num);

	return 0;
}
