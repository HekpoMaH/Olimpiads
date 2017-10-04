#include <stdio.h>
#include <string.h>

#define MOD 999017

int N, perm[4096], uz[4096], cycle[4096], cnt;

inline int sort1(const int *perm, int N)
{
	int time = 0;
	for (int i = 0; i < N; ++i)
		for (int j = i+1; j < N; ++j)
			time += perm[i] > perm[j];
	return time;
}

inline int sort2(const int *perm, int N)
{
	int nrc = 0;

	memset(cycle, 0, sizeof(cycle));
	for (int i = 0; i < N; ++i)
		if (!cycle[i])
		{
			++nrc;
			int j = i;
			while (!cycle[j])
			{
				cycle[j] = 1;
				j = perm[j]-1;
			}
		}
	return N-nrc;
}

void back(int level)
{
	if (level == N)
	{
		cnt += sort2(perm, N) < sort1(perm, N);
		if (cnt >= MOD)
			cnt -= MOD;
		return ;
	}

	for (int i = 1; i <= N; ++i)
		if (!uz[i])
		{
			uz[i] = 1;
			perm[level] = i;
			back(level+1);
			uz[i] = 0;
		}
}

int main()
{
	scanf("%d", &N);
	back(0);

	printf("%d\n", cnt);

	return 0;
}


