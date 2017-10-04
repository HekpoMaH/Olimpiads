#include<iostream>
using namespace std;
bool x[50002],y[50002];
long a,b,c,n,br;
int main()
{
  cin>>n>>a>>b>>c;
  for(int i=0;i<=n;i+=a)
  {
    x[i]=true;
  }
  for(int i=n;i>=0;i-=b)
  {
    x[i]=true;
  }
  for(int i=0;i<=n-c;i++)
  {
    if(x[i]&&x[i+c])
    {
      for(int j=i;j<i+c;j++)
      {
        y[j]=true;
      }
    }
  }
  for(int i=0;i<n;i++)
  {
    if(!y[i])br++;
  }
  cout<<br<<endl;
  return 0;
}
