/**
* There are two sorted arrays nums1 and nums2 of size m and n respectively.
* Find the median of the two sorted arrays. The overall run time complexity
* should be O(log (m+n)).
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	double t1 = (nums1Size - 1.0) / 2.0, t2 = (nums2Size - 1.0) / 2.0;
	int td = (int)floor(t1 > t2 ? t2:t1) + 1;
	double a11 = 0, a12 = 0, a21 = 0, a22 = 0, a1 = 0, a2 = 0;

	if (0 > t1 && 0 <= t2) {
		return (nums2[(int)floor(t2)] + nums2[(int)ceil(t2)]) / 2.0;
	}
	else if (0 <= t1 && 0 > t2) {
		return (nums1[(int)floor(t1)] + nums1[(int)ceil(t1)]) / 2.0;
	}
	else if (0 > t1 && 0 > t2) {
		return 0;
	}
	else if (0 <= t1 && 0 <= t2) {
		a11 = nums1[(int)floor(t1)];
		a12 = nums1[(int)ceil(t1)];
		a21 = nums2[(int)floor(t2)];
		a22 = nums2[(int)ceil(t2)];
		a1 = a11 > a21 ? a11:a21;
		a2 = a12 < a22 ? a12:a22;
		if (a1 <= a2) {
			return (a1 + a2) / 2.0;
		}
		else if (a11 > a22) {
			return findMedianSortedArrays(nums1, nums1Size - td, nums2 + td, nums2Size - td);
		}
		else if (a12 < a21) {
			return findMedianSortedArrays(nums1 + td, nums1Size - td, nums2, nums2Size - td);
		}
	}
}

int main() {
	int nums1[] = { 1, 3 };
	int nums2[] = { 2, 4 };
	double r = findMedianSortedArrays(nums1, sizeof(nums1) / sizeof(int), nums2, sizeof(nums2) / sizeof(int));
	//double r = findMedianSortedArrays(nums1, 0, nums2, sizeof(nums2) / sizeof(int));
	printf("%.1lf\n", r);
	return 0;
}
