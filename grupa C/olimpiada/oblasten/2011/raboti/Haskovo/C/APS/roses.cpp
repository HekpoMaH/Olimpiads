#include<iostream>
using namespace std;
int rozeField[1005][1005];
int main()
{
  int m,n,k;
  cin>>m>>n>>k;
  long long int sum=0;
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>rozeField[i][j];
      sum+=rozeField[i][j];
    }
  }
  long long int sumNow=0,maxSum=0;
  for(int i=1;i<=m-k+1;i++)
  {
    for(int j=1;j<=n-k+1;j++)
    {
      sumNow=0;
      for(int x=i;x<=i+k-1;x++)
      {
        for(int y=j;y<=j+k-1;y++)
        {
          sumNow+=rozeField[x][y];
        }
      }
      if(sumNow>maxSum)
      {
        maxSum=sumNow;
      }
    }
  }
  cout<<sum-maxSum<<endl;
  return 0;
}