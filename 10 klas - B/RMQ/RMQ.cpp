// RMQ build O(n log n), query O(1)
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int Log2(int val)
{
	int ret = 0;
	while (val >>= 1) ++ret;
    return ret;
}

vector <int> A;
vector < vector<int> > MIN;
vector < vector<int> > MAX;

int N, Q;
int minA(int i, int j)
{
	return A[i] < A[j] ? i : j;
}

int maxA(int i, int j)
{
	return A[i] > A[j] ? i : j;
}

void precompute()
{
	int i, j, ln = Log2(N);
	MIN.clear(); MIN.resize(ln + 1, vector<int>(N));
	MAX.clear(); MAX.resize(ln + 1, vector<int>(N));

	for(int i = 0; i < N; i++) 
		MIN[0][i] = MAX[0][i] = i;

	for(i = 1; 1 << i <= N; i++) 
	{
		for(j = 0; j + (1 << i) - 1 < N; j++)
		{
			int k = j + (1 << (i - 1));
			MIN[i][j] = minA(MIN[i - 1][j], MIN[i - 1][k]);
			MAX[i][j] = maxA(MAX[i - 1][j], MAX[i - 1][k]);
		}
	}
}

int rmqMin(int beg, int end)
{
	beg--,end--;
	int ln = Log2(end - beg + 1);
	int k = end - (1 << ln) + 1;
	return min(A[MIN[ln][beg]], A[MIN[ln][k]]);
}

int rmqMax(int beg, int end)
{
	beg--,end--;
	int ln = Log2(end - beg+1);
	int k = end - (1 << ln) + 1;
	return max(A[MAX[ln][beg]], A[MAX[ln][k]]);
}

int main()
{
	//genTest();

	while(true)
	{
		scanf("%d", &N);
		if(N == -1)
			break;
		
		scanf("%d", &Q);
		
		A.clear();
		A.resize(N);
		for(int i = 0;i < N;i++)
			scanf("%d", &A[i]);

		precompute();

		int beg, end;
		for(int i = 0;i < Q;i++)
		{
			scanf("%d%d", &beg, &end);
			printf("%d %d\n", rmqMin(beg, end), rmqMax(beg, end));
		}
	}

	return 0;
}

//int rmqMinSlow(int i, int j)
//{
//	int m = INT_MAX;
//	i--, j--;
//	for(; i <= j && i < N;i++)
//		if(m > A[i])
//			m = A[i];
//
//	return m;
//}
//
//int rmqMaxSlow(int i, int j)
//{
//	int m = INT_MIN;
//	i--, j--;
//	for(; i <= j && i < N;i++)
//		if(m < A[i])
//			m = A[i];
//
//	return m;
//}

//void genTest()
//{
//	FILE *f = fopen("mm.in", "w");
//
//	int n = 50000, q = 200000;
//	fprintf(f, "%d %d\n", n, q);
//	vector<int> t(n);
//	for(int i = 0;i < n;i++)
//		t[i]=i+1;
//
//	random_shuffle(t.begin(), t.end());
//
//	for(int i = 0;i < n - 1;i++)
//		fprintf(f, "%d ", t[i]);
//	fprintf(f, "%d\n", t[n-1]);
//	
//	int k = 1;
//	for(int i = 0;i < q;i++)
//	{
//		if(k % 500) k *= 10;
//		int beg=-1, end=-1;
//		while(true)
//		{
//			beg = rand() % (10 + k);
//			if(beg >= 1 && beg <= n)
//				break;
//		}
//
//		while(true)
//		{
//			end = rand() % n;
//			if(end >= 1 && end <= n && beg <= end)
//				break;
//		}
//
//		fprintf(f, "%d %d\n", beg, end);
//	}
//
//	fprintf(f, "%d\n", -1);
//	fclose(f);
//}
