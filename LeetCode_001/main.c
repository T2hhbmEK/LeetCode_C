/**
* Given an array of integers, find two numbers such that they add up to a specific
* target number.
* 
* The function twoSum should return indices of the two numbers such that they add
* up to the target, where index1 must be less than index2. Please note that your
* returned answers (both index1 and index2) are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
*/



/**
* Note: The returned array must be malloced, assume caller calls free().
*/

#include<stdio.h>
#include<stdlib.h>
#include"qsortInt.h"
#include"hashTable.h"

int* twoSum_hash(int* nums, int numsSize, int target) {
	int i, idx, tmp;
	hashTableNode** hash;
	int* ans = (int*)malloc(2 * sizeof(int));
	initHashTable(&hash, numsSize);
	ans[0] = ans[1] = 0;
	for (i = 0; i < numsSize; i++) {
		insertHashTable(hash, numsSize, nums[i], i);
	}
	for (i = 0; i < numsSize; i++) {
		idx = getHashTable(hash, numsSize, target-nums[i]);
		if (idx >= 0 && idx != i) {
			ans[0] = i+1;
			ans[1] = idx+1;
			if (ans[0] > ans[1]) {
				tmp = ans[0];
				ans[0] = ans[1];
				ans[1] = tmp;
			}
		}
	}
	freeHashTable(hash, numsSize);
	return ans;
}

int* twoSum_sort(int* nums, int numsSize, int target) {
	int i, j, tmp;
	int* numsSort = (int*)malloc(numsSize*sizeof(int));
	int* ans = (int*)malloc(2 * sizeof(int));
	for (i = 0; i < numsSize; i++) {
		numsSort[i] = nums[i];
	}
	qsortInt(numsSort, numsSize);
	ans[0] = ans[1] = 0;
	i = 0, j = numsSize - 1;
	while (i < j) {
		while (numsSort[i] + numsSort[j] < target) {
			i++;
		}
		if (numsSort[i] + numsSort[j] == target) {
			ans[0] = numsSort[i];
			ans[1] = numsSort[j];
			break;
		}
		while (numsSort[i] + numsSort[j] > target) {
			j--;
		}
		if (numsSort[i] + numsSort[j] == target) {
			ans[0] = numsSort[i];
			ans[1] = numsSort[j];
			break;
		}
	}
	for (i = 0; i < numsSize; i++) {
		if(nums[i] == ans[0]) {
			ans[0] = i+1;
			break;
		}
	}
	for (i = 0; i < numsSize; i++) {
		if(nums[i] == ans[1] && i+1 != ans[0]) {
			ans[1] = i+1;
			break;
		}
	}
	if (ans[0] > ans[1]) {
		tmp = ans[0];
		ans[0] = ans[1];
		ans[1] = tmp;
	}
	//for (i = 0; i < numsSize - 1; i++) {
	//	printf("%d,", nums[i]);
	//}
	//printf("%d\n", nums[numsSize - 1]);
	//for (i = 0; i < numsSize-1; i++) {
	//	printf("%d,",numsSort[i]);
	//}
	//printf("%d\n", numsSort[numsSize - 1]);
	free(numsSort);
	return ans;
}

int main() {
	int nums[] = { -1,-2,-3,-4,-5 };
	int numsSize = sizeof(nums) / sizeof(int);
	int target = -8;
	int* ans = twoSum_hash(nums, numsSize, target);
	printf("%d,%d\n", ans[0], ans[1]);
	free(ans);
	return 0;
}
