#include <stdio.h>

#define MOD 999017

int N, Res;

int getFib(int x)
{
	if (x <= 2)
		return 1;
	int f1 = 1, f2 = 1, f3;
	for (int i = 3; i <= x; ++i)
	{
		f3 = f1 + f2;
		if (f3 >= MOD) f3 -= MOD;
		f1 = f2; f2 = f3;
	}
	return f2;
}

int main()
{
	scanf("%d", &N);
	Res = 1;
	for (int i = 2; i <= N; ++i)
		Res = (Res * i) % MOD;
	Res -= getFib(2*N-1);
	if (Res < 0) Res += MOD;

	printf("%d\n", Res);

	return 0;
}


