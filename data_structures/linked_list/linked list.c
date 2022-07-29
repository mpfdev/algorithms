#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} node;

int main(void) {

    node *list = NULL;

    //A node is created with garbage values in it
    node *n = malloc(sizeof(node));

    //Check if there is enough space in memory to create the node
    if(n != NULL) {
        //n is filled with garbage values, reassigning the values.
        n -> number = 1;
        n -> next = NULL;
    }

    //Assigning the node as the first item of the list.
    list = n;

    n = malloc(sizeof(node));

    if(n == NULL) {
        return 1;
    }

    n -> number = 2;
    n -> next = NULL;

    list -> next = n;

    n = malloc(sizeof(node));

    if(n == NULL) {
        return 1;
    }

    n -> number = 3;
    n -> next = NULL;

    list -> next -> next = n;

    for(node *temp = list; temp != NULL; temp = temp -> next) {
        printf("%i\n", temp -> number);
    }

    //Free memory from the nexts to the higher level of the list
    free(list -> next -> next);
    free(list -> next);
    free(list);

    return 0;
}