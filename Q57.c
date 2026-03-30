/*
Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print inorder traversal of mirrored tree
Example:
Input:
7
1 2 3 4 5 6 7

Output:
7 3 6 1 5 2 4

Explanation:
Each node’s left and right children are swapped recursively.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};
struct Node* newNode(int x){
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}
struct Node* build(int a[], int n){
    if(n==0 || a[0]==-1) return NULL;

    struct Node* root = newNode(a[0]);
    struct Node* q[1000];
    int f=0,r=0,i=1;

    q[r++] = root;

    while(i<n){
        struct Node* t = q[f++];

        if(i<n && a[i]!=-1)
            q[r++] = t->left = newNode(a[i]);
        i++;

        if(i<n && a[i]!=-1)
            q[r++] = t->right = newNode(a[i]);
        i++;
    }
    return root;
}
void solve(struct Node* r){
    if(!r) return;

    struct Node* temp = r->left;
    r->left = r->right;
    r->right = temp;

    solve(r->left);
    printf("%d ", r->data);
    solve(r->right);
}
int main(){
    int n;
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    struct Node* root = build(a,n);

    solve(root);

    return 0;
}