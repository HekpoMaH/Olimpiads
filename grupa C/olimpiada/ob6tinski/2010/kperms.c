#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n;
int k;
int a[]={1,2,3,4,5,6,7,8,9};
int used[10];
int m[10],l,kp;
void perm(int s)
{
  if(s>=n)
  {
    l=1;
    for(int i=0;i<n-1;i++)
    {
      if(abs((double)m[i]-(double)m[i+1])>k){l=0;break;}
    }
    if(l==1)kp++;
  }
  else
  {
    for(int i=0;i<n;i++)
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
  cin>>n>>k;
  perm(0);
  cout<<kp<<endl;
  return 0;
}
