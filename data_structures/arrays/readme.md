# Arrays

- Creating an array in heap memory, allocating memory with malloc

```c
#include <stdio.h>

int main(void) {

	//creating an array of size of 3 in heap memory
	int *list = malloc(3 * sizeof(int));

	//if computer is out of memory
	//error check
	if(list == NULL) {
		return 1;
	}
	
	//pointer arithmetic
	*list = 1;
	*(list + 1) = 2;
	*(list + 2) = 3;
	
}
```

- Creating an array in stack memory

```c
#include <stdio.h>

int main(void) {
	//arrain in stack memory
	int list[3];

	//bracket notation does the pointers arithmetic
	list[0] = 1;
	list[1] = 2;
	list[2] = 3;
}
```

## Insertion

- In C, arrays have fixed sizes.
- How to insert a new element?
    
    Creating a new temporary address with `malloc` , looping through to copy values from the original list, and then adding the new element.
    

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	//Dinamically allocate of size 3
	int *list = malloc(3 * sizeof(int));

	//Pointer Arithmetic to assign values
	*list = 1;
	*(list + 1) = 2;
	*(list + 2) = 3;

	//Dinamically allocate of size 4
	int *temp = malloc(4 * sizeof(int));
	
	for(int i = 0; i < 3; i++) {
		temp[i] = list[i];
	}
	
	//Free memory from the previous list
	free(list);

	list = temp;

	list[3] = 10;

	for(int i = 0; i < 4; i++) {
		printf("%i\n", list[i]);
	}

	free(list);

	return 0;
}
```

- We can also use `realloc(address from the list to resize, size`.