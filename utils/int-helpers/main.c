#include "int-helpers.h"
#include <stdio.h>

int main() {
	int test = 2398123;
	int count = count_int_digits(test);
	printf("===============\n");
	printf("Test count digits\n");
	printf("Expected: 7\n");
	printf("Got: %d\n", count);

	int digit = get_int_nth_digit(test * -1, 1);
	printf("===============\n");
	printf("Test get int nth digit\n");
	printf("Expected: 2\n");
	printf("Got: %d\n", digit);

	return 0;
}
