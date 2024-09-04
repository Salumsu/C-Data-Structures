#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "generic-hash-table.h"

void displayValue(void* val, enum ValueType value_type) {
	switch (value_type) {
		case STRING:
			printf("%s\n", (char*)val);
			break;
		case INT:
			printf("%d\n", *(int*)val);
			break;
		case CHAR:
			printf("%c\n", *(char*)val);
			break;
		default:
			printf("\n");
	}
}

GenericHashTable* create_generic_table(size_t TABLE_SIZE) {
	GenericHashTable* hash_table = (GenericHashTable*)malloc(sizeof(GenericHashTable));
	if (hash_table == NULL) {
		printf("Failed to create table\n");
		return NULL;
	}

	GenericHashNode** entries = (GenericHashNode**)calloc(TABLE_SIZE, sizeof(GenericHashNode*));
	if (entries == NULL) {
		printf("Failed to create table\n");
		free(hash_table);
		return NULL;
	}


	hash_table->entries = entries;
	hash_table->size = TABLE_SIZE;

	return hash_table;
}


unsigned long hash(char* key, size_t TABLE_SIZE) {
	unsigned long hash = 5381;
    int c;

    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % TABLE_SIZE;
}


void addEntry(GenericHashTable* hash_table, char* key, void* val, enum ValueType value_type, size_t val_size) {
	unsigned long hash_key = hash(key, hash_table->size);
	GenericHashNode* entry = hash_table->entries[hash_key];
	GenericHashNode* prev = NULL;
	 
	while (entry) {
		if (strcmp(entry->key, key) == 0) {
			entry->key = key;
			entry->value_type = value_type;
			free(entry->val); 
			entry->val = malloc(val_size);
			if (entry->val == NULL) {
				printf("Failed to add");
				displayValue(val, value_type);
				return;
			}
			memcpy(entry->val, val, val_size);

			return;
		}
		prev = entry;
		entry = entry->next;
	}

	GenericHashNode* new_node = (GenericHashNode*)malloc(sizeof(GenericHashNode));
	if (new_node == NULL) {
		printf("Failed to add");
		displayValue(val, value_type);
		return;
	}

	new_node->value_type = value_type;
	new_node->key = strdup(key);
	new_node->next = NULL;
	new_node->val = malloc(val_size);
	if (new_node->val == NULL) {
		printf("Failed to add");
		displayValue(val, value_type);
		return;
	}
	memcpy(new_node->val, val, val_size);

	if (prev == NULL) {
		hash_table->entries[hash_key] = new_node;
	} else {
		prev->next = new_node;
	}
}


void removeEntry(GenericHashTable* hash_table, char* key) {
	unsigned long hash_key = hash(key, hash_table->size);
	GenericHashNode* entry = hash_table->entries[hash_key];

	if (entry != NULL) {
		GenericHashNode* prev = NULL;
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
			free(entry->val);
			free(entry);
		}
	}	
}


void display(GenericHashTable* hash_table) {
	for (size_t i = 0; i < hash_table->size; i++) {
		GenericHashNode* node = hash_table->entries[i];
		if (node != NULL) {
			while (node != NULL) {
				printf("%zu > %s : ", i, node->key);
				displayValue(node->val, node->value_type);
				node = node->next;
			}
		}
	}
}
