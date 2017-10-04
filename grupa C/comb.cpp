#include<iostream>
using namespace std;
int n,a[15],m[20];
void comb(int s,int k,int after)
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
      comb(s+1,k,i);
      //used[i]=0;
    }
  }
}
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  comb(0,3,-1);
  return 0;
}
