#include<fstream>
using namespace std;
long long m,n,dp[52][52],d1,d2,d3,d4;
int main()
{
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  fin>>m>>n;
  dp[1][1]=1;
  dp[0][3]=2;
  dp[3][0]=2;
  dp[2][3]=2;
  dp[3][2]=2;
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      d1=0;d2=0;d3=0;d4=0;
      if(j>=2){d1=dp[i-1][j-2];d3=dp[i+1][j-2];}
      if(i>=2){d2=dp[i-2][j-1];d4=dp[i-2][j+1];}
      if(dp[i][j]==0)dp[i][j]=d1+d2+d3+d4;
    }
  }
  /*for(int i=0;i<=m;i++)
  {
    for(int j=0;j<=n;j++)
    {
      fout<<dp[i][j]<<" ";
      //fout<<dp[i][j]<<" "<<dp[i-1][j-2]<<" "<<dp[i-2][j-1]<<" "<<dp[i+1][j-2]<<" "<<dp[i-2][j+1]<<endl;
    }
    fout<<endl;
  }*/
  fout<<dp[m][n]<<endl;
  fin.close();fout.close();
  return 0;
}
