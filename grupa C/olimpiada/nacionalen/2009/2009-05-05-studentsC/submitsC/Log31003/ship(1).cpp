/*
TASK:ship
LANG:C++
*/
#include<iostream>
using namespace std;
int t[10001],p[10001],op[10001];
int main()
{    
int n,i,j;
cin>>n;
for(i=1;i<=n;i++)
 scanf("%d",&t[i]);
for(i=1;i<=n;i++)
{
 scanf("%d",&p[i]);
 p[i]++;
 op[p[i]]=i;
}
long long k,s=0;
for(i=1;i<=n;i++)
 if(p[i]!=i)
 {
  s=s+t[i]+t[p[i]];          
  p[op[i]]=p[i];          
  op[p[i]]=op[i];
  p[i]=i;
  op[i]=i;
 }
cout<<s<<endl; 
//system("pause");
return 0;
}
