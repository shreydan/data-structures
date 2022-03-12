#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*

BINARY SEARCH TREE

Explanation: https://www.programiz.com/dsa/binary-search-tree


notes:

1. inorder traversal gives all values in increasing order

2. Complexity:

Operation       Best            Average         Worst       Space
			
Search          O(log n)        O(log n)        O(n)        O(n)
			
Insertion       O(log n)        O(log n)        O(n)        O(n)
			
Deletion        O(log n)        O(log n)        O(n)        O(n)

*/

typedef struct node {
    int value;
    struct node *left;
    struct node *right;

} node;

node *newNode(int value) {
    node *new_node = malloc(sizeof(node));

    if (new_node != NULL) {
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}

bool insertNode(node **rootPtr, int value) {
    node *root = *rootPtr;

    if (root == NULL) {
        // if tree empty, create root
        *rootPtr = newNode(value);
        return true;
    }

    if (value == root->value) {
        // value to be added already exists
        // so no need to add
        return false;
    }

    if (value < root->value) {
        return insertNode(&(root->left), value);
    } else {
        return insertNode(&(root->right), value);
    }
}

int minValue(node *root) {
    node *min = root;

    if (min->left != NULL) {
        min = min->left;
        return minValue(min);
    } else {
        return min->value;
    }
}
node *minValueNode(struct node *node) {
    struct node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

int maxValue(node *root) {
    node *max = root;

    if (max->right != NULL) {
        max = max->right;
        return maxValue(max);
    } else {
        return max->value;
    }
}

bool foundValue(node *root, int value) {
    if (root == NULL) {
        return false;
    }

    if (value == root->value) {
        return true;
    }
    if (value < root->value) {
        return foundValue(root->left, value);
    } else {
        return foundValue(root->right, value);
    }
}

node *deleteNode(struct node *root, int value) {
    if (root == NULL) return root;
    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);

    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        node *temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

void preorder_traverse(node *current_node) {
    if (current_node == NULL) {
        return;
    }

    printf("%d\t", current_node->value);
    preorder_traverse(current_node->left);
    preorder_traverse(current_node->right);
}
void inorder_traverse(node *current_node) {
    if (current_node == NULL) {
        return;
    }

    inorder_traverse(current_node->left);
    printf("%d\t", current_node->value);
    inorder_traverse(current_node->right);
}

int main() {
    node *root = NULL;

    insertNode(&root, 15);
    insertNode(&root, 11);
    insertNode(&root, 24);
    insertNode(&root, 5);
    insertNode(&root, 19);
    insertNode(&root, 16);
    printf("Preorder:\t");
    preorder_traverse(root);
    printf("\n");
    root = deleteNode(root, 5);
    printf("Preorder:\t");
    preorder_traverse(root);
    printf("\n");
    return 0;
}