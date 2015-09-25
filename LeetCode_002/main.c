/**
* You are given two linked lists representing two non-negative numbers. The digits
* are stored in reverse order and each of their nodes contain a single digit. Add
* the two numbers and return it as a linked list.
*
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

#include<stdio.h>
#include<stdlib.h>
#include"ListNode.h"

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	ListNode *l1cur, *l2cur, *ans, **anscur;
	int a, b, sum, carry;
	l1cur = l1;
	l2cur = l2;
	ans = NULL;
	anscur = &ans;
	carry = 0;
	while (l1cur != NULL || l2cur != NULL || carry != 0) {
		if (l1cur != NULL) {
			a = l1cur->val;
			l1cur = l1cur->next;
		}
		else {
			a = 0;
		}
		if (l2cur != NULL) {
			b = l2cur->val;
			l2cur = l2cur->next;
		}
		else {
			b = 0;
		}
		sum = a + b + carry;
		carry = sum >= 10;
		sum = carry ? sum - 10 : sum;
		(*anscur) = (ListNode*)malloc(sizeof(ListNode));
		(*anscur)->val = sum;
		(*anscur)->next = NULL;
		anscur = &((*anscur)->next);
	}
	return ans;
}

int main() {
	int a[] = { 2, 4, 5, 3 };
	int b[] = { 5, 6, 4 };
	ListNode *l1, *l2, *ans, *cur;
	initList(&l1, a, sizeof(a) / sizeof(int));
	initList(&l2, b, sizeof(b) / sizeof(int));
	ans = addTwoNumbers(l1, l2);
	for (cur = ans; cur->next != NULL; cur = cur->next) {
		printf("%d -> ", cur->val);
	}
	printf("%d\n", cur->val);
	freeList(&ans);
	freeList(&l1);
	freeList(&l2);
	return 0;
}
