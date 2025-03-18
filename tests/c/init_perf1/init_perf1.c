
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
#define MAX_THREADS 4
#define MAX_RANDOM_VALUE 1000
#define SWAP(a, b)                                                             \
  {                                                                            \
    __typeof__(a) tmp = (a);                                                   \
    (a) = (b);                                                                 \
    (b) = tmp;                                                                 \
  }

/* =========================================================
 *  Struktury
 * ========================================================= */
typedef struct {
  int *edges;
  int size;
} GraphNode;

typedef struct {
  GraphNode *nodes;
  int numNodes;
} Graph;

typedef struct {
  int **matrix;
  int rows;
  int cols;
} Matrix;

/* Struktura z danymi do w¹tków */
typedef struct {
  int thread_id;
  int *array;
  int length;
  long long partial_sum;
} ThreadData;

/* =========================================================
 *  Zmienne globalne
 * ========================================================= */
Graph globalGraph;
int globalArray[1024] = {0};

/* =========================================================
 *  Funkcje pomocnicze
 * ========================================================= */

/* Generowanie losowych danych do tablicy globalArray */
void fillGlobalArrayRandomly() {
  srand((unsigned)time(NULL));
  for (int i = 0; i < 1024; i++) {
    globalArray[i] = rand() % 10000;
  }
}

/* Prosta funkcja rekurencyjna (silnia) */
long long factorial(int n) {
  if (n < 2)
    return 1;
  return n * factorial(n - 1);
}

/* Rekurencyjne obliczanie n-tej liczby Fibonacciego */
long long fibonacci(int n) {
  if (n < 2)
    return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

/* =========================================================
 *  Tworzenie i obs³uga grafu
 * ========================================================= */
Graph createRandomGraph(int numNodes, int maxEdgesPerNode) {
  Graph g;
  g.numNodes = numNodes;
  g.nodes = (GraphNode *)malloc(sizeof(GraphNode) * numNodes);

  for (int i = 0; i < numNodes; i++) {
    g.nodes[i].size = rand() % (maxEdgesPerNode + 1);
    g.nodes[i].edges = (int *)malloc(sizeof(int) * g.nodes[i].size);
    for (int j = 0; j < g.nodes[i].size; j++) {
      g.nodes[i].edges[j] = rand() % numNodes;
    }
  }
  return g;
}

void freeGraph(Graph *g) {
  for (int i = 0; i < g->numNodes; i++) {
    free(g->nodes[i].edges);
  }
  free(g->nodes);
}

/* BFS na grafie */
void bfs(const Graph *g, int startNode) {
  if (startNode < 0 || startNode >= g->numNodes)
    return;

  int visited[g->numNodes];
  memset(visited, 0, sizeof(visited));

  int queue[MAX_GRAPH_SIZE];
  int front = 0;
  int rear = 0;

  queue[rear++] = startNode;
  visited[startNode] = 1;

  while (front < rear) {
    int current = queue[front++];
    // W realnym kodzie mo¿esz tu wstawiæ jak¹œ operacjê
    for (int i = 0; i < g->nodes[current].size; i++) {
      int neighbor = g->nodes[current].edges[i];
      if (!visited[neighbor]) {
        visited[neighbor] = 1;
        queue[rear++] = neighbor;
      }
    }
  }
}

/* =========================================================
 *  Sortowanie
 * ========================================================= */

/* Merge Sort */
void merge(int *arr, int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int *L = (int *)malloc(sizeof(int) * n1);
  int *R = (int *)malloc(sizeof(int) * n2);

  for (i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  i = 0;
  j = 0;
  k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }

  while (i < n1) {
    arr[k++] = L[i++];
  }
  while (j < n2) {
    arr[k++] = R[j++];
  }

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

/* Quick Sort */
int partitionQ(int *arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      SWAP(arr[i], arr[j]);
    }
  }
  SWAP(arr[i + 1], arr[high]);
  return i + 1;
}

void quickSort(int *arr, int low, int high) {
  if (low < high) {
    int pi = partitionQ(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

/* =========================================================
 *  Operacje na macierzach
 * ========================================================= */
Matrix createMatrix(int rows, int cols) {
  Matrix m;
  m.rows = rows;
  m.cols = cols;
  m.matrix = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    m.matrix[i] = (int *)malloc(cols * sizeof(int));
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = rand() % 10;
    }
  }
  return m;
}

void freeMatrix(Matrix *m) {
  for (int i = 0; i < m->rows; i++) {
    free(m->matrix[i]);
  }
  free(m->matrix);
}

/* Mno¿enie macierzy */
Matrix multiplyMatrices(const Matrix *A, const Matrix *B) {
  Matrix result;
  if (A->cols != B->rows) {
    /* Zwracamy pust¹ macierz, gdy nie da siê pomno¿yæ */
    result.rows = 0;
    result.cols = 0;
    result.matrix = NULL;
    return result;
  }

  result = createMatrix(A->rows, B->cols);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->cols; j++) {
      long long sum = 0;
      for (int k = 0; k < A->cols; k++) {
        sum += (long long)A->matrix[i][k] * B->matrix[k][j];
      }
      result.matrix[i][j] = (int)sum;
    }
  }
  return result;
}

/* =========================================================
 *  Wielow¹tkowoœæ (pthread)
 * ========================================================= */

/* Funkcja, któr¹ bêd¹ wykonywaæ w¹tki.
   Tutaj zliczamy sumê elementów przekazanej tablicy. */
void *threadFunction(void *arg) {
  ThreadData *data = (ThreadData *)arg;
  long long sum = 0;
  for (int i = 0; i < data->length; i++) {
    sum += data->array[i];
  }
  data->partial_sum = sum;
  pthread_exit(NULL);
}

/* =========================================================
 *  Funkcje matematyczne (liczby pierwsze, faktoryzacja)
 * ========================================================= */

/* Sprawdzenie, czy liczba jest pierwsza */
int isPrime(long long x) {
  if (x <= 1)
    return 0;
  if (x <= 3)
    return 1;
  if (x % 2 == 0 || x % 3 == 0)
    return 0;
  for (long long i = 5; i * i <= x; i += 6) {
    if (x % i == 0 || x % (i + 2) == 0) {
      return 0;
    }
  }
  return 1;
}

/* Prosta faktoryzacja */
void primeFactorization(long long x) {
  printf("Czynniki pierwsze %lld: ", x);
  while (x % 2 == 0) {
    printf("%d ", 2);
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

/* =========================================================
 *  Funkcja main
 * ========================================================= */
int main(void) {
  srand((unsigned)time(NULL));

  /* ----------------
   * 1. Global Array
   * ----------------*/
  fillGlobalArrayRandomly();
  printf("Pierwsze 10 elementów globalArray:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", globalArray[i]);
  }
  printf("\n");

  /* ----------------
   * 2. Graph + BFS
   * ----------------*/
  globalGraph = createRandomGraph(20, 5);
  printf("Wykonujê BFS w globalGraph od wierzcho³ka 0...\n");
  bfs(&globalGraph, 0);

  /* ----------------
   * 3. Sortowanie
   * ----------------*/
  int testArray1[10];
  int testArray2[10];
  for (int i = 0; i < 10; i++) {
    int val = rand() % 100;
    testArray1[i] = val;
    testArray2[i] = val;
  }
  printf("Tablica przed sortowaniem:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", testArray1[i]);
  }
  printf("\n");

  mergeSort(testArray1, 0, 9);
  quickSort(testArray2, 0, 9);

  printf("Tablica po MergeSort:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", testArray1[i]);
  }
  printf("\n");

  printf("Tablica po QuickSort:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", testArray2[i]);
  }
  printf("\n");

  /* ----------------
   * 4. Macierze
   * ----------------*/
  Matrix A = createMatrix(5, 3);
  Matrix B = createMatrix(3, 5);

  Matrix C = multiplyMatrices(&A, &B);
  if (C.matrix != NULL) {
    printf("Wynik mno¿enia macierzy A(5x3) i B(3x5) to macierz %dx%d.\n",
           C.rows, C.cols);
  } else {
    printf("Nie mo¿na pomno¿yæ podanych macierzy.\n");
  }

  freeMatrix(&A);
  freeMatrix(&B);
  freeMatrix(&C);

  /* ----------------
   * 5. Wielow¹tkowoœæ
   * ----------------*/
  int arraySize = 100000;
  int *largeArray = (int *)malloc(arraySize * sizeof(int));
  for (int i = 0; i < arraySize; i++) {
    largeArray[i] = rand() % 100;
  }

  pthread_t threads[MAX_THREADS];
  ThreadData threadData[MAX_THREADS];
  int chunkSize = arraySize / MAX_THREADS;

  for (int i = 0; i < MAX_THREADS; i++) {
    threadData[i].thread_id = i;
    threadData[i].array = &largeArray[i * chunkSize];
    threadData[i].length =
        (i == MAX_THREADS - 1) ? (arraySize - i * chunkSize) : chunkSize;
    threadData[i].partial_sum = 0;
    pthread_create(&threads[i], NULL, threadFunction, &threadData[i]);
  }

  long long totalSum = 0;
  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
    totalSum += threadData[i].partial_sum;
  }
  printf("Sum of largeArray = %lld\n", totalSum);
  free(largeArray);

  /* ----------------
   * 6. Matematyka
   * ----------------*/
  long long num = 1234567890LL;
  printf("Czy %lld jest liczb¹ pierwsz¹? %s\n", num,
         isPrime(num) ? "TAK" : "NIE");
  primeFactorization(num);

  /* ----------------
   * 7. Funkcje rekurencyjne (fibonacci, factorial)
   * ----------------*/
  int fibN = 20;
  printf("fibonacci(%d) = %lld\n", fibN, fibonacci(fibN));
  int factN = 12;
  printf("factorial(%d) = %lld\n", factN, factorial(factN));

  /* Sprz¹tanie */
  freeGraph(&globalGraph);
  return 0;
}
