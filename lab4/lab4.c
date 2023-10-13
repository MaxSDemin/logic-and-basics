#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>

typedef struct Node {
	
	struct Node* left;
	struct Node* right;
	int data;
} Node;

struct Node* root;

//`
struct Node* CreateTree(Node* rooot, Node* r, int data, bool left) {
	if (r == NULL) {
		r = (struct Node*)malloc(sizeof(Node));
		if (r == NULL) {
			printf("Ошибка выделения памяти");
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (rooot == NULL)
			return r;

		if (left)
			rooot->left = r;
		else
			rooot->right = r;
		return r;
	}

	if (left)
		CreateTree(r, r->right, data, left);
	else
		CreateTree(r, r->right, data, left);

	return rooot;
}

void print_tree(Node* r, int l) {
	if (r == NULL)
		return;

	print_tree(r->right, l + 1);
	for (int i = 0; i < l; i++) {
		printf(" ");
	}

	printf("%d\n", r->data);
	print_tree(r->left, l + 1);
}

void search_tree(Node* r, int l, int query) {
	if (r == NULL)
		return;

	search_tree(r->right, l + 1, query);
	for (int i = 0; i < l; i++) {
		printf(" ");
	}

	if (r->data == query)
		printf("%d <----\n", r->data);
	else
		printf("%d\n", r->data);
	search_tree(r->left, l + 1, query);
}

int _count_tree(Node* r, int l, int query, int count) {
	if (r == NULL)
		return count;

	count = _count_tree(r->right, l + 1, query, count);
	for (int i = 0; i < l; i++) {
		printf(" ");
	}

	if (r->data == query) {
		count++;
		printf("%d <---- (%d)\n", r->data, count);
	}
	else {
		printf("%d\n", r->data);
	}
	count = _count_tree(r->left, l + 1, query, count);
	return count;
}

int count_tree(Node* r, int l, int query) {
	return _count_tree(r, l, query, 0);
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setbuf(stdout, NULL);

	int D, start = 1;

	root = NULL;/*
	printf("-1 - окончание построения дерева\n");
	while (start) {
		printf("Введите число: ");
		scanf_s("%d", &D);
		if (D == -1) {
			printf("Построение дерева окончено\n\n");
			start = 0;
		}
		else
			root = CreateTree(root, root, D, false);

	}
	print_tree(root, 0);*/

	printf("Поиск числа:\n");
	scanf_s("%d", &D);
	search_tree(root, 0, D);

	printf("Поиск количества вхождений числа:\n");
	count_tree(root, 0, D);

	root = NULL;
	start = 1;
	printf("-1 - окончание построения дерева\n");
	while (start) {
		bool left = false;
		printf("ВВедите 1 если слева, не 1 если справа: ");
		scanf_s("%d", &D);
		if (D == 1)
			left = true;

		printf("Введите число: ");
		scanf_s("%d", &D);
		if (count_tree(root, 0, D)) {
			printf("Число уже есть\n\n");
			continue;
		}if (D == -1) {
			printf("Построение дерева окончено\n\n");
			start = 0;
		}
		else {
			root = CreateTree(root, root, D, left);
		}

	}
	print_tree(root, 0);


	return 0;
}

