#include "hash-table.h"
#include <stdio.h>

int main() {
	size_t TABLE_SIZE = 3;
	HashTable* hash_table = create_table(TABLE_SIZE);

	addEntry(hash_table, "test", 1);
	addEntry(hash_table, "test1", 2);
	addEntry(hash_table, "test2", 3);
	removeEntry(hash_table, "test2");
	display(hash_table);

	return 0;
}	