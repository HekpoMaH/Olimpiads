#include <stdio.h>
#define MAXINT 32767
#define MAXN 500
#define MAXM 1500
	int N,M;int minx,miny,minp;
	int p[MAXN+1][3],d[MAXM][3];
	int stck[MAXN],stckp=0;
	int found[MAXN],dist[MAXN];

int mymin(int a,int b)
{
	if(a<=b) return a; else return b;
}

void find_short(int v)
{
	int dst[MAXN],parent[MAXN],u[MAXN];
	int i, mind, minv;
	for(i=1;i<=N;i++) {u[i]=0;parent[i]=v;dst[i]=MAXINT;}
	u[v]=1;parent[v]= -1;dst[v]=0;
	for(i=0;i<M;i++)
	{
		if(d[i][0]==v) {dst[d[i][1]]=d[i][2];continue;}
		if(d[i][1]==v) dst[d[i][0]]=d[i][2];
	}
int flag=0;do
{
	minv=N+1;mind=MAXINT;
	for(i=1;i<=N;i++)
		if(u[i]==0&&dst[i]<mind) {mind=dst[i];minv=i;}
	if(found[minv]==2)
	{
		i=parent[minv];
		while(i!= -1) 
		{
			found[i]=1;
			dist[i]=dist[minv]+dst[minv]-dst[i];
			i=parent[i];
		}
		flag=1;
	}
	else
	{
		u[minv]=1;
		for(i=1;i<=M;i++)
		{
			if(d[i][0]==minv&&u[d[i][1]]==0) 
			{
				dst[d[i][1]]=mymin(dst[d[i][1]],dst[minv]+d[i][2]);
				parent[d[i][1]]=minv;
			}
			else if(d[i][1]==minv&&u[d[i][0]]==0) 
			{
				dst[d[i][0]]=mymin(dst[d[i][0]],dst[minv]+d[i][2]);
				parent[d[i][0]]=minv;
			}
		}
	}
} while(flag!=1);
}

int cross(int k,int l,int m)
{
	int x0,x1,x2,y0,y1,y2,z;
	x0=p[k][0];y0=p[k][1];
	x1=p[l][0];y1=p[l][1];
	x2=p[m][0];y2=p[m][1];
	z=(x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
	if(z>0) return 1;
	else if(z<0) return -1; 
	else return 0;
}

void main()
{
	int i,j;char c;
	FILE *inf,*outf; //int hull[MAXN],hullp;

	inf=fopen("snow.inp","r");
	fscanf(inf,"%d %d",&N,&M);
	for(i=1;i<=N;i++) {fscanf(inf,"%d %d",p[i],p[i]+1);p[i][2]=i;}
	for(i=0;i<M;i++) fscanf(inf,"%d %d %d",d[i],d[i]+1,d[i]+2);
	// finding the lower point
	miny=MAXINT;minx=MAXINT;minp=MAXN;
	for(i=1;i<=N;i++)
		if(p[i][1]<=miny)
		{
			if(p[i][1]<miny)
			{
				miny=p[i][1];minx=p[i][0];
				minp=i;
			}
			else if(p[i][0]<minx)
			{
				minx=p[i][0];minp=i;
			}
		}
	for(i=0;i<=2;i++) p[0][i]=p[minp][i];
	for(j=minp+1;j<=N;j++)
		for(i=0;i<=2;i++) p[j-1][i]=p[j][i];
	for(j=N-2;j>=1;j--)
		for(i=1;i<=j;i++)
		{
			int x=(p[i][0]-p[0][0])*(p[i+1][1]-p[0][1])-(p[i+1][0]-p[0][0])*(p[i][1]-p[0][1]);
			if(x<0)
			{
				int t=p[i][0];p[i][0]=p[i+1][0];p[i+1][0]=t;
				    t=p[i][1];p[i][1]=p[i+1][1];p[i+1][1]=t;
				    t=p[i][2];p[i][2]=p[i+1][2];p[i+1][2]=t;
			}
			else if(x==0)
			{
				int y=(p[i][0]-p[0][0])*(p[i][0]-p[0][0])-(p[i][1]-p[0][1])*(p[i][1]-p[0][1]);
				if(y>(p[i+1][0]-p[0][0])*(p[i+1][0]-p[0][0])-(p[i+1][1]-p[0][1])*(p[i+1][1]-p[0][1]))
				{
					int t=p[i][0];p[i][0]=p[i+1][0];p[i+1][0]=t;
					    t=p[i][1];p[i][1]=p[i+1][1];p[i+1][1]=t;
					    t=p[i][2];p[i][2]=p[i+1][2];p[i+1][2]=t;		
				}
			}
		}
	
	stck[stckp++]=0;
	stck[stckp++]=0;
	stck[stckp++]=1;
	stck[stckp++]=2;
	for(i=3;i<N;i++)
	{
		while(cross(stck[stckp-2],stck[stckp-1],i)<0) 
			stckp--;
		stck[stckp++]=i;
	}
//	for(i=1;i<stckp;i++) {printf("%3d",p[stck[i]][2]);
//	if(i%20==0) printf("\n");}
//	scanf("%c",c);

	// Dijkstra
	for(i=1;i<=N;i++) {found[i]=0;dist[i]=MAXINT;}
	for(i=1;i<stckp;i++)
	{found[p[stck[i]][2]]=2;dist[p[stck[i]][2]]=0;}
	i=1;while(i<=N)
	{
		if(found[i]!=0) {i++;continue;}
		find_short(i);
		i++;
	}

	int sum=0;
	for(i=1;i<=N;i++) sum+=dist[i];
        // printf("%3d",dist[i]);
	//if(i%20==0) printf("\n");

        outf=fopen("snow.out","wt");
	fprintf(outf, "%5d\n",sum);
}
