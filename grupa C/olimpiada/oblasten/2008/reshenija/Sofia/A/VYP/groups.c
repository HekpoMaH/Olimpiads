#include <stdio.h>

#define MAX_N 500
#define MAX_P 500

typedef float DOUBLE;

void input(void);
void solve(void);
DOUBLE calc(int tmp[MAX_N]);

int n;
int p;
DOUBLE a[MAX_N];

int main(void)
{
	input();
	solve();
	
	return 0;
}

void input(void)
{
	int i;
	
	scanf("%d", &n);
	scanf("%d", &p);
	for (i = 0; i < n; i++)
		scanf("%f", &a[i]);
}

void solve(void)
{
	int i;
	int j;
	int st;
	DOUBLE min_ar = 100000.0;
	DOUBLE cur_ar;
	
	int tmp[MAX_N];
	for (i = 0; i < p - 1; i++)
		tmp[i] = 1;
	tmp[p - 1] = n - p + 1;
	
	for (i = p - 1; i >= 1; )
	{
		//for (j = 0; j < p; j++)
	//		printf("%d ", tmp[j]);
	//	printf("\n");
		cur_ar = calc(tmp);
		if (cur_ar < min_ar)
			min_ar = cur_ar;
		//printf("\n\n");
		if (tmp[i] - 1 < 1)
			i--;
		tmp[i]--;
		tmp[i - 1]++;
	}
	/*
	for (j = 0; j < p; j++)
		printf("%d ", tmp[j]);
	printf("\n");
	cur_ar = calc(tmp);
		if (cur_ar < min_ar)
			min_ar = cur_ar;
	*/
	
	printf("%.4f\n", min_ar);
}

DOUBLE calc(int tmp[MAX_N])
{
	int i;
	int j;
	int k;
	int s; int e;
	DOUBLE ar;
	DOUBLE sum_ar;
	DOUBLE sum_d;
	
	for (i = 0, s = 0, e = 0, sum_ar = 0.0; i < p; i++)
	{
		s = e;
		e = s + tmp[i];
		for (j = s, ar = 0.0; j < e; j++)
			ar += a[j];
		ar /= tmp[i];
		for (j = s; j < e; j++)
		{
			sum_ar += (a[j] - ar) * (a[j] - ar);
		}
//		printf("%.4f %.4f\n", ar, sum_ar);
	}
	
	return sum_ar;
}
