/*
Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int d;
    struct Node* next;
};
void dfs(struct Node* a[], int v[], int s[], int* top, int u) 
{
    v[u] = 1;

    for (struct Node* t = a[u]; t; t = t->next)
        if (!v[t->d])
            dfs(a, v, s, top, t->d);

    s[(*top)++] = u; // push to stack
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
    int vis[n], stack[n], top = 0;
    for (int i = 0; i < n; i++) vis[i] = 0;

    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(a, vis, stack, &top, i);

    for (int i = top - 1; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}