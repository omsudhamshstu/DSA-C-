#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool adj[MAX][MAX], visited[MAX];

bool dfs(int v, int parent, int n) {
    visited[v] = true;
    for (int u = 0; u < n; u++) {
        if (adj[v][u]) {
            if (!visited[u]) {
                if (dfs(u, v, n)) return true;
            } else if (u != parent) return true;
        }
    }
    return false;
}

bool containsCycle(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dfs(i, -1, n)) return true;
    }
    return false;
}

int main() {
    int n, e, u, v;
    scanf("%d %d", &n, &e); // number of vertices and edges
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = true;
    }
    if (containsCycle(n)) printf("Graph contains cycle\n");
    else printf("Graph doesn't contain cycle\n");
    return 0;
}