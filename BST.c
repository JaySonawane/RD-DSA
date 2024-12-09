#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function prototypes
struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);

// Main function
int main() {
    struct node *tree = NULL; // Initialize tree as empty
    int option, val;

    do {
        printf("\n****** MAIN MENU ******\n");
        printf("1. Insert Element\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("Enter the value of the new node: ");
            scanf("%d", &val);
            tree = insertElement(tree, val);
            break;
        case 2:
            printf("\nPreorder Traversal: ");
            preorderTraversal(tree);
            printf("\n");
            break;
        case 3:
            printf("\nInorder Traversal: ");
            inorderTraversal(tree);
            printf("\n");
            break;
        case 4:
            printf("\nPostorder Traversal: ");
            postorderTraversal(tree);
            printf("\n");
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option! Please try again.\n");
        }
    } while (option != 5);

    return 0;
}

// Function to insert an element into the tree
struct node *insertElement(struct node *tree, int val) {
    if (tree == NULL) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (val < tree->data) {
        tree->left = insertElement(tree->left, val);
    } else {
        tree->right = insertElement(tree->right, val);
    }

    return tree;
}

// Function for preorder traversal
void preorderTraversal(struct node *tree) {
    if (tree != NULL) {
        printf("%d ", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}

// Function for inorder traversal
void inorderTraversal(struct node *tree) {
    if (tree != NULL) {
        inorderTraversal(tree->left);
        printf("%d ", tree->data);
        inorderTraversal(tree->right);
    }
}

// Function for postorder traversal
void postorderTraversal(struct node *tree) {
    if (tree != NULL) {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d ", tree->data);
    }
}
