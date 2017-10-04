#include<iostream>
#include<cmath>
using namespace std;
int a[20][20],n,br=0;
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>a[i][j];
    }
  }
  int l=1;
  for(int i=1;i<n;i++)
  {
    for(int j=1;j<=n-i;j++)
    {
      if(a[i][j]!=a[n-j+1][n-i+1]){l=0;break;}
    }
  }
  if(l==1)
  {
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(a[i][j]!=0&&abs(a[i][j])%3==0){
                                        br++;
                                        if(br==1)cout<<a[i][j];
                                        else cout<<" "<<a[i][j];
                                       }
    }
  }
  cout<<endl;
  }
  if(l==0)
  {
    int s=0;
    for(int i=1;i<=n;i++)
    {
      if(i%2!=0)
      {
        for(int j=1;j<=n;j++)
        {
          s+=a[i][j];
        }
      }
    }
    cout<<s<<endl;
  }
  return 0;
}

