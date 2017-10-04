#include <iostream>
#include <cstdio>

using namespace std;

int S,n;
int A[3001];
int d[5001];
const int INF=5001;

int main()
{
 scanf("%d",&S);
 scanf("%d",&n);
 for(int i=0;i<n;i++)
      scanf("%d",&A[i]);
 
 d[0]=0;
 d[1]=1;
 for(int i=2;i<=S;i++)
     {d[i]=INF;
      for(int j=0;j<n;j++)
          if(i-A[j]>=0) d[i]=min(d[i],d[i-A[j]]+1);
      }
 printf("%d\n",d[S]);

 return 0;
}
 
