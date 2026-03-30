/*
Problem Statement:
Perform zigzag(spiral)level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order
Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7
Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.
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
void zigzag(struct Node* root){
    if(!root) return;

    struct Node* s1[1000], *s2[1000];
    int t1=0, t2=0;

    s1[t1++] = root;

    while(t1 || t2){

        while(t1){
            struct Node* t = s1[--t1];
            printf("%d ", t->data);

            if(t->left)  s2[t2++] = t->left;
            if(t->right) s2[t2++] = t->right;
        }
        while(t2){
            struct Node* t = s2[--t2];
            printf("%d ", t->data);

            if(t->right) s1[t1++] = t->right;
            if(t->left)  s1[t1++] = t->left;
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    struct Node* root = build(a,0,n);

    zigzag(root);

    return 0;
}