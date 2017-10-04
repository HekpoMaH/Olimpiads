/*
TASK: frogs
LANG: C++
ML: 16MB
*/

#include <cstdio>
using namespace std;

const int MAX_N = 1<<20;

int n;
int H[MAX_N];		// height
int J[MAX_N];		// number of jumps  &  index in H[] of the answer

int st[MAX_N];		// stack

void input ()
{
	int i;

	scanf ("%d", &n);
	for (i=0; i<n; i++)
		scanf ("%d", &H[i]);
	for (i=0; i<n; i++)
		scanf ("%d", &J[i]);
}

void solve ()
{
	int i, l=0;

	for (i=n-1; i>=0; i--) {
		while (l && H[st[l-1]] <= H[i]) l--;
		J[i] = J[i]<=l ? st[l-J[i]] : -1;
		st[l++] = i;
	}
}

void output ()
{
	int i;

	for (i=0; i<n; i++) {
		if (i) printf (" ");
		printf ("%d", J[i]!=-1 ? H[J[i]] : -1);
	}

	printf ("\n");
}

int main ()
{
	input ();
	solve ();
	output ();

	return 0;
}
