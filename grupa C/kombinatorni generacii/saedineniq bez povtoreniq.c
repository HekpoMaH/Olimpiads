#include<iostream>
using namespace std;
int a[]={1,2,3,4,5};
int used[10],m[10],n=5,k=3;
void perm(int s)
{
  if(s>=n)
  {
    for(int i=0;i<n;i++)
    {
      cout<<m[i]<<" ";
    }
    cout<<endl;
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
void var(int s)
{
  if(s>=k)
  {
    for(int i=0;i<s;i++)
    {
      cout<<m[i]<<" ";
    }
    cout<<endl;
  }
  else
  {
    for(int i=0;i<n;i++)
    {
      if(used[i]==0)
      {
        m[s]=a[i];
        used[i]=1;
        var(s+1);
        used[i]=0;
      }
    }
  }
}
void comb(int s,int after)
{
  if(s>=k)
  {
    for(int i=0;i<s;i++)
    {
      cout<<m[i]<<" ";
    }
    cout<<endl;
  }
  else
  {
    for(int i=after+1;i<n;i++)
    {
      m[s]=a[i];
      comb(s+1,i);
    }
  }
}
int main()
{
  cout<<"Permutacii"<<endl;
  perm(0);
  cout<<"variacii"<<endl;
  var(0);
  cout<<"kombinacii"<<endl;
  k=1;comb(0,-1);k=2;comb(0,-1);k=3;comb(0,-1);
  return 0;
}

