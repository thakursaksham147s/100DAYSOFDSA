/*
Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree
Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.
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
int search(int in[], int s, int e, int x){
    for(int i=s;i<=e;i++)
        if(in[i]==x) return i;
    return -1;
}
int preIndex = 0;

struct Node* build(int pre[], int in[], int s, int e){
    if(s > e) return NULL;

    struct Node* root = newNode(pre[preIndex++]);

    int pos = search(in, s, e, root->data);

    root->left = build(pre, in, s, pos-1);
    root->right = build(pre, in, pos+1, e);

    return root;
}
void post(struct Node* r){
    if(!r) return;

    post(r->left);
    post(r->right);
    printf("%d ", r->data);
}
int main(){
    int n;
    scanf("%d",&n);

    int pre[n], in[n];

    for(int i=0;i<n;i++) scanf("%d",&pre[i]);
    for(int i=0;i<n;i++) scanf("%d",&in[i]);

    struct Node* root = build(pre, in, 0, n-1);

    post(root);

    return 0;
}