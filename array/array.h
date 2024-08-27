#ifndef ARRAY_H
#define ARRAY_H

// SORTING ALGORITHMS

void print_array(int* array, int size);
void bubble_sort(int* array, int size);
void selection_sort(int* array, int size);
void insertion_sort(int* array, int size);
void merge_sort(int* array, int size);
void quick_sort(int* array, int size);
void radix_sort(int* array, int size);


// SEARCH ALGORITHMS

int linear_search(int* array, int size, int val);
// SORTED ARRAY ONLY 
int binary_search(int* array, int size, int val);

#endif