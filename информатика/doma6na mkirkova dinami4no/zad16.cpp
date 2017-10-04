#include<fstream>
using namespace std;
int m,n,dp[52][52];
int main()
{
  ifstream fin("input.txt");
  fin>>m>>n;
  dp[1][1]=1;
  for(int i=2;i<=m;i++)
  {
    for(int j=2;j<=n;j++)
    {
      dp[i][j]=dp[i-1][j-2]+dp[i-2][j-1];
    }
  }
  ofstream fout("output.txt");
  fout<<dp[m][n]<<endl;
  fin.close();fout.close();
  return 0;
}
