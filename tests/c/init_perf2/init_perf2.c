#include <limits.h>
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* =========================================================
 *  Makra i sta³e
 * ========================================================= */
#define MAX_GRAPH_SIZE 1000
#define MAX_THREADS 8
#define SWAP(a, b)                                                             \
  do {                                                                         \
    __typeof__(a) tmp = (a);                                                   \
    (a) = (b);                                                                 \
    (b) = tmp;                                                                 \
  } while (0)

/* Przyk³adowy enum i union */
typedef enum { TYPE_INT, TYPE_DOUBLE, TYPE_STRING } VariantType;

typedef union {
  int i;
  double d;
  char s[64];
} VariantValue;

/* =========================================================
 *  STRUKTURY
 * ========================================================= */

/* Struktura przechowuj¹ca listê jednokierunkow¹ */
typedef struct ListNode {
  int data;
  struct ListNode *next;
} ListNode;

/* Struktura BST (Binary Search Tree) */
typedef struct BSTNode {
  int key;
  struct BSTNode *left;
  struct BSTNode *right;
} BSTNode;

/* Struktura wêz³a grafu dla listy s¹siedztwa */
typedef struct GraphEdge {
  int to;
  int weight;
  struct GraphEdge *next;
} GraphEdge;

/* Struktura grafu w formie listy s¹siedztwa */
typedef struct {
  GraphEdge **adjList;
  int numVertices;
} GraphAdjList;

/* Struktura grafu w formie macierzy s¹siedztwa */
typedef struct {
  int **matrix;
  int n;
} GraphMatrix;

/* Struktura do wielow¹tkowoœci */
typedef struct {
  int thread_id;
  int *array;
  int length;
  long long partial_sum;
} ThreadData;

/* Struktura macierzy do mno¿enia */
typedef struct {
  int rows;
  int cols;
  int **data;
} Matrix;

/* Struktura przechowuj¹ca wartoœci typu Variant */
typedef struct {
  VariantType type;
  VariantValue value;
} Variant;

/* =========================================================
 *  PROTOTYPY FUNKCJI
 * ========================================================= */

/* ----- Lista jednokierunkowa ----- */
ListNode *listCreateNode(int data);
void listInsertFront(ListNode **head, int data);
void listPrint(const ListNode *head);
void listFree(ListNode *head);

/* ----- Drzewo BST ----- */
BSTNode *bstInsert(BSTNode *root, int key);
void bstInOrder(const BSTNode *root);
void bstFree(BSTNode *root);

/* ----- Sortowania ----- */
void mergeSort(int *arr, int left, int right);
void quickSort(int *arr, int left, int right);
void heapSort(int *arr, int n);

/* ----- Algorytmy grafowe ----- */
GraphAdjList createGraphAdjList(int vertices);
void addEdgeAdjList(GraphAdjList *g, int from, int to, int weight);
void freeGraphAdjList(GraphAdjList *g);

void bfsAdjList(const GraphAdjList *g, int start);
void dfsAdjList(const GraphAdjList *g, int start);
void dijkstraAdjList(const GraphAdjList *g, int start);

/* Graf w formie macierzy */
GraphMatrix createGraphMatrix(int n);
void freeGraphMatrix(GraphMatrix *gm);
void floydWarshall(GraphMatrix *gm);

/* ----- Wielow¹tkowoœæ ----- */
void *threadFunctionSum(void *arg);
void threadedArraySum(int *arr, int size, int numThreads);

/* ----- Macierze ----- */
Matrix createRandomMatrix(int rows, int cols);
Matrix multiplyMatrices(const Matrix *A, const Matrix *B);
void freeMatrix(Matrix *m);

/* ----- Funkcje rekurencyjne i matematyczne ----- */
long long factorial(int n);
long long fibonacci(int n);
int isPrime(long long x);
void primeFactorization(long long x);

/* ----- Inne przyk³ady obliczeñ ----- */
void randomStringManipulation(char *buffer, size_t size);
Variant createVariantInt(int value);
Variant createVariantDouble(double value);
Variant createVariantString(const char *value);
void printVariant(const Variant *v);

/* =========================================================
 *  IMPLEMENTACJA FUNKCJI
 * ========================================================= */

/* ---------------------------
 * 1. Lista jednokierunkowa
 * --------------------------- */
ListNode *listCreateNode(int data) {
  ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void listInsertFront(ListNode **head, int data) {
  ListNode *newNode = listCreateNode(data);
  newNode->next = *head;
  *head = newNode;
}

void listPrint(const ListNode *head) {
  printf("Lista: ");
  while (head) {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

void listFree(ListNode *head) {
  while (head) {
    ListNode *temp = head;
    head = head->next;
    free(temp);
  }
}

/* ---------------------------
 * 2. Drzewo BST
 * --------------------------- */
BSTNode *bstInsert(BSTNode *root, int key) {
  if (root == NULL) {
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    node->key = key;
    node->left = node->right = NULL;
    return node;
  }
  if (key < root->key)
    root->left = bstInsert(root->left, key);
  else if (key > root->key)
    root->right = bstInsert(root->right, key);
  return root;
}

void bstInOrder(const BSTNode *root) {
  if (!root)
    return;
  bstInOrder(root->left);
  printf("%d ", root->key);
  bstInOrder(root->right);
}

void bstFree(BSTNode *root) {
  if (!root)
    return;
  bstFree(root->left);
  bstFree(root->right);
  free(root);
}

/* ---------------------------
 * 3. Sortowania
 * --------------------------- */

/* MergeSort */
void merge(int *arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int *L = (int *)malloc(sizeof(int) * n1);
  int *R = (int *)malloc(sizeof(int) * n2);

  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }
  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
  free(L);
  free(R);
}

void mergeSort(int *arr, int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

/* QuickSort */
int partitionQ(int *arr, int left, int right) {
  int pivot = arr[right];
  int i = left - 1;
  for (int j = left; j < right; j++) {
    if (arr[j] < pivot) {
      i++;
      SWAP(arr[i], arr[j]);
    }
  }
  SWAP(arr[i + 1], arr[right]);
  return i + 1;
}

void quickSort(int *arr, int left, int right) {
  if (left < right) {
    int pi = partitionQ(arr, left, right);
    quickSort(arr, left, pi - 1);
    quickSort(arr, pi + 1, right);
  }
}

/* HeapSort */
void heapify(int *arr, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;
  if (right < n && arr[right] > arr[largest])
    largest = right;
  if (largest != i) {
    SWAP(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(int *arr, int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);
  for (int i = n - 1; i > 0; i--) {
    SWAP(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

/* ---------------------------
 * 4. Graf - lista s¹siedztwa
 * --------------------------- */
GraphAdjList createGraphAdjList(int vertices) {
  GraphAdjList g;
  g.numVertices = vertices;
  g.adjList = (GraphEdge **)malloc(vertices * sizeof(GraphEdge *));
  for (int i = 0; i < vertices; i++) {
    g.adjList[i] = NULL;
  }
  return g;
}

void addEdgeAdjList(GraphAdjList *g, int from, int to, int weight) {
  if (from < 0 || from >= g->numVertices || to < 0 || to >= g->numVertices)
    return;
  GraphEdge *newEdge = (GraphEdge *)malloc(sizeof(GraphEdge));
  newEdge->to = to;
  newEdge->weight = weight;
  newEdge->next = g->adjList[from];
  g->adjList[from] = newEdge;
}

void freeGraphAdjList(GraphAdjList *g) {
  for (int i = 0; i < g->numVertices; i++) {
    GraphEdge *edge = g->adjList[i];
    while (edge) {
      GraphEdge *temp = edge;
      edge = edge->next;
      free(temp);
    }
  }
  free(g->adjList);
}

/* BFS */
void bfsAdjList(const GraphAdjList *g, int start) {
  if (start < 0 || start >= g->numVertices)
    return;
  int *visited = (int *)calloc(g->numVertices, sizeof(int));
  int *queue = (int *)malloc(sizeof(int) * g->numVertices);
  int front = 0, rear = 0;
  visited[start] = 1;
  queue[rear++] = start;

  while (front < rear) {
    int current = queue[front++];
    /* Przyk³adowa operacja: wypisanie wierzcho³ka */
    // printf("Visited: %d\n", current);
    GraphEdge *edge = g->adjList[current];
    while (edge) {
      if (!visited[edge->to]) {
        visited[edge->to] = 1;
        queue[rear++] = edge->to;
      }
      edge = edge->next;
    }
  }
  free(visited);
  free(queue);
}

/* DFS (rekurencyjny) */
void dfsVisit(const GraphAdjList *g, int v, int *visited) {
  visited[v] = 1;
  // printf("Visited: %d\n", v);
  GraphEdge *edge = g->adjList[v];
  while (edge) {
    if (!visited[edge->to]) {
      dfsVisit(g, edge->to, visited);
    }
    edge = edge->next;
  }
}

void dfsAdjList(const GraphAdjList *g, int start) {
  if (start < 0 || start >= g->numVertices)
    return;
  int *visited = (int *)calloc(g->numVertices, sizeof(int));
  dfsVisit(g, start, visited);
  free(visited);
}

/* Dijkstra (dla grafu w formie listy s¹siedztwa, wagi >= 0) */
void dijkstraAdjList(const GraphAdjList *g, int start) {
  if (start < 0 || start >= g->numVertices)
    return;
  int n = g->numVertices;
  int *dist = (int *)malloc(n * sizeof(int));
  int *visited = (int *)calloc(n, sizeof(int));

  for (int i = 0; i < n; i++) {
    dist[i] = INT_MAX;
  }
  dist[start] = 0;

  for (int count = 0; count < n - 1; count++) {
    int minDist = INT_MAX;
    int u = -1;
    for (int i = 0; i < n; i++) {
      if (!visited[i] && dist[i] < minDist) {
        minDist = dist[i];
        u = i;
      }
    }
    if (u == -1)
      break;
    visited[u] = 1;

    GraphEdge *edge = g->adjList[u];
    while (edge) {
      int v = edge->to;
      int w = edge->weight;
      if (!visited[v] && dist[u] != INT_MAX && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
      }
      edge = edge->next;
    }
  }
  /* Mo¿na tu ewentualnie coœ zrobiæ z tablic¹ dist... */

  free(dist);
  free(visited);
}

/* ---------------------------
 * 5. Graf - macierz s¹siedztwa
 * --------------------------- */
GraphMatrix createGraphMatrix(int n) {
  GraphMatrix gm;
  gm.n = n;
  gm.matrix = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    gm.matrix[i] = (int *)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++) {
      gm.matrix[i][j] =
          ((i == j) ? 0
                    : INT_MAX / 2); // Ustawiamy du¿e wartoœci poza przek¹tn¹
    }
  }
  return gm;
}

void freeGraphMatrix(GraphMatrix *gm) {
  for (int i = 0; i < gm->n; i++) {
    free(gm->matrix[i]);
  }
  free(gm->matrix);
}

/* Floyd-Warshall dla wyznaczania najkrótszych œcie¿ek w grafie */
void floydWarshall(GraphMatrix *gm) {
  int n = gm->n;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (gm->matrix[i][k] + gm->matrix[k][j] < gm->matrix[i][j]) {
          gm->matrix[i][j] = gm->matrix[i][k] + gm->matrix[k][j];
        }
      }
    }
  }
}

/* ---------------------------
 * 6. Wielow¹tkowoœæ
 * --------------------------- */
void *threadFunctionSum(void *arg) {
  ThreadData *data = (ThreadData *)arg;
  long long sum = 0;
  for (int i = 0; i < data->length; i++) {
    sum += data->array[i];
  }
  data->partial_sum = sum;
  pthread_exit(NULL);
}

void threadedArraySum(int *arr, int size, int numThreads) {
  pthread_t threads[numThreads];
  ThreadData threadData[numThreads];
  int chunkSize = size / numThreads;
  for (int i = 0; i < numThreads; i++) {
    threadData[i].thread_id = i;
    threadData[i].array = &arr[i * chunkSize];
    threadData[i].length =
        (i == numThreads - 1) ? (size - i * chunkSize) : chunkSize;
    threadData[i].partial_sum = 0;
    pthread_create(&threads[i], NULL, threadFunctionSum, &threadData[i]);
  }
  long long totalSum = 0;
  for (int i = 0; i < numThreads; i++) {
    pthread_join(threads[i], NULL);
    totalSum += threadData[i].partial_sum;
  }
  printf("Total sum (multi-thread) = %lld\n", totalSum);
}

/* ---------------------------
 * 7. Macierze (mno¿enie)
 * --------------------------- */
Matrix createRandomMatrix(int rows, int cols) {
  Matrix m;
  m.rows = rows;
  m.cols = cols;
  m.data = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    m.data[i] = (int *)malloc(cols * sizeof(int));
    for (int j = 0; j < cols; j++) {
      m.data[i][j] = rand() % 10;
    }
  }
  return m;
}

Matrix multiplyMatrices(const Matrix *A, const Matrix *B) {
  Matrix result;
  if (A->cols != B->rows) {
    result.rows = 0;
    result.cols = 0;
    result.data = NULL;
    return result;
  }
  result.rows = A->rows;
  result.cols = B->cols;
  result.data = (int **)malloc(result.rows * sizeof(int *));
  for (int i = 0; i < result.rows; i++) {
    result.data[i] = (int *)malloc(result.cols * sizeof(int));
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->cols; j++) {
      long long sum = 0;
      for (int k = 0; k < A->cols; k++) {
        sum += (long long)(A->data[i][k]) * (B->data[k][j]);
      }
      result.data[i][j] = (int)sum;
    }
  }
  return result;
}

void freeMatrix(Matrix *m) {
  for (int i = 0; i < m->rows; i++) {
    free(m->data[i]);
  }
  free(m->data);
  m->data = NULL;
}

/* ---------------------------
 * 8. Funkcje rekurencyjne i matematyczne
 * --------------------------- */

/* Silnia (rekurencja) */
long long factorial(int n) {
  if (n < 2)
    return 1;
  return n * factorial(n - 1);
}

/* n-ta liczba Fibonacciego (rekurencja) */
long long fibonacci(int n) {
  if (n < 2)
    return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

/* Sprawdzenie, czy liczba jest pierwsza */
int isPrime(long long x) {
  if (x <= 1)
    return 0;
  if (x <= 3)
    return 1;
  if (x % 2 == 0 || x % 3 == 0)
    return 0;
  for (long long i = 5; i * i <= x; i += 6) {
    if (x % i == 0 || x % (i + 2) == 0)
      return 0;
  }
  return 1;
}

/* Faktoryzacja liczby */
void primeFactorization(long long x) {
  printf("Czynniki pierwsze %lld: ", x);
  while (x % 2 == 0) {
    printf("2 ");
    x /= 2;
  }
  for (long long i = 3; i * i <= x; i += 2) {
    while (x % i == 0) {
      printf("%lld ", i);
      x /= i;
    }
  }
  if (x > 2) {
    printf("%lld", x);
  }
  printf("\n");
}

/* ---------------------------
 * 9. Inne przyk³adowe obliczenia
 * --------------------------- */
void randomStringManipulation(char *buffer, size_t size) {
  const char *alphabet =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  for (size_t i = 0; i < size - 1; i++) {
    buffer[i] = alphabet[rand() % (strlen(alphabet))];
  }
  buffer[size - 1] = '\0';
}

/* Tworzenie struktur Variant */
Variant createVariantInt(int value) {
  Variant v;
  v.type = TYPE_INT;
  v.value.i = value;
  return v;
}

Variant createVariantDouble(double value) {
  Variant v;
  v.type = TYPE_DOUBLE;
  v.value.d = value;
  return v;
}

Variant createVariantString(const char *value) {
  Variant v;
  v.type = TYPE_STRING;
  strncpy(v.value.s, value, sizeof(v.value.s) - 1);
  v.value.s[sizeof(v.value.s) - 1] = '\0';
  return v;
}

void printVariant(const Variant *v) {
  switch (v->type) {
  case TYPE_INT:
    printf("Variant Int: %d\n", v->value.i);
    break;
  case TYPE_DOUBLE:
    printf("Variant Double: %f\n", v->value.d);
    break;
  case TYPE_STRING:
    printf("Variant String: %s\n", v->value.s);
    break;
  default:
    printf("Unknown Variant\n");
    break;
  }
}

/* =========================================================
 *  FUNKCJA MAIN
 * ========================================================= */
int main(void) {
  srand((unsigned)time(NULL));

  /* ---------------------------
   * A. Lista jednokierunkowa
   * --------------------------- */
  ListNode *myList = NULL;
  for (int i = 0; i < 10; i++) {
    listInsertFront(&myList, rand() % 100);
  }
  listPrint(myList);
  listFree(myList);

  /* ---------------------------
   * B. Drzewo BST
   * --------------------------- */
  BSTNode *myBST = NULL;
  for (int i = 0; i < 10; i++) {
    myBST = bstInsert(myBST, rand() % 200);
  }
  printf("BST in-order: ");
  bstInOrder(myBST);
  printf("\n");
  bstFree(myBST);

  /* ---------------------------
   * C. Sortowanie
   * --------------------------- */
  int arrSize = 15;
  int *arr1 = (int *)malloc(sizeof(int) * arrSize);
  int *arr2 = (int *)malloc(sizeof(int) * arrSize);
  int *arr3 = (int *)malloc(sizeof(int) * arrSize);

  for (int i = 0; i < arrSize; i++) {
    int val = rand() % 300;
    arr1[i] = val;
    arr2[i] = val;
    arr3[i] = val;
  }

  mergeSort(arr1, 0, arrSize - 1);
  quickSort(arr2, 0, arrSize - 1);
  heapSort(arr3, arrSize);

  free(arr1);
  free(arr2);
  free(arr3);

  /* ---------------------------
   * D. Graf - lista s¹siedztwa
   * --------------------------- */
  GraphAdjList gAdj = createGraphAdjList(10);
  for (int i = 0; i < 20; i++) {
    int from = rand() % 10;
    int to = rand() % 10;
    int w = rand() % 50;
    addEdgeAdjList(&gAdj, from, to, w);
  }
  bfsAdjList(&gAdj, 0);
  dfsAdjList(&gAdj, 0);
  dijkstraAdjList(&gAdj, 0);
  freeGraphAdjList(&gAdj);

  /* ---------------------------
   * E. Graf - macierz s¹siedztwa
   * --------------------------- */
  GraphMatrix gm = createGraphMatrix(6);
  /* Dodajmy kilka przyk³adowych krawêdzi do macierzy */
  for (int i = 0; i < 6; i++) {
    for (int j = i + 1; j < 6; j++) {
      int w = rand() % 100;
      gm.matrix[i][j] = w;
      gm.matrix[j][i] = w;
    }
  }
  floydWarshall(&gm);
  freeGraphMatrix(&gm);

  /* ---------------------------
   * F. Wielow¹tkowoœæ
   * --------------------------- */
  int largeSize = 100000;
  int *largeArray = (int *)malloc(largeSize * sizeof(int));
  for (int i = 0; i < largeSize; i++) {
    largeArray[i] = rand() % 100;
  }
  threadedArraySum(largeArray, largeSize, MAX_THREADS);
  free(largeArray);

  /* ---------------------------
   * G. Macierze (mno¿enie)
   * --------------------------- */
  Matrix A = createRandomMatrix(5, 3);
  Matrix B = createRandomMatrix(3, 5);
  Matrix C = multiplyMatrices(&A, &B);
  if (C.data != NULL) {
    // Przyk³adowo, wypiszmy jedn¹ wartoœæ
    printf("Wynik mno¿enia macierzy: C[0][0] = %d\n", C.data[0][0]);
  } else {
    printf("Nie mo¿na pomno¿yæ A i B.\n");
  }
  freeMatrix(&A);
  freeMatrix(&B);
  freeMatrix(&C);

  /* ---------------------------
   * H. Funkcje rekurencyjne, matematyczne
   * --------------------------- */
  int fN = 20;
  printf("fibonacci(%d) = %lld\n", fN, fibonacci(fN));
  int facN = 10;
  printf("factorial(%d) = %lld\n", facN, factorial(facN));

  long long testPrime = 1234567890123LL;
  printf("Czy %lld jest pierwsza? %s\n", testPrime,
         isPrime(testPrime) ? "TAK" : "NIE");
  primeFactorization(testPrime);

  /* ---------------------------
   * I. Inne przyk³ady obliczeñ
   * --------------------------- */
  char buffer[32];
  randomStringManipulation(buffer, sizeof(buffer));
  printf("Losowy ci¹g znaków: %s\n", buffer);

  Variant vi = createVariantInt(42);
  Variant vd = createVariantDouble(3.14159);
  Variant vs = createVariantString("Hello World");
  printVariant(&vi);
  printVariant(&vd);
  printVariant(&vs);

  printf("Koniec programu.\n");
  return 0;
}
