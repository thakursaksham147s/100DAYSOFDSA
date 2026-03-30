/*
Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values
Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2
*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* build(int a[], int i, int n){
    if(i>=n || a[i]==-1) return NULL;

    struct Node* r = malloc(sizeof(struct Node));
    r->data = a[i];

    r->left = build(a,2*i+1,n);
    r->right = build(a,2*i+2,n);

    return r;
}

struct Node* LCA(struct Node* r, int a, int b){
    if(!r || r->data==a || r->data==b)
        return r;

    struct Node* l = LCA(r->left,a,b);
    struct Node* rt = LCA(r->right,a,b);

    if(l && rt) return r;

    return l ? l : rt;
}

int main(){
    int n,a,b;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    struct Node* root = build(arr,0,n);

    scanf("%d %d",&a,&b);

    printf("%d", LCA(root,a,b)->data);

    return 0;
}