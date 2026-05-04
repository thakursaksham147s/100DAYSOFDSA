/*
Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
int main() {
    int n, m, u, v, s;

    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) 
    {
        scanf("%d %d", &u, &v);

        struct Node* temp = malloc(sizeof(struct Node));
        temp->data = v;
        temp->next = adj[u];
        adj[u] = temp;

    }
    scanf("%d", &s);

    int vis[n], q[n], front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        vis[i] = 0;

    q[rear++] = s;
    vis[s] = 1;

    while (front < rear) 
    {
        int curr = q[front++];
        printf("%d ", curr);

        for (struct Node* t = adj[curr]; t; t = t->next) {
            if (!vis[t->data]) {
                vis[t->data] = 1;
                q[rear++] = t->data;
            }
        }
    }

    return 0;
}