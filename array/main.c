#include <stdlib.h>
#include <stdio.h>
#include "array.h"

int main() {
	int array[] = {3, 5, 1, 9, 2};
	// bubble_sort(array, 5);
	// selection_sort(array, 5);
	// insertion_sort(array, 5);
	// merge_sort(array, 5);
	// quick_sort(array, 5);
	radix_sort(array, 5);
	print_array(array, 5);

	return 0;
}