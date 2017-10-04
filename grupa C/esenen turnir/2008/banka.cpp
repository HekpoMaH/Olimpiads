#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;
long long int n,m1,br;
long long int k;
int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13};
int used[15];
int m[15],;
void perm(int s)
{
  if(s>=k)
  {
    br++;//cout<<br<<endl;
    if(br>=n&&br<=m1)
    {
      for(int i=0;i<k;i++)
      {
        printf("%d",m[i]);
      }
      printf("\n");
    }
  }
  else
  {
    for(int i=0;i<k;i++)
    {
      if(used[i]==0)
      {
        m[s]=a[i];
        used[i]=1;
        perm(s+1);
        used[i]=0;
      }
    }
  }
}
int main()
{
  //ios::sync_with_stdio(false);
  cin>>k>>n>>m1;
  perm(0);
  return 0;
}
