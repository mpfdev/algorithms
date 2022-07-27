#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *list = malloc(3 * sizeof(int));

    *list = 1;
    *(list + 1) = 2;
    *(list + 2) = 3;

    int *temp = malloc(4 * sizeof(int));

    for(int i = 0; i < 3; i++) {
        temp[i] = list[i];
    }

    free(list);

    list = temp;

    list[3] = 10;

    for(int i = 0; i < 4; i++) {
        printf("%i\n", list[i]);
    }

    free(list);

    return 0;
}