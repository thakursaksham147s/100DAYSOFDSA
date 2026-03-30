/*
Problem: BST Search

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
int search(struct Node* r, int x){
    if(!r) return 0;
    if(r->data == x) return 1;
    if(x < r->data) return search(r->left, x);
    return search(r->right, x);
}
int main(){
    int n, x;
    scanf("%d",&n);

    struct Node* root = NULL;

    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        root = insert(root, val);
    }

    scanf("%d",&x);

    printf(search(root, x) ? "Found" : "Not Found");

    return 0;
}