/**
* Given a string, find the length of the longest substring without repeating
* characters. For example, the longest substring without repeating letters for
* "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring
* is "b", with the length of 1.
*/

#include<stdio.h>
#include<string.h>

int lengthOfLongestSubstring(char* s) {
	int r, c, i, j;
	int hash[256] = { 0 };
	unsigned char * us = s;
	if (us[0] == '\0') {
		return 0;
	}
	r = 0;
	i = 0;
	j = 0;
	c = 0;
	while (us[j] != '\0') {
		while (us[j] != '\0' && hash[us[j]] == 0x0) {
			hash[us[j]] = 0x1;
			c++;
			j++;
		}
		r = c > r ? c : r;
		c--;
		hash[us[i]] = 0x0;
		i++;
	}
	return r;
}

int main() {
	char s[] = "cdd";
	int r;
	r = lengthOfLongestSubstring(s);
	printf("%d\n", r);
	return;
}
