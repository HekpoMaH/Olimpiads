
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

int n,m,MOD;
int pr[10000],d[101000];
bool ispr[101000];

int main()
{
    int i,j,k,l;
    cin>>n;
    if (n<=3) { cout<<"0\n"; return 0; }
    
    memset(ispr,1,sizeof(ispr));
    ispr[0]=ispr[1]=0;
    for (int i=2;i*i<=2*n;i++)
     if (ispr[i])
      for (int j=i*i;j<=2*n;j+=i)
       ispr[j]=0;
    Repi(2*n)
     if (ispr[i])
      pr[m++]=i;
      
  //  Repi(m) cout<<pr[i]<<" "; cout<<endl;
    MOD=n+1;
    while (!ispr[MOD]) MOD++;
    while (pr[m-1]>n && m) m--; m++;

    memset(d,0,sizeof(d));
    Repi(m)
     { d[pr[i]]++;
 //      cout<<pr[i]<<" "<<d[pr[i]]<<endl;
//       cout<<pr[i]<<endl;
       for (int j=0; j+pr[i]<=n;j++)
         d[j+pr[i]]=(d[j+pr[i]]+d[j])%MOD;
     }
     
   // Repi(n+1) cout<<d[i]-ispr[i]<<" "; cout<<endl;
     
    cout<<(d[n]-ispr[n]+MOD)%MOD<<"\n";

//    pause;      
    return 0;
}
