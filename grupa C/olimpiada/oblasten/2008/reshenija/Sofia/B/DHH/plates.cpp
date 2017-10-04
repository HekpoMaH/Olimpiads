#include <cstdio>

using namespace std;

int m,n,e=0;
char p[1024][32][32],s[32][32];

bool chec (int);

int main ()
{
	scanf ("%d %d",&m,&n);
	int i,j,k,l;
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			scanf ("%s",s[j]);
		}
		if (e==0)
		{
			for (k=0;k<n;k++)
			{
				for (l=0;l<n;l++)
				{
					p[e][k][l]=s[k][l];
				}
			}
			e++;
		}
		else
		{
			for (j=0;j<e;j++)
			{
				if (chec (j))
				{
					goto e;
				}
			}
			for (k=0;k<n;k++)
			{
				for (l=0;l<n;l++)
				{
					p[e][k][l]=s[k][l];
				}
			}
			e++;
e:			e=e;
		}
	}
	printf ("%d\n",e);
	return 0;
}

bool chec (int h)
{
	int i,j,k,l;
	for (i=0,k=0;i<n,k<n;i++,k++)
	{
		for (j=0,l=0;j<n,l<n;j++,l++)
		{
			if (p[h][i][j]!=s[k][l])
			{
				goto x1;
			}
		}
	}
	return true;
x1:	for (i=0,k=0;i<n,k<n;i++,k++)
	{
		for (j=0,l=0;j<n,l<n;j++,l++)
		{
			if (p[h][i][j]!=s[l][k])
			{
				goto x2;
			}
		}
	}
	return true;
x2:	for (i=0,k=n-1;i<n,k>=0;i++,k--)
	{
		for (j=0,l=0;j<n,l<n;j++,l++)
		{
			if (p[h][i][j]!=s[k][l])
			{
				goto x3;
			}
		}
	}
	return true;
x3:	for (i=0,k=n-1;i<n,k>=0;i++,k--)
	{
		for (j=0,l=0;j<n,l<n;j++,l++)
		{
			if (p[h][i][j]!=s[l][k])
			{
				goto x4;
			}
		}
	}
	return true;
x4:	for (i=0,k=0;i<n,k<n;i++,k++)
	{
		for (j=0,l=n-1;j<n,l>=0;j++,l--)
		{
			if (p[h][i][j]!=s[k][l])
			{
				goto x5;
			}
		}
	}
	return true;
x5:	for (i=0,k=0;i<n,k<n;i++,k++)
	{
		for (j=0,l=n-1;j<n,l>=0;j++,l--)
		{
			if (p[h][i][j]!=s[l][k])
			{
				goto x6;
			}
		}
	}
	return true;
x6:	for (i=0,k=n-1;i<n,k>=0;i++,k--)
	{
		for (j=0,l=n-1;j<n,l>=0;j++,l--)
		{
			if (p[h][i][j]!=s[k][l])
			{
				goto x7;
			}
		}
	}
	return true;
x7:	for (i=0,k=n-1;i<n,k>=0;i++,k--)
	{
		for (j=0,l=n-1;j<n,l>=0;j++,l--)
		{
			if (p[h][i][j]!=s[l][k])
			{
				goto x8;
			}
		}
	}
	return true;
x8:	return false;
}
