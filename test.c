#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void populate(Node** node, FILE* file) {
    int value;
    fscanf(file, "%d", &value);
    *node = createNode(value);
    populateHelper(node, file);
}

void populateHelper(Node** node, FILE* file) {
    bool left, right;
    printf("Do you want to enter left of %d (1 for yes, 0 for no): ", (*node)->value);
    fscanf(file, "%d", &left);
    if (left) {
        int value;
        printf("Enter the value of the left of %d: ", (*node)->value);
        fscanf(file, "%d", &value);
        (*node)->left = createNode(value);
        populateHelper(&((*node)->left), file);
    }
    printf("Do you want to enter right of %d (1 for yes, 0 for no): ", (*node)->value);
    fscanf(file, "%d", &right);
    if (right) {
        int value;
        printf("Enter the value of the right of %d: ", (*node)->value);
        fscanf(file, "%d", &value);
        (*node)->right = createNode(value);
        populateHelper(&((*node)->right), file);
    }
}

void display(Node* node) {
    if (node == NULL)
        return;
    printf("%d\n", node->value);
    display(node->left);
    display(node->right);
}

void prettyDisplay(Node* node, int level) {
    if (node == NULL)
        return;
    prettyDisplay(node->right, level + 1);
    if (level != 0) {
        for (int i = 0; i < level - 1; i++) {
            printf("|\t\t");
        }
        printf("|-------> %d\n", node->value);
    } else {
        printf("%d\n", node->value);
    }
    prettyDisplay(node->left, level + 1);
}

int main() {
    Node* root = NULL;
    FILE* file = fopen("input.txt", "r");
    populate(&root, file);
    fclose(file);

    printf("Displaying the tree:\n");
    display(root);

    printf("\nPretty Display of the tree:\n");
    prettyDisplay(root, 0);

    return 0;
}

