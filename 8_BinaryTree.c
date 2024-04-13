#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *root = NULL;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void populateRecursive(Node *node)
{
    char choice;
    printf("Do you want to enter left of %d (y/n)? ", node->value);
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        printf("Enter the value of the left of %d: ", node->value);
        int value;
        scanf("%d", &value);
        node->left = createNode(value);
        populateRecursive(node->left);
    }

    printf("Do you want to enter right of %d (y/n)? ", node->value);
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        printf("Enter the value of the right of %d: ", node->value);
        int value;
        scanf("%d", &value);
        node->right = createNode(value);
        populateRecursive(node->right);
    }
}

void displayPreorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printf("%d ", node->value);
    displayPreorder(node->left);
    displayPreorder(node->right);
}

void displayIndented(Node *node, int level)
{
    if (node == NULL)
    {
        return;
    }
    displayIndented(node->right, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf("\t");
    }
    printf("%d\n", node->value);
    displayIndented(node->left, level + 1);
}

int main()
{
    printf("Enter the root Node: ");
    int value;
    scanf("%d", &value);
    root = createNode(value);
    populateRecursive(root);

    printf("Preorder traversal: ");
    displayPreorder(root);
    printf("\n");
    printf("Indented display:\n");
    displayIndented(root, 0);

    return 0;
}
