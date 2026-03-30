/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression
Example:
Input:
A+B*C

Output:
ABC*+
Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity
*/
#include <stdio.h>
#include <ctype.h>

int main() {
    char infix[100], postfix[100], stack[100];
    int i = 0, j = 0, top = -1;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') 
    {
        if (isalnum(infix[i])) {   // operand
            postfix[j++] = infix[i];
        }
        else 
        {                     // operator
            while (top >= 0 && 
                 ((stack[top] == '*' || stack[top] == '/') ||
                 ((infix[i] == '+' || infix[i] == '-') && (stack[top] == '+' || stack[top] == '-')))) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
        i++;
    }
    while (top >= 0) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';

    printf("Postfix expression: %s", postfix);

    return 0;
}