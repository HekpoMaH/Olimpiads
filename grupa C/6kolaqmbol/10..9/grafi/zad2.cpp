#include<iostream>
#include<algorithm>
using namespace std;
int n,m,mat[400][400],mn=999999,s,r[5],g1,g2,t;
int main()
{
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    cin>>g1>>g2>>t;
    //if(r<mn){mn=r;ngf=g1;ngs=g2;}
    mat[g1][g2]=t;
    mat[g2][g1]=t;
  }
  for(int a=2;a<=n;a++)
  {
    for(int b=2;b<=n;b++)
    {
      for(int c=2;c<=n;c++)
      {
          if(a!=b&&a!=c&&b!=c)
          {
            if(mat[1][a]>0&&mat[a][b]>0&&mat[b][c]>0&&mat[c][1]>0&&mat[1][a]+mat[a][b]+mat[b][c]+mat[c][1]<mn)
            {
              mn=mat[1][a]+mat[a][b]+mat[b][c]+mat[c][1];
              r[0]=a;
              r[1]=b;
              r[2]=c;
            }
          }
        }
      }
    }
  sort(r,r+3);
  cout<<mn<<" "<<r[0]<<" "<<r[1]<<" "<<r[2]<<endl;
  return 0;
}
