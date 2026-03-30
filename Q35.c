/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated
Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50
Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.
*/
#include <stdio.h>

int main() {
    int n, i;
    int queue[100];
    int front = 0, rear = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) 
    {
        rear++;
        scanf("%d", &queue[rear]);
    }
    printf("Queue elements: ");
    for(i = front; i <= rear; i++) 
    {
        printf("%d ", queue[i]);
    }
    return 0;
}