/*
Problem: Level Order Traversal

Implement the solution for this problem.
Input:
- Input specifications
5
1 2 3 4 5

Output:
- Output specifications
1 2 3 4 5
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* build(int a[], int i, int n) {
    if(i >= n || a[i] == -1) return NULL;

    struct Node* r = malloc(sizeof(struct Node));
    r->data = a[i];

    r->left = build(a, 2*i+1, n);
    r->right = build(a, 2*i+2, n);

    return r;
}
void levelOrder(struct Node* r) {
    if(!r) return;

    struct Node* q[100];
    int f = 0, re = 0;

    q[re++] = r;

    while(f < re){
        struct Node* t = q[f++];
        printf("%d ", t->data);

        if(t->left)  q[re++] = t->left;
        if(t->right) q[re++] = t->right;
    }
}
int main() {
    int n;
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    struct Node* root = build(a,0,n);

    levelOrder(root);

    return 0;
}