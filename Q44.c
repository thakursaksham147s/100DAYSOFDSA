/*
Problem Statement:
Perform inorder, preorder, and postorder traversals of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print inorder, preorder, and postorder traversals
Example:
Input:
7
1 2 3 4 5 6 7

Output:
4 2 5 1 6 3 7
1 2 4 5 3 6 7
4 5 2 6 7 3 1
*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};
struct Node* build(int arr[], int i, int n){
    if(i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = malloc(sizeof(struct Node));
    root->data = arr[i];

    root->left = build(arr, 2*i+1, n);
    root->right = build(arr, 2*i+2, n);

    return root;
}
void inorder(struct Node* r){
    if(r){
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}
void preorder(struct Node* r){
    if(r){
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}
void postorder(struct Node* r){
    if(r){
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}
int main(){

    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct Node* root = build(arr,0,n);

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);

    return 0;
}