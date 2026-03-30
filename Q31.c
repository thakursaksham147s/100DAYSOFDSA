/*Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'
Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10
*/
#include <stdio.h>

#define MAX 100

int stack[MAX], top = -1;

int main() {
    int n, ch, val;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    while (n--) 
    {
        printf("Enter operation (1-Push, 2-Pop, 3-Display): ");
        scanf("%d", &ch);

        if (ch == 1) 
        {
            printf("Enter value: ");
            scanf("%d", &val);
            if (top == MAX - 1)
                printf("Stack Overflow\n");
            else
                stack[++top] = val;
        }
        else if (ch == 2) 
        {
            if (top == -1)
                printf("Stack Underflow\n");
            else
                printf("%d\n", stack[top--]);
        }
        else if (ch == 3) 
        {
            if (top == -1)
                printf("Stack is Empty\n");
            else {
                for (int i = top; i >= 0; i--)
                    printf("%d ", stack[i]);
                printf("\n");
            }
        }
    }
    return 0;
}