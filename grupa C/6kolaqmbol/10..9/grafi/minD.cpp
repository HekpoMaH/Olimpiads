#include<iostream>
using namespace std;
int n,m,a[400][400],g1,g2,r,mn=400,ngf,ngs,used[400],ng,s;
int main()
{
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    cin>>g1>>g2>>r;
    if(r<mn){mn=r;ngf=g1;ngs=g2;}
    a[g1][g2]=r;
    a[g2][g1]=r;
  }
  used[ngf]=1;
  used[ngs]=1;
  int l=1;
  s+=mn;
  while(l)
  {
    mn=400;l=0;
    for(int i=1;i<=n;i++)
    {
      if(used[i]==1)
      {
        for(int j=1;j<=n;j++)
        {
          if(used[j]==0)
          {
            if(a[i][j]<mn&&a[i][j]!=0){mn=a[i][j];ng=j;l=1;}
          }
        }
      }
    }
    used[ng]=1;
    if(l!=0)s+=mn;
    //cout<<" s="<<s<<endl;
  }
  cout<<s<<endl;
  return 0;
}
