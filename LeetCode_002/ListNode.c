#include<stdlib.h>
#include"ListNode.h"

void initList(ListNode **list, int* seq, int seqLen) {
	int i;
	if (seqLen <= 0) {
		(*list) = NULL;
		return;
	}
	(*list) = (ListNode*)malloc(sizeof(ListNode));
	(*list)->val = seq[0];
	initList(&((*list)->next), seq + 1, seqLen - 1);
	return;
}

void freeList(ListNode **list){
	if ((*list) == NULL) return;
	freeList(&((*list)->next));
	free((*list));
	(*list) = NULL;
	return;
}