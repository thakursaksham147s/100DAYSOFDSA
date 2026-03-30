/*
Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes
Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6
Explanation:
At each level, the rightmost node is visible from the right view.
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

void rightView(struct Node* r){
    if(!r) return;

    struct Node* q[1000];
    int f=0, re=0;

    q[re++] = r;

    while(f < re){
        int n = re - f;

        while(n--){
            struct Node* t = q[f++];

            if(n==0) printf("%d ", t->data); // last node

            if(t->left) q[re++] = t->left;
            if(t->right) q[re++] = t->right;
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    struct Node* root = build(a,0,n);

    rightView(root);

    return 0;
}