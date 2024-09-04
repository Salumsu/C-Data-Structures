#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stddef.h>

typedef struct HashNode {
	int val;
	struct HashNode* next;
	char* key;
} HashNode;


typedef struct HashTable {
	size_t size;
	HashNode** entries;
} HashTable;

HashTable* create_table(size_t TABLE_SIZE);
unsigned long hash(char* key, size_t TABLE_SIZE);
void addEntry(HashTable* hash_table, char* key, int val);
void removeEntry(HashTable* hash_table, char* key);
void display(HashTable* hash_table);

#endif