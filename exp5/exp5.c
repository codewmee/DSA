
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function declarations
void insertAtBeginning(int value);
void insertAtEnd(int value);
void insertBetween(int value, int loc1, int loc2);
void display();
void removeBeginning();
void removeEnd();
void removeSpecific(int value);

int main()
{
    int choice, value, choice1, loc1, loc2;

    while (1)
    {
        printf("\n\n===== SINGLY LINKED LIST =====\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the value to be inserted: ");
            scanf("%d", &value);

            printf("\nLocation to insert:\n");
            printf("1. At Beginning\n");
            printf("2. At End\n");
            printf("3. Between\n");
            printf("Enter your choice: ");
            scanf("%d", &choice1);

            switch (choice1)
            {
            case 1:
                insertAtBeginning(value);
                break;

            case 2:
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter the two values between which the node should be inserted: ");
                scanf("%d %d", &loc1, &loc2);
                insertBetween(value, loc1, loc2);
                break;

            default:
                printf("\nInvalid choice!\n");
            }
            break;

        case 2:
            display();
            break;

        case 3:
            printf("\nHow do you want to delete?\n");
            printf("1. From Beginning\n");
            printf("2. From End\n");
            printf("3. Specific Node\n");
            printf("Enter your choice: ");
            scanf("%d", &choice1);

            switch (choice1)
            {
            case 1:
                removeBeginning();
                break;

            case 2:
                removeEnd();
                break;

            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                removeSpecific(value);
                break;

            default:
                printf("\nInvalid choice!\n");
            }
            break;

        case 4:
            printf("\nProgram terminated.\n");
            exit(0);

        default:
            printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}

// Insert at beginning
void insertAtBeginning(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("\nMemory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("\nNode inserted at beginning.\n");
}

// Insert at end
void insertAtEnd(int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("\nMemory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("\nNode inserted at end.\n");
}

// Insert between two nodes
void insertBetween(int value, int loc1, int loc2)
{
    struct Node *newNode, *temp;

    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    temp = head;

    while (temp != NULL)
    {
        if (temp->data == loc1 || temp->data == loc2)
        {
            break;
        }

        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nGiven location values not found.\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("\nMemory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("\nNode inserted successfully.\n");
}

// Delete from beginning
void removeBeginning()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);

    printf("\nNode deleted from beginning.\n");
}

// Delete from end
void removeEnd()
{
    struct Node *temp, *prev;

    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    // Only one node
    if (head->next == NULL)
    {
        free(head);
        head = NULL;

        printf("\nNode deleted from end.\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("\nNode deleted from end.\n");
}

// Delete a specific node
void removeSpecific(int value)
{
    struct Node *temp, *prev;

    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    // If first node contains the value
    if (head->data == value)
    {
        temp = head;
        head = head->next;

        free(temp);

        printf("\nNode deleted successfully.\n");
        return;
    }

    temp = head;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nGiven value not found in the list.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("\nNode deleted successfully.\n");
}

// Display the linked list
void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    temp = head;

    printf("\nLinked List:\n");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
