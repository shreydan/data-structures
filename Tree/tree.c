#include <stdio.h>
#include <stdlib.h>

/*

Binary Tree: 
            non-linear data-structure
            Each node/element has 2 child-nodes

Traversal:
            Preorder:
                    root, left, right
            Postorder:
                    left, right, root
            Inorder:
                    left, root, right

Below Example:

                10 
        20                  30
                    40              50

*/

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} node;

node *newNode(int value) {
    node *new_node = malloc(sizeof(node));

    if(new_node == NULL) {
        printf("Memory Error!\n");
        exit(1);
    }

    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void preorder_traverse(node *current_node) {
    
    if(current_node == NULL) {
        return;
    }

    printf("%d\t",current_node->value);
    preorder_traverse(current_node->left);
    preorder_traverse(current_node->right);

}

void postorder_traverse(node *current_node) {

    if(current_node == NULL) {
        return;
    }

    postorder_traverse(current_node->left);
    postorder_traverse(current_node->right);
    printf("%d\t", current_node->value);

}

void inorder_traverse(node *current_node) {

    if(current_node == NULL) {
        return;
    }

    inorder_traverse(current_node->left);
    printf("%d\t", current_node->value);
    inorder_traverse(current_node->right);

}


int main() {

    node *n1 = newNode(10);
    node *n2 = newNode(20);
    node *n3 = newNode(30);
    node *n4 = newNode(40);
    node *n5 = newNode(50);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    printf("PREORDER:\n");
    preorder_traverse(n1);
    printf("\nPOSTORDER:\n");
    postorder_traverse(n1);
    printf("\nINORDER:\n");
    inorder_traverse(n1);
    printf("\n");


    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);

    return 0;
}