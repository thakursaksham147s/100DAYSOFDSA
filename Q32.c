/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom
Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10
*/
#include <stdio.h>

int main() {
    int stack[100], top = -1;
    int n, m, i;

    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) 
    {
        scanf("%d", &stack[++top]);
    }
    printf("Enter number of elements to pop: ");
    scanf("%d", &m);

    for(i = 0; i < m; i++) 
    {
        if(top == -1) 
        {
            printf("Stack Underflow\n");
            break;
        }
        top--;
    }
    printf("Remaining stack elements: ");
    for(i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    return 0;
}