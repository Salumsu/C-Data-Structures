#include "array.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../utils/int-helpers/int-helpers.h"

void print_array(int* array, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d: %d\n", i, array[i]);
	}
}

void bubble_sort(int* array, int size) {
	bool is_sorted = false;
	while (!is_sorted) {
		is_sorted = true;

		for (int i = 0; i < size - 1; i++) {
			if (array[i] > array[i + 1]) {
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				is_sorted = false;
			}
		}
	}
}

void selection_sort(int* array, int size) {
	for (int i = 0; i < size - 1; i++) {
		int lowest_index = i;
		for (int j = i + 1; j < size; j++) {
			if (array[j] < array[lowest_index]) {
				lowest_index = j;
			}
		}
		int temp = array[i];
		array[i] = array[lowest_index];
		array[lowest_index] = temp;
	}
}

void insertion_sort(int* array, int size) {
	for (int i = 1; i < size; i++) {
		int current_item = array[i];
		int j = i - 1;
		while (j >= 0 && current_item < array[j]) {
			array[j + 1] = array[j];
			j--;
		}

		array[j + 1] = current_item;
	}
}

void merge_sort(int* array, int size) {
	int half = size / 2;
	int second_half = size - half;
	int* left = (int*)calloc(half, sizeof(int));
	int* right = (int*)calloc(second_half, sizeof(int));
	for (int i = 0; i < half; i++) {
		left[i] = array[i];
	}
	for (int i = half; i < size; i++) {
		right[i - half] = array[i];
	}
	if (half > 1) {
		merge_sort(left, half);
	}
	if (second_half > 1) {
		merge_sort(right, second_half);
	}

	int left_index = 0;
	int right_index = 0;
	int array_index = 0;
	while (left_index < half && right_index < second_half) {
		if (left[left_index] < right[right_index]) {
			array[array_index++] = left[left_index++];
		} else {
			array[array_index++] = right[right_index++];
		}
	}	

	// LEFTOVERS
	while (left_index < half)
	{
		array[array_index++] = left[left_index++];
	}
	
	// LEFTOVERS
	while (right_index < second_half)
	{
		array[array_index++] = right[right_index++];
	}
	
}


void _quick_sort(int* array, int pivot, int end) {
	int store_index = pivot + 1;
	for (int i = store_index; i < end; i++) {
		if (array[i] <= array[pivot]) {
			int temp = array[i];
			array[i] = array[store_index];
			array[store_index] = temp;
			store_index++;
		}
	}
	int temp = array[pivot];
	array[pivot] = array[store_index - 1];
	array[store_index - 1] = temp;
	if (store_index > pivot + 1) {
		_quick_sort(array, pivot, store_index - 1);
	}

	if (store_index < end - 1) {
		_quick_sort(array, store_index, end);
	}
}

void quick_sort(int* array, int size) {
	if (size <= 1) return;
	_quick_sort(array, 0, size);
}

void radix_sort(int* array, int size) {
	int max_digits = 0;
	for (int i = 0; i < size; i++) {
		int digits = count_int_digits(array[i]);
		if (digits > max_digits) {
			max_digits = digits;
		}
	}

	for (int i = 0; i < max_digits; i++) {
		bool is_sorted = false;
		while (!is_sorted) {
			is_sorted = true;

			for (int j = 0; j < size - 1; j++) {
				if (get_int_nth_digit2(array[j + 1], i) < get_int_nth_digit2(array[j], i)) {
					int temp =  array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					is_sorted = false;
				}
			}
		}
	}
}
