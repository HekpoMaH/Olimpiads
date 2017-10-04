#include<iostream>
using namespace std;
int s[10][10];
int n,m;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>s[i][j];
    }
  }
  for(int i=0;i<=n-1;i++)
  {
    for(int j=0;j<i;j++)
    {
      cout<<s[i][j]<<" ";
    }
  }
  return 0;
}
