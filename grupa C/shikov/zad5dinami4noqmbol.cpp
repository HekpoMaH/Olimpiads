#include<iostream>
#include<string>
using namespace std;
string s;
int n;
int f[60][60];
int main()
{
  cin>>s;
  n=s.size()-1;
  for(int i=0;i<=n;i++)
  for(int j=0;j<=n;j++)
  f[i][j]=0;
  for(int i=0;i<=n;i++)f[i][i]=1;
  int j;
  for(int p=1;p<=n;p++)
  {
    for(int i=0;i+p<=n;i++)
    {
      j=i+p;
      if(s[i]!=s[j])f[i][j]=0;
      else
      {
        f[i][j]=1;
        for(int k=i+1;k<j;k++)
        {
          for(int m=k;m<j;m++)
          {
            f[i][j]+=f[k][m];
          }
        }
      }
    }
  }
  int s=0;
  for(int i=0;i<=n;i++)
  {
    for(j=0;j<=n;j++)
    {
      s+=f[i][j];
    }
  }
  cout<<s<<endl;
  return 0;
}
