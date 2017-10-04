
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>


#define SZ size()
#define PB push_back
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define x first
#define y second

#define LL long long
#define UI unsigned int
#define ULL unsigned long long
#define PI pair<int,int>
#define PD pair<double,double>
#define PLL pair<LL,LL>
#define PULL pair<ULL,ULL>
#define VI vector<int>
#define VD vector<double>
#define VS vector<string>
#define SI set<int>
#define PQ priority_queue
#define VVI vector<vector<int> >
#define IT iterator

#define sign(a) ((a)>0)-((a)<0)
#define sqr(a) ((a)*(a))
#define Repi(n) for (int i=0; i<n; i++)
#define Repj(n) for (int j=0; j<n; j++)
#define Repk(n) for (int k=0; k<n; k++)

#define Pi 3.1415926535897932384626433832795028841971693993751
#define INF 2000000000
#define EPS 1e-6

#define pause system("pause")

using namespace std;

int n,m;
double a[512],s[512],D[512][512],d[512][512];

int main()
{
    int i,j,k,l;
    scanf("%d%d",&n,&m);
    Repi(n)
     scanf("%lf",&a[i]);
    
    s[0]=0;
    Repi(n) s[i+1]=s[i]+a[i];
    
    for (int i=0;i<n;i++)
     for (int j=i;j<n;j++)
      {
		double mid=(s[j+1]-s[i])/(double)(j-i+1);
		D[i][j]=0;
        for (int k=i;k<=j;k++)
         D[i][j]+=sqr(mid-a[k]);
         
      //  printf("%d %d= %lf\n",i,j,D[i][j]);
	  }
	
	
	Repi(n+2) Repj(n+2) d[i][j]=1e100;
	d[0][0]=0.;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	  {
	    for (int k=i-1;k>=j-1;k--)
	      d[i][j]<?=d[k][j-1]+D[k][i-1];
       // printf("%d %d = %lf\n",i,j,d[i][j]);
	  }
    
    printf("%.4lf",d[n][m]);
    
    return 0;
}
