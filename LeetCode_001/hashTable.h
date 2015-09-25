#pragma once
#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

typedef struct hashTableNode {
	int val;
	int idx;
	struct hashTableNode* next;
} hashTableNode;

void initHashTable(hashTableNode*** hash, int hashTableSize);

void insertHashTable(hashTableNode** hash, int hashTableSize, int val, int idx);

void freeHashTableNode(hashTableNode** node);

void freeHashTable(hashTableNode** hash, int hashTableSize);

int getHashTable(hashTableNode** hash, int hashTableSize, int val);

void removeHashTable(hashTableNode** hash, int hashTableSize, int val);

#endif
