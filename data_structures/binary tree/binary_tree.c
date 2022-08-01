#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *left;
    struct node *right;
} node;

void free_space(node *root);

int main(void) {

    //Create an empty list
    node *list = NULL;

    //Create a node with garbage values
    node *n = malloc(sizeof(node));

    if(n != NULL) {
        //Assign values
        n -> number = 2;
        n -> left = NULL;
        n -> right = NULL;
    }

    list = n;

    n = malloc(sizeof(node));

    if(n != NULL) {
        n -> number = 1;
        n -> left = NULL;
        n -> right = NULL;
    }

    list -> left = n;

    n = malloc(sizeof(node));

    if(n != NULL) {
        n -> number = 3;
        n -> left = NULL;
        n -> right = NULL;
    }

    list -> right = n;

    free_space(list);

}

void free_space(node *root) {
    if(root != NULL) {
        free_space(root->left);
        free_space(root->right);
        free(root);
    }
}