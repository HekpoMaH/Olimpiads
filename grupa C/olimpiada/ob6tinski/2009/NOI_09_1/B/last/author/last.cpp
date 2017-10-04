#include<cstdio>
int n;
int s;
int main()
{
	scanf("%d%d", &n, &s);
	int p = 0;
	int mp = 0;
	for (int m = 1;m <= n - 1;m++)
	{
		int i = 1;
		int c = 0;
		int pp=p;
		int pmp=mp;
		do
		{
			if (i == s)if (p < c)
				{
					p = c;
					mp = m;
				}
			i = i + m;
			if (i > n) i = i - n;
			c++;
		}
		while (i != 1);
		if(c<n) {p=pp; mp=pmp;}
	}
	printf("%d\n", mp);
}

