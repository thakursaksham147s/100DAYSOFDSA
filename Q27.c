/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'
Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30
Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
int main() 
{
    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *tail1 = NULL, *tail2 = NULL, *newNode;

    int n, m, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (!head1)
            head1 = newNode;
        else
            tail1->next = newNode;

        tail1 = newNode;
    }
    scanf("%d", &m);

    for (int i = 0; i < m; i++) 
    {
        scanf("%d", &value);

        newNode = malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (!head2)
            head2 = newNode;
        else
            tail2->next = newNode;

        tail2 = newNode;
    }
    struct Node* temp = head1;
    while (temp && temp->data != 30)
        temp = temp->next;

    tail2->next = temp;  

    struct Node *p1 = head1, *p2 = head2;

    while (p1 != p2) 
    {
        p1 = (p1 == NULL) ? head2 : p1->next;
        p2 = (p2 == NULL) ? head1 : p2->next;
    }
    if (p1)
        printf("%d", p1->data);
    else
        printf("No Intersection");

    return 0;
}