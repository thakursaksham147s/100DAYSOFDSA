/*
Problem: BST Insert

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
struct Node* insert(struct Node* root, int val){
    if(root == NULL){
        struct Node* n = malloc(sizeof(struct Node));
        n->data = val;
        n->left = n->right = NULL;
        return n;
    }

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}
void inorder(struct Node* root){
    if(root){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main(){
    int n;
    scanf("%d",&n);

    struct Node* root = NULL;

    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        root = insert(root, x);
    }

    inorder(root);

    return 0;
}