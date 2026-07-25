#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int stack[SIZE];
int top = -1;

void push(int value);
void pop();
void display();

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n===== STACK MENU =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}

// Push operation
void push(int value)
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow! Stack is Full.\n");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("%d pushed successfully.\n", value);
    }
}

// Pop operation
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! Stack is Empty.\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

// Display operation
void display()
{
    if (top == -1)
    {
        printf("Stack is Empty.\n");
    }
    else
    {
        int i;
        printf("Stack Elements (Top to Bottom):\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}