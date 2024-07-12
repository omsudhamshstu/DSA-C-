#include <stdio.h>
#define MS 5

int graph[MS][MS] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}
};

int visited[MS] = {0};
void dfs(int start) {
    visited[start] = 1;
    printf("%3d", start);
    for(int i = 0; i < MS; i++){
        if(graph[start][i] && !visited[i]){
            dfs(i);
        }
    }
}

int main() {
    printf("DFS traversal: ");
    dfs(1);
    return 0;
}