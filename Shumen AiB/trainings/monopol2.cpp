#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define inpfile "f.in"
#define outfile "f.out"

#define NMAX 2005
#define MMAX 400005

struct NODE {
	int x,next;
};

//Global variables
int a[NMAX];
NODE p[MMAX];
int b[NMAX];
int n,m;
int pn;

int comp[NMAX];
int col[NMAX];
int num[NMAX][2];
int u[NMAX][2];
int collision[NMAX];
int ncomp;

int used[NMAX][NMAX];

int res,r1,r2;
//----------------

void Init()
{
	freopen(inpfile,"r",stdin);
	freopen(outfile,"w",stdout);
	memset(a,0,sizeof(a[0])*NMAX);
	memset(comp,0,sizeof(comp[0])*NMAX);
	memset(col,0,sizeof(col[0])*NMAX);
	memset(num,0,sizeof(num[0][0])*NMAX*2);
	memset(u,0,sizeof(u[0])*NMAX);
	memset(collision,0,sizeof(collision[0])*NMAX);
	memset(used,0,sizeof(used[0][0])*NMAX*NMAX);
}

void Out()
{
	printf("%d\n",res);
	exit(0);
}

void Inp()
{
	int i,x,y;

	scanf("%d",&n);
	assert((n>=1)&&(n<=2000));
	for (i=1; i<=n; i++) {
		assert(scanf("%d",b+i)==1);
		assert((b[i]==0)||(b[i]==1));
	}
	scanf("%d",&m);
	assert((m>=0)&&(m<=200000));

	pn=0;
	for (i=1; i<=m; i++) {
		assert(scanf("%d %d",&x,&y)==2);
		assert((x>=1)&&(x<=n));
		assert((y>=1)&&(y<=n));
		assert(x!=y);
		assert((!used[x][y]) && (!used[y][x]));
		used[x][y]=1;
		used[y][x]=1;

		pn++;
		p[pn].x=y;
		p[pn].next=a[x];
		a[x]=pn;

		pn++;
		p[pn].x=x;
		p[pn].next=a[y];
		a[y]=pn;
	}
	assert(scanf("%d",&x)==EOF);
}

void Dfs(int x, int k)
{
	int i;

	comp[x]=ncomp;
	col[x]=k;
	num[ncomp][k]++;

	for (i=a[x]; i; i=p[i].next) {
		if (!comp[p[i].x]) Dfs(p[i].x, 1-k);
		if (col[p[i].x]!=1-k) collision[ncomp]=1;
	}
}

void Solve()
{
	int i;

	ncomp=0;
	for (i=1; i<=n; i++)
		if (!comp[i]) {
			ncomp++;
			Dfs(i,0);
		}

	res=0; r1=0; r2=0;
	for (i=1; i<=n; i++) res+=b[i];

	for (i=1; i<=n; i++) u[comp[i]][col[i]]|=b[i];

	for (i=1; i<=ncomp; i++)
		if ((num[i][0]+num[i][1]>1) && (u[i][0] || u[i][1])){
			if ((u[i][0] && u[i][1]) || collision[i]) {
				r1+=num[i][0]+num[i][1];
				r2+=num[i][0]+num[i][1];
			} else
			if (u[i][0]) {
				r1+=num[i][0];
				r2+=num[i][1];
			} else {
				r1+=num[i][1];
				r2+=num[i][0];
			}
		}

	if (r1>res) res=r1;
	if (r2>res) res=r2;
}

int main()
{
	Init();
	Inp();
	Solve();
	Out();
	return 0;
}
