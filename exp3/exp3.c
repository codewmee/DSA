#include <stdio.h>
#include <ctype.h>
#include <math.h>

int stack[50];
int top = -1;

// Function Prototypes
void push(int x);
int pop();

int main()
{
    char exp[50];
    int i = 0;
    int op1, op2;
    int result;

    printf("Enter the postfix expression: ");
    scanf("%s", exp);

    while (exp[i] != '\0')
    {
        // If the character is a digit, push it onto the stack
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            // Pop two operands
            op1 = pop();
            op2 = pop();

            // Perform the operation
            switch (exp[i])
            {
            case '+':
                push(op2 + op1);
                break;

            case '-':
                push(op2 - op1);
                break;

            case '*':
                push(op2 * op1);
                break;

            case '/':
                push(op2 / op1);
                break;

            case '^':
                push((int)pow(op2, op1));
                break;

            default:
                printf("Invalid operator!\n");
                return 1;
            }
        }

        i++;
    }

    // Final result
    result = pop();

    printf("\nThe answer of postfix expression %s = %d\n", exp, result);

    return 0;
}

// Push function
void push(int x)
{
    top++;
    stack[top] = x;
}

// Pop function
int pop()
{
    int value;

    value = stack[top];
    top--;

    return value;
}