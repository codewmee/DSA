#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int cQueue[SIZE];
int front = -1, rear = -1;

void enQueue(int value);
void deQueue();
void display();

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n===== Circular Queue Menu =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enQueue(value);
            break;

        case 2:
            deQueue();
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

// Insert element
void enQueue(int value)
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf("Queue Overflow! Queue is Full.\n");
    }
    else
    {
        if (rear == SIZE - 1 && front != 0)
            rear = -1;

        cQueue[++rear] = value;

        if (front == -1)
            front = 0;

        printf("%d inserted successfully.\n", value);
    }
}

// Delete element
void deQueue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow! Queue is Empty.\n");
    }
    else
    {
        printf("Deleted element: %d\n", cQueue[front++]);

        if (front == SIZE)
            front = 0;

        if (front - 1 == rear)
            front = rear = -1;
    }
}

// Display queue
void display()
{
    if (front == -1)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        int i = front;

        printf("Queue Elements: ");

        if (front <= rear)
        {
            while (i <= rear)
            {
                printf("%d ", cQueue[i]);
                i++;
            }
        }
        else
        {
            while (i < SIZE)
            {
                printf("%d ", cQueue[i]);
                i++;
            }

            i = 0;

            while (i <= rear)
            {
                printf("%d ", cQueue[i]);
                i++;
            }
        }

        printf("\n");
    }
}