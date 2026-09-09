#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value)
{
    struct node *NewNode;

    NewNode = (struct node *)malloc(sizeof(struct node));

    NewNode->data = value;
    NewNode->next = top;
    top = NewNode;

    printf("Inserted successfully\n");
}

void pop()
{
    if (top == NULL)
    {
        printf("The stack is empty\n");
    }
    else
    {
        struct node *temp = top;

        printf("Deleted: %d\n", temp->data);

        top = temp->next;

        free(temp);
    }
}

void display()
{
    if (top == NULL)
    {
        printf("The stack is empty\n");
    }
    else
    {
        struct node *temp = top;

        while (temp->next != NULL)
        {
            printf("%d --> ", temp->data);
            temp = temp->next;
        }

        printf("%d --> NULL\n", temp->data);
    }
}

int main()
{
    int value;
    int choice;

    while (1)
    {
        printf("\n\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
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
            printf("Exiting...");
            exit(0);

        default:
            printf("Invalid choice");
        }
    }

    return 0;
}