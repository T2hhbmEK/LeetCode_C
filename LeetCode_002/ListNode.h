#pragma once

struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode ListNode;

void initList(ListNode **list, int* seq, int seqLen);

void freeList(ListNode **list);