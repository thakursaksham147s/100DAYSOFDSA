/*
Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree
Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* build(int arr[], int i, int n)
{
    if(i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = malloc(sizeof(struct Node));
    root->data = arr[i];

    root->left = build(arr, 2*i+1, n);
    root->right = build(arr, 2*i+2, n);

    return root;
}
int height(struct Node* root) {
    if(root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}
int main() {

    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct Node* root = build(arr,0,n);

    printf("%d", height(root));

    return 0;
}