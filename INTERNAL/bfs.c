#include <stdio.h>

#define MAX 5

int graph[MAX][MAX] = {{0, 1, 1, 0, 0},
                       {1, 0, 0, 1, 0},
                       {1, 0, 0, 1, 1},
                       {0, 1, 1, 0, 1},
                       {0, 0, 1, 1, 0}};

int visited[MAX] = {0};
int queue[MAX], front = -1, rear = -1;

void bfs(int start) {
  visited[start] = 1;
  queue[rear++] = start;

  while (front != rear) {
    int curr = queue[front++];
    printf("%d ", curr);

    for (int i = 0; i < MAX; i++) {
      if (graph[curr][i] && !visited[i]) {
        visited[i] = 1;
        queue[rear++] = i;
      }
    }
  }
}

int main() {
  printf("BFS traversal: ");
  bfs(2);
  return 0;
}