#include<cstdio>
using namespace std;
long long i,n,b,a[1000000];
int main()
{scanf("%d",&n);for(i=0;i<n;i++){scanf("%d",&b);if(a[b])a[b]=0;else a[b]=1;}
for(i=0;i<1000000;i++)if(a[i])printf("%d ",i);}


/*
10
14
7
21
9
14
17 
17
7 
19 
9

19 21
*/
