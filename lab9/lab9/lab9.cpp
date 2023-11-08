#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <queue>


#define MAX_SIZE 100

struct node
{
    int vertex;
    struct node* next;
};
struct node* createNode(int v)
{
    struct node* newNode = (node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph
{
    int numVertices;
    struct node** adjLists;
};
struct Graph* createGraph(int vertices)
{
    struct Graph* graph = (Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (node**)malloc(vertices * sizeof(struct node*));

    int i;
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph)
{
    int v;
    printf("\n");
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node* temp = graph->adjLists[v];
        printf("\nvertex: %d\n ", v+1);
        while (temp)
        {
            printf("%d ", temp->vertex+1);
            temp = temp->next;
        }
    }
}

void BFSD(int **G, int size_G, int v, int DIST[MAX_SIZE]) {
    bool visited[MAX_SIZE] = { false };
    visited[v] = true;
    DIST[v] = 0;

    int queue[MAX_SIZE] = { 0 };
    int front = 0, rear = 0;
    queue[rear++] = v;

    while (front != rear) {
        int current_vertex = queue[front++];
        printf("%d ", current_vertex);

        for (int i = 0; i < size_G; i++) {
            if (G[current_vertex][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
                DIST[i] = DIST[current_vertex] + 1;
            }
        }
    }
}

int main() {
    int size, v = 0;
    printf("Enter a count of headers: ");
    scanf(" %d", &size);

    srand(time(NULL)); // Инициализация генератора случайных чисел

    int** matrix = (int**)calloc(size, sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int*)calloc(size, sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int random = rand() % 2; // Генерация случайного числа 0 или 1
            matrix[i][j] = random;
            matrix[j][i] = random; // Заполнение элементов и их симметричных пар
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Enter the source vertex: ");
    scanf("%d", &v);

    int DIST[MAX_SIZE];
    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        DIST[i] = -1;
    }
    BFSD(matrix, size, v, DIST);

    printf("\nDIST vector:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", DIST[i]);
    }

    //Задание 1.3
    struct Graph* graph = createGraph(size);
    srand(time(NULL));
    int *vertex = (int*)calloc(size, sizeof(int));
    bool edge;

    for (int i = 0; i < size; i++)
    {
        vertex[i] = i;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            edge = rand() % 2;
            if (vertex[j] != i and edge == true)
            {
                addEdge(graph, i, j);
            }
        }
    }
    printGraph(graph);
}
