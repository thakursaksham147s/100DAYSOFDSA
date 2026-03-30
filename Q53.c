/*
Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line
Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7
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
void findRange(struct Node* r, int hd, int *min, int *max){
    if(!r) return;

    if(hd < *min) *min = hd;
    if(hd > *max) *max = hd;

    findRange(r->left, hd-1, min, max);
    findRange(r->right, hd+1, min, max);
}
void printVertical(struct Node* r, int hd, int line){
    if(!r) return;

    if(hd == line)
        printf("%d ", r->data);

    printVertical(r->left, hd-1, line);
    printVertical(r->right, hd+1, line);
}
int main(){
    int n;
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    struct Node* root = build(a,0,n);

    int min=0, max=0;
    findRange(root, 0, &min, &max);

    for(int i=min;i<=max;i++){
        printVertical(root, 0, i);
        printf("\n");
    }
    return 0;
}