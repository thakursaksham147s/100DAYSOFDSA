/*
Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
*/
#include <stdio.h>
#include <stdlib.h>

struct Node { int d; struct Node* next; };

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
    }
    int indeg[n];
    for (int i = 0; i < n; i++) indeg[i] = 0;

    for (int i = 0; i < n; i++)
        for (struct Node* t = a[i]; t; t = t->next)
            indeg[t->d]++;

    int q[n], f = 0, b = 0;

    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            q[b++] = i;

    while (f < b) 
    {
        int x = q[f++];
        printf("%d ", x);

        for (struct Node* t = a[x]; t; t = t->next)
            if (--indeg[t->d] == 0)
                q[b++] = t->d;
    }
}