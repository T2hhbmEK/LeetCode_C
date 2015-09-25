#ifndef _HASH_TABLE_C_
#define _HASH_TABLE_C_

#include<stdlib.h>
#include"hashTable.h"

void initHashTable(hashTableNode*** hash, int hashTableSize) {
	int i;
	(*hash) = (hashTableNode**)malloc(hashTableSize*sizeof(hashTableNode*));
	for (i = 0; i < hashTableSize; i++) {
		(*hash)[i] = NULL;
	}
}

void insertHashTable(hashTableNode** hash, int hashTableSize, int val, int idx) {
	hashTableNode* tmp = (hashTableNode*)malloc(sizeof(hashTableNode));
	hashTableNode* node;
	int hashTableIdx = val % hashTableSize;
	hashTableIdx = hashTableIdx >= 0 ? hashTableIdx : hashTableIdx + hashTableSize;
	tmp->val = val;
	tmp->idx = idx;
	tmp->next = NULL;
	if (hash[hashTableIdx] == NULL) {
		hash[hashTableIdx] = tmp;
		return;
	}
	for (node = hash[hashTableIdx]; node->next != NULL; node = node->next);
	node->next = tmp;
}

int getHashTable(hashTableNode** hash, int hashTableSize, int val) {
	int hashTableIdx = val % hashTableSize;
	hashTableNode* node;
	hashTableIdx = hashTableIdx >= 0 ? hashTableIdx : hashTableIdx + hashTableSize;
	for (node = hash[hashTableIdx]; node != NULL; node = node->next) {
		if (node->val == val) {
			return node->idx;
		}
	}
	return -1;
}

void removeHashTable(hashTableNode** hash, int hashTableSize, int val) {
	int hashTableIdx = val % hashTableSize;
	hashTableNode* node,* tmp;
	hashTableIdx = hashTableIdx >= 0 ? hashTableIdx : hashTableIdx + hashTableSize;
	if (hash[hashTableIdx]->val == val) {
		node = hash[hashTableIdx]->next;
		free(hash[hashTableIdx]);
		hash[hashTableIdx] = node;
		return;
	}
	for (node = hash[hashTableIdx]; node->next != NULL; node = node->next) {
		if (node->next->val == val) {
			tmp = node->next->next;
			free(node->next);
			node->next = tmp;
			return;
		}
	}
}

void freeHashTableNode(hashTableNode** node) {
	if ((*node)->next != NULL) {
		freeHashTableNode(&((*node)->next));
	}
	free(*node);
	*node = NULL;
}

void freeHashTable(hashTableNode** hash, int hashTableSize) {
	int i;
	for (i = 0; i < hashTableSize; i++) {
		if (hash[i] != NULL) {
			freeHashTableNode(hash + i);
		}
	}
}

#endif
