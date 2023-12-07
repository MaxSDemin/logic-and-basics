#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

struct node {
    int vertex;
    struct node* next;
};

struct node* createNode(int v) {
    struct node* newNode = (node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph {
    int numVertices;
    struct node** adjLists;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (node**)malloc(vertices * sizeof(struct node*));

    int i;
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph) {
#ifdef NO_PRINT
    return;
#endif

    int v;
    for (v = 0; v < graph->numVertices; v++) {
        struct node* temp = graph->adjLists[v];
        printf("\nvertex: %d\n ", v + 1);
        while (temp) {
            printf("%d ", temp->vertex + 1);
            temp = temp->next;
        }
    }
}

int** identity(int** matrix, int vertexA, int vertexB, int count)
{
    int** matrixNew = (int**)calloc(count - 1, sizeof(int*));
    for (int i = 0; i < count - 1; i++)
    {
        matrixNew[i] = (int*)calloc(count - 1, sizeof(int));
    }
    int row = 0;
    int col = 0;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (i != vertexA and i != vertexB and j != vertexA and j != vertexB)
            {
                matrixNew[row][col] = matrix[i][j];
                col++;
                //printf("%d ", matrix[i][j]);
            }
        }
        if (i != vertexA and i != vertexB)
        {
            //printf("\n");
            col = 0;
            row++;
        }
    }
    //printf("\n");

    row = 0;
    col = 0;

    for (int i = 0; i < count; i++)
    {
        if (i != vertexA and i != vertexB)
        {
            matrixNew[row][count - 2] = matrix[vertexA][i] || matrix[vertexB][i];
            matrixNew[count - 2][col] = matrix[i][vertexA] || matrix[i][vertexB];
            row++;
            col++;
        }
        else
        {
            matrixNew[count - 2][count - 2] = matrix[vertexA][vertexB];
        }
    }

    //for (int i = 0; i < count-1; i++) {
    //    for (int j = 0; j < count-1; j++) {
    //        //printf("%d ", matrixNew[i][j]);
    //    }
    //    printf("\n");
    //}

    printf("\n");

    count--;

    delete[] matrix;
    matrix = matrixNew;

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return matrix;
}

int** tightening(int** matrix, int vertexA, int vertexB, int count)
{
    matrix[vertexA][vertexB] = 0;
    matrix[vertexB][vertexA] = 0;
    matrix = identity(matrix, vertexA, vertexB, count);

    return matrix;
}

int** splitting(int** matrix, int vertex, int count)
{

    int** matrixNew = (int**)calloc(count+1, sizeof(int*));
    for (int i = 0; i < count - 1; i++)
    {
        matrixNew[i] = (int*)calloc(count+1, sizeof(int));
    }

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            matrixNew[i][j] = matrix[i][j];
        }
    }

    for (int i = 0; i < count; i++) {
        matrixNew[i][count] = matrix[i][vertex];
        matrixNew[count][i] = matrix[vertex][i];
    }
    matrixNew[count++][count++] = 0;
    count++;
    matrix = matrixNew;
    return matrix;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int count1 = 0;
    printf("Введите размер первого графа: ");
    scanf("%d", &count1);

    int count2 = 0;
    printf("Введите размер второго графа: ");
    scanf("%d", &count2);

    srand(time(NULL));

    int** matrix1 = (int**)malloc(count1 * sizeof(int*));
    for (int i = 0; i < count1; i++)
    {
        matrix1[i] = (int*)malloc(count1 * sizeof(int));
    }
    int** matrix2 = (int**)malloc(count2 * sizeof(int*));
    for (int i = 0; i < count2; i++)
    {
        matrix2[i] = (int*)malloc(count2 * sizeof(int));
    }

    for (int i = 0; i < count1; i++) {
        for (int j = 0; j < count1; j++) {
            matrix1[j][i] = 0;
        }
    }
    for (int i = 0; i < count2; i++) {
        for (int j = 0; j < count2; j++) {
            matrix2[j][i] = 0;
        }
    }

    for (int i = 0; i < count1; i++) {
        for (int j = i + 1; j < count1; j++) {
            int random = rand() % 2; // Генерация случайного числа 0 или 1
            matrix1[i][j] = random;
            matrix1[j][i] = random; // Заполнение элементов и их симметричных пар
        }
    }
    for (int i = 0; i < count2; i++) {
        for (int j = i + 1; j < count2; j++) {
            int random = rand() % 2; // Генерация случайного числа 0 или 1
            matrix2[i][j] = random;
            matrix2[j][i] = random; // Заполнение элементов и их симметричных пар
        }
    }

    struct Graph* graph1 = createGraph(count1);
    srand(time(NULL));
    int* vertex = (int*)calloc(count1, sizeof(int));
    bool edge;

    for (int i = 0; i < count1; i++) {
        vertex[i] = i;
    }

    for (int i = 0; i < count1; i++) {
        for (int j = i + 1; j < count1; j++) {
            edge = matrix1[i][j];
            if (edge == true) {
                addEdge(graph1, i, j);
            }
        }
    }

    struct Graph* graph2 = createGraph(count2);
    srand(time(NULL));
    vertex = (int*)calloc(count2, sizeof(int));


    for (int i = 0; i < count2; i++) {
        vertex[i] = i;
    }

    for (int i = 0; i < count2; i++) {
        for (int j = i + 1; j < count2; j++) {
            edge = matrix2[i][j];
            if (edge == true) {
                addEdge(graph2, i, j);
            }
        }
    }


    printf("\n");

    //Задание 2.1
    int vertexA, vertexB, vertexSpl;

    bool ready = true;

    while (ready)
    {

        /*printGraph(graph1);
        printf("\n");
        printGraph(graph2);*/
        printf("\n\n");


        for (int i = 0; i < count1; i++) {
            for (int j = 0; j < count1; j++) {
                printf("%d ", matrix1[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        for (int i = 0; i < count2; i++) {
            for (int j = 0; j < count2; j++) {
                printf("%d ", matrix2[i][j]);
            }
            printf("\n");
        }

        printf("\nВыберете какую операцию нужно сделать:\n");
        printf("0. Пропустить/Продолжить дальше.\n1. Отождествление вершин.\n2. Стягивание ребра.\n3. Расщепление вершин.\n");
        printf("\nДля выбора введите цифру от 1 до 3 соответственно\n");

        int input;
        scanf("%d", &input);
        switch (input)
        {
        case 0:
            ready = false;
            break;
        case 1:
            printf("\nВведите нужные вершины:");
            scanf("%d %d", &vertexA, &vertexB);
            vertexA--;
            vertexB--;
            matrix1 = identity(matrix1, vertexA, vertexB, count1);
            matrix2 = identity(matrix2, vertexA, vertexB, count2);
            count1--;
            count2--;
            break;
        case 2:
            printf("\nВведите вершины между которыми стянуть ребро:");
            scanf("%d %d", &vertexA, &vertexB);
            vertexA--;
            vertexB--;
            matrix1 = tightening(matrix1, vertexA, vertexB, count1);
            matrix2 = tightening(matrix2, vertexA, vertexB, count2);
            break;
        case 3:
            printf("\nВведите вершинe которую хотите расщепить:");
            scanf("%d", &vertexSpl);
            vertexSpl--;
            matrix1 = splitting(matrix1, vertexSpl, count1);
            matrix2 = splitting(matrix2, vertexSpl, count2);
            break;
        default:
            printf("Введите еще раз");
            break;
        }
    }

}
