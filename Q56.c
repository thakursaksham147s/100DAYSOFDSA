/*
Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.
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
    int f=0, r=0, i=1;

    q[r++] = root;

    while(i<n){
        struct Node* t = q[f++];

        if(i<n && a[i]!=-1){
            t->left = newNode(a[i]);
            q[r++] = t->left;
        }
        i++;

        if(i<n && a[i]!=-1){
            t->right = newNode(a[i]);
            q[r++] = t->right;
        }
        i++;
    }
    return root;
}
int mirror(struct Node* a, struct Node* b){
    if(!a && !b) return 1;
    if(!a || !b) return 0;

    return (a->data==b->data) &&
           mirror(a->left,b->right) &&
           mirror(a->right,b->left);
}
int main(){
    int n;
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    struct Node* root = build(a,n);

    printf(mirror(root,root) ? "YES" : "NO");

    return 0;
}