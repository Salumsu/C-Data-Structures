#include "int-helpers.h"
#include <errno.h>
#include <stdio.h>
#include <math.h>

int count_int_digits (int num) {
	int count = (num == 0) ? 1 : 0;
	while (num > 0) {
		count++;
		num /= 10;
	}
	return count;
} 

int get_int_nth_digit (int num, int index) {	
	// JUST RETURN FIRST DIGIT IF INDEX IS 0 OR NEGATIVE
	if (index > 9) {
		errno = EINVAL;
		perror("Index out of bounds");
		return -1;
	}
	if (num < 0) {
		num *= -1;
	}

	if (index < 1) return num % 10;

	int current_index = 0;
	while (current_index < index && num > 0) {
		current_index++;
		num /= 10;
	}

	if (num <= 0) {
		errno = EINVAL;
		perror("Index out of bounds");
		return -1;
	}

	return num % 10;
}

int get_int_nth_digit2 (int num, int index) {	
	// JUST RETURN FIRST DIGIT IF INDEX IS 0 OR NEGATIVE
	if (index > 9) {
		errno = EINVAL;
		perror("Index out of bounds");
		return -1;
	}

	if (num < 0) {
		num *= -1;
	}

	num /= pow(10, index);
	if (num <= 0) {
		errno = EINVAL;
		perror("Index out of bounds");
		return -1;
	}

	return num % 10;
}
