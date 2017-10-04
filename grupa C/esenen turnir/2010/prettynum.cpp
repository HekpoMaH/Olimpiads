#include <stdio.h>

#define MAXN 1000000

int n, a[MAXN];
int reps[MAXN], next[MAXN];

int answ_start, answ_end, answ_rep;
int curr_start, curr_end, curr_rep;

struct TLargeNumber {
	int n, rep;
	int dig[MAXN];
};

void readInput() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
}

int getSequenceCount(int ind) {
	int count = 1, i;
	i = ind;

	while ((i+1 < n) && (a[i+1] == a[i])) {
		count++;
		i++;
	}

	return count;
}

void updateAnswer() {
	int i, j, answ_past, curr_past;
	int updateFlag = 1;

	if (curr_end - curr_start < answ_end - answ_start)
		return;

	if (curr_end - curr_start > answ_end - answ_start) {
		answ_start = curr_start;
		answ_end = curr_end;
		answ_rep = curr_rep;
	} else {
		answ_past = 0;
		curr_past = 0;
		i = answ_start;
		j = curr_start;
		while ((i <= answ_end) && (j <= curr_end)) {
			if (a[j] > a[i]) {
				break;
			} else if (a[i] > a[j]) {
				updateFlag = 0;
				break;
			}

			if (answ_past + next[i] - i < curr_past + next[j] - j) {
				answ_past += answ_past + next[i] - i;
				i = next[i];
			} else if (answ_past + next[i] - i > curr_past + next[j] - j) {
				curr_past += curr_past + next[j] - j;
				j = next[j];
			} else {
				answ_past += answ_past + next[i] - i;
				i = next[i];

				curr_past += curr_past + next[j] - j;
				j = next[j];
			}
		}

		if (updateFlag) {
			answ_start = curr_start;
			answ_end = curr_end;
			answ_rep = curr_rep;
		}
	}
}

void solve() {
	int i = 0, nextSeq;
	int rep;

	while (i < n) {
		reps[i] = getSequenceCount(i);
		nextSeq = i + reps[i];
		next[i] = nextSeq;

		while ((i+1 < n) && (a[i+1] == a[i])) {
			i++;
			reps[i] = reps[i-1];
			next[i] = nextSeq;
		}
		i++;
	}

	answ_start = 0;
	answ_end = -1;
	curr_rep = 0;

	i = 0;
	while (i < n) {
		rep = reps[i];

		if (curr_rep == 0) {
			if (a[i] != 0) {
				curr_start = i;
				curr_end = next[i] - 1;
				curr_rep = rep;
			}
		} else {
			if (rep == curr_rep) {
				curr_end = next[i] - 1;
			} else if (rep > curr_rep) {
				curr_end = i + curr_rep - 1;
				updateAnswer();
				if (a[i] == 0) {
					curr_rep = 0;
				} else {
					curr_start = i;
					curr_end = next[i] - 1;
					curr_rep = rep;
				}
			} else {
				updateAnswer();
				curr_start = i - rep;
				curr_end = next[i] - 1;
				curr_rep = rep;
			}
		}

		i = next[i];
	}

	if (curr_rep > 0)
		updateAnswer();

	if (answ_end == -1) {
		printf("0\n");
		return;
	}

	for (i = answ_start; i <= answ_end; i++)
		printf("%d", a[i]);
	printf("\n");
}

int main () {

	readInput();
	solve();

	return 0;
}

