/*
Problem: Count Leaf Nodes

Implement the solution for this problem.
Input:
- Input specifications

Output:
- Output specifications
*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};
struct Node* build(int a[], int i, int n){
    if(i >= n || a[i] == -1) return NULL;

    struct Node* r = malloc(sizeof(struct Node));
    r->data = a[i];

    r->left = build(a, 2*i+1, n);
    r->right = build(a, 2*i+2, n);

    return r;
}
int countLeaf(struct Node* r){
    if(!r) return 0;

    if(!r->left && !r->right)   // leaf node
        return 1;

    return countLeaf(r->left) + countLeaf(r->right);
}
int main() {
    int n;
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    struct Node* root = build(a,0,n);

    printf("%d", countLeaf(root));

    return 0;
}