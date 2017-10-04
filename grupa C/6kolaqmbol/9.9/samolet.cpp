#include<iostream>
using namespace std;
int map[26][26];
int n,m;
int main()
{
  cin>>n>>m;
  map[0][0]=1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(map[i][j]==0)map[i][j]=map[i-1][j]+map[i][j-1];
    }
  }
  cout<<map[n-1][n-1]<<endl;
  return 0;
}
