/*
Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int d;
    struct Node* next;
};
int dfs(struct Node* a[], int vis[], int rec[], int i) {
    vis[i] = rec[i] = 1;

    for (struct Node* t = a[i]; t; t = t->next) {
        if (!vis[t->d] && dfs(a, vis, rec, t->d))
            return 1;
        else if (rec[t->d])
            return 1;
    }

    rec[i] = 0; // remove from stack
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
        t->d = v;
        t->next = a[u];
        a[u] = t;
    }
    int vis[n], rec[n];
    for (int i = 0; i < n; i++)
        vis[i] = rec[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i] && dfs(a, vis, rec, i)) 
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}