#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
#define wait system("pause")
int n,br;
long long x,ans1,ans2;
map<long long, int> m;
map<int,long long> m1;
int main()
{


scanf("%d",&n);
for(int i=1;i<=n;i++)
{
cin>>x; m[x]++; if(m[x]==1) { m1[br]=x; br++; }
if(m[x]==2)
{
   m.erase(x);
   for(int j=0;j<br;j++)
   { if(m1[j]==x) { m1[j]=m1[br-1];  m1.erase(br-1); br--; break; } }
}
}
if(m1[0]>m1[1]) cout<<m1[1]<<" "<<m1[0]<<endl;
else
 cout<<m1[0]<<"  "<<m1[1]<<endl;
return 0;
}