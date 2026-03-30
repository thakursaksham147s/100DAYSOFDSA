/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated
Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30
Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
int main() {
    int n, k, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    printf("Enter %d values: ", n);
    for (i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
            head = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    printf("Enter k: ");
    scanf("%d", &k);

    if (n > 0) 
    {
        k = k % n;

        if (k != 0) {
            temp->next = head; 

            struct Node *move = head;
            for (i = 1; i < n - k; i++)
                move = move->next;

            head = move->next;  
            move->next = NULL;
        }
    }
    printf("Rotated List: ");
    temp = head;
    while (temp) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}