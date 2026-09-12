
#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
    int data;
    struct BST *left, *right;
} node;

node *root = NULL;

/* Insert a node into BST */
node* Insert(node *root, int data)
{
    if (root == NULL)
    {
        root = (node*)malloc(sizeof(node));

        if (root == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }

    return root;
}

/* Inorder: Left -> Root -> Right */
void inorder(node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

/* Preorder: Root -> Left -> Right */
void preorder(node *temp)
{
    if (temp != NULL)
    {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

/* Postorder: Left -> Right -> Root */
void postorder(node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}

int main()
{
    int choice, num;

    while (1)
    {
        printf("\n---------- MENU ----------\n");
        printf("1. Insert\n");
        printf("2. Preorder Display\n");
        printf("3. Inorder Display\n");
        printf("4. Postorder Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter your number: ");
                scanf("%d", &num);

                root = Insert(root, num);
                break;

            case 2:
                printf("Pre-Order Display:\n");
                preorder(root);
                printf("\n");
                break;

            case 3:
                printf("In-Order Display:\n");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Post-Order Display:\n");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("\n---- Wrong Option ----\n");
        }
    }

    return 0;
}