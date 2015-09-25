#ifndef _QSORTINT_C_
#define _QSORTINT_C_

void qsortInt(int* seq, int seqSize) {
	int i, j, key;
	if (seqSize <= 1) {
		return;
	}
	i = 0;
	j = seqSize - 1;
	key = seq[0];
	while (i < j) {
		while (i < j && seq[j] >= key) {
			j--;
		}
		seq[i] = seq[j];
		while (i < j && seq[i] <= key) {
			i++;
		}
		seq[j] = seq[i];
	}
	seq[i] = key;
	qsortInt(seq, i);
	qsortInt(seq + i + 1, seqSize - i - 1);
	return;
}

#endif
