/*
Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value
Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6
*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};
struct Node* insert(struct Node* r, int x){
    if(!r){
        r = malloc(sizeof(struct Node));
        r->data = x;
        r->left = r->right = NULL;
        return r;
    }
    if(x < r->data) r->left = insert(r->left, x);
    else r->right = insert(r->right, x);
    return r;
}
struct Node* LCA(struct Node* r, int a, int b){
    while(r){
        if(a < r->data && b < r->data) r = r->left;
        else if(a > r->data && b > r->data) r = r->right;
        else return r;
    }
    return NULL;
}
int main(){
    int n, x, a, b;
    scanf("%d",&n);

    struct Node* root = NULL;

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        root = insert(root, x);
    }

    scanf("%d %d",&a,&b);

    printf("%d", LCA(root, a, b)->data);

    return 0;
}