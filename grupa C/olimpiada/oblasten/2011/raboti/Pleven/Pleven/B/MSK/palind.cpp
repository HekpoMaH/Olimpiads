#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,i,x,j,l,r,fl,s,a[10001],b[10001];
vector<int> c[10001];
int main()
{
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  scanf("%d",a+i);
  b[i]=10001;
 }

 b[0]=0; b[1]=1;
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=i;j++)
  {
   l=j; r=i; fl=0;
   while(l<=r)
   {
   if(a[l]!=a[r]) {fl=1; break;}
   l++; r--;
   }
   if(fl==0)
    if(b[i]>b[j-1]+1)
    {
     b[i]=b[j-1]+1;
     c[i]=c[j-1];
     c[i].push_back(j-1);
    }
  }
 }

 printf("%d\n",b[n]);
 s=c[n].size();
 for(i=1;i<s-1;i++)
  printf("%d ",c[n][i]);
 printf("%d",c[n][s-1]);
 printf("\n");
 return 0;
}


/*
16
1 1 0 0 0 1 1 0 0 0 0 1 1 0 0 0
*/