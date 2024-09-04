#ifndef GENERIC_HASH_TABLE_H
#define GENERIC_HASH_TABLE_H

#include <stddef.h>

enum ValueType {
	STRING,
	INT,
	CHAR,
};

typedef struct GenericHashNode {
	void* val;
	enum ValueType value_type;
	struct GenericHashNode* next;
	char* key;
} GenericHashNode;


typedef struct GenericHashTable {
	size_t size;
	GenericHashNode** entries;
} GenericHashTable;

void displayValue(void* val, enum ValueType value_type);
GenericHashTable* create_generic_table(size_t TABLE_SIZE);
unsigned long hash(char* key, size_t TABLE_SIZE);
void addEntry(GenericHashTable* hash_table, char* key, void* val, enum ValueType value_type, size_t val_size);
void removeEntry(GenericHashTable* hash_table, char* key);
void display(GenericHashTable* hash_table);

#endif