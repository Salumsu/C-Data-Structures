#include <stdlib.h>
#include <stdio.h>
#include "array.h"

int main() {
	int array[] = {1, 2, 5, 7, 9};
	// bubble_sort(array, 5);
	// selection_sort(array, 5);
	// insertion_sort(array, 5);
	// merge_sort(array, 5);
	// quick_sort(array, 5);
	// radix_sort(array, 5);
	// print_array(array, 5);

	int index = binary_search(array, 5, 9);
	printf("Found 1 at index: %d\n", index);

	return 0;
}