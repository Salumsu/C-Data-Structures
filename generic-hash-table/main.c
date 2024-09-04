#include <stdio.h>
#include "generic-hash-table.h"

int main() {
	GenericHashTable* hash_table = create_generic_table(5);
	addEntry(hash_table, "test", "Hello", STRING, sizeof(char) * 6);
	int testint = 1;
	addEntry(hash_table, "testint", &testint, INT, sizeof(int));
	char testchar = 'a';
	addEntry(hash_table, "testchar", &testchar, CHAR, sizeof(char));
	removeEntry(hash_table, "testcharqwe");

	display(hash_table);

	return 0;
}