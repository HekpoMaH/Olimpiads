#include<iostream>
using namespace std;
int a[106][106],col[104],br;
int n;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>a[i][j];
    }
  }
  for(int i=0;i<n;i++)cin>>col[i];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<i;j++)
    {
      if(a[i][j]==1&&col[i]!=col[j])br++;
    }
  }
  cout<<br<<endl;
  return 0;
}
