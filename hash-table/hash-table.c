#include "hash-table.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

HashTable* create_table(size_t TABLE_SIZE) {
	HashTable* hash_table = (HashTable*)malloc(sizeof(HashTable));
	if (hash_table == NULL) return NULL;

	HashNode** entries = (HashNode**)calloc(TABLE_SIZE, sizeof(HashNode*));
	if (entries == NULL) {
		free(hash_table);
		return NULL;
	}

	hash_table->entries = entries;
	hash_table->size = TABLE_SIZE;

	return hash_table;
}

unsigned long hash(char *key, size_t TABLE_SIZE) {
    unsigned long hash = 5381;
    int c;

    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % TABLE_SIZE;
}


void addEntry(HashTable* hash_table, char* key, int val) {
	unsigned long hash_key = hash(key, hash_table->size);
	HashNode* entry = hash_table->entries[hash_key];

	HashNode* prev = NULL;
	while (entry) {
		if (strcmp(entry->key, key) == 0) {
			entry->val = val;
			return;
		}
		prev = entry;
		entry = entry->next;
	}

	HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
	if (new_node == NULL) {
		return;
	}

	new_node->key = strdup(key);
	new_node->val = val;
	new_node->next = NULL;

	if (prev == NULL) {
		hash_table->entries[hash_key] = new_node;
	} else {
		prev->next = new_node;
	}
}

void removeEntry(HashTable* hash_table, char* key) {
	unsigned long hash_key = hash(key, hash_table->size);
	HashNode* entry = hash_table->entries[hash_key];

	if (entry != NULL) {
		HashNode* prev = NULL;
		while (entry != NULL && strcmp(entry->key, key) != 0) {
			prev = entry;
			entry = entry->next;
		}
		if (entry != NULL) {
			if (prev != NULL) {
				prev->next = entry->next;
			} else {
				hash_table->entries[hash_key] = entry->next;
			}

			free(entry->key);
			free(entry);
		}
	}	
}

void display(HashTable* hash_table) {
	for (size_t i = 0; i < hash_table->size; i++) {
		HashNode* node = hash_table->entries[i];
		if (node != NULL) {
			while (node != NULL) {
				printf("%zu > %s : %d\n", i, node->key, node->val);
				node = node->next;
			}
		}
	}
}

