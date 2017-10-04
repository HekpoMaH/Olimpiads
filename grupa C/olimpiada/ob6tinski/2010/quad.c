#include<iostream>
using namespace std;
int n,m,k,ki,kj,s1,s2,s3,s4;
int tab[104][104];
int main()
{
  cin>>n>>m>>k;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>tab[i][j];
      if(i*m+j+1==k){ki=i;kj=j;}
    }
  }
  for(int i=0;i<ki;i++)
  {
    for(int j=kj+1;j<m;j++)
    {
      s1+=tab[i][j];
    }
  }
  for(int i=ki+1;i<n;i++)
  {
    for(int j=kj+1;j<m;j++)
    {
      s4+=tab[i][j];
    }
  }
  for(int i=0;i<ki;i++)
  {
    for(int j=0;j<kj;j++)
    {
      s2+=tab[i][j];
    }
  }
  for(int i=ki+1;i<n;i++)
  {
    for(int j=0;j<kj;j++)
    {
      s3+=tab[i][j];
    }
  }
  cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
  return 0;
}
