#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

// Push operation
void push(char x)
{
    stack[++top] = x;
}

// Pop operation
char pop()
{
    if (top == -1)
        return -1;
    return stack[top--];
}

// Function to return precedence
int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;

    printf("Enter the infix expression: ");
    scanf("%s", exp);

    printf("Postfix Expression: ");

    e = exp;

    while (*e != '\0')
    {
        if (isalnum(*e))
        {
            printf("%c", *e);
        }
        else if (*e == '(')
        {
            push(*e);
        }
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
            {
                printf("%c", x);
            }
        }
        else
        {
            while (top != -1 && priority(stack[top]) >= priority(*e))
            {
                printf("%c", pop());
            }
            push(*e);
        }

        e++;
    }

    while (top != -1)
    {
        printf("%c", pop());
    }

    printf("\n");

    return 0;
}