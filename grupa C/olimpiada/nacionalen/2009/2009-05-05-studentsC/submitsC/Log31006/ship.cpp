/*
TASK: ship
LANG: C++
*/
#include<iostream>
#include<vector>
using namespace std;
long x,s,n,i,b[10001];
vector<long> a;
int main()
 {
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {scanf("%d",&x);
  a.push_back(x);
 }
 for(i=0;i<n;i++)
 scanf("%d",&b[i]);
 for(i=0;i<n;i++)
 while(i!=b[i])
 {x=b[i];
  s+=a[i]+a[x];
  swap(a[i],a[x]);
  swap(b[i],b[x]);
 }
 printf("%d\n",s);
 //system("PAUSE");
 return 0;
 }
