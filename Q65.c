/*
Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int d;
    struct Node* next;
};
int dfs(struct Node* a[], int v[], int i, int p) {
    v[i] = 1;

    for (struct Node* t = a[i]; t; t = t->next) 
    {
        if (!v[t->d]) {
            if (dfs(a, v, t->d, i))
                return 1;
        }
        else if (t->d != p)
            return 1;
    }
    return 0;
}
int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);

    struct Node* a[n];
    for (int i = 0; i < n; i++) a[i] = NULL;

    for (int i = 0; i < m; i++) 
    {
        scanf("%d %d", &u, &v);

        struct Node* t = malloc(sizeof(struct Node));
        t->d = v; t->next = a[u]; a[u] = t;

        t = malloc(sizeof(struct Node));
        t->d = u; t->next = a[v]; a[v] = t;
    }
    int vis[n];
    for (int i = 0; i < n; i++) vis[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i] && dfs(a, vis, i, -1)) {
            printf("YES");
            return 0;
        }
    }

    printf("NO");
}