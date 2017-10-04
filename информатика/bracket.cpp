#include<iostream>
#include<cstring>
using namespace std;
string s,dp[105][105],r;
int n;
int main()
{
  cin>>s;
  n=s.length()-1;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='(')dp[i][i]="()";
    if(s[i]==')')dp[i][i]="()";
    if(s[i]=='['||s[i]==']')dp[i][i]="[]";
  }
  //for(int i=0;i<n;i++)cout<<dp[i][i]<<endl;
  int j;
  string s1;
  char c;
  for(int p=1;p<=n;p++)
  {
    for(int i=0;i+p<=n;i++)
    {
      j=i+p;
      if(s[i]==']')dp[i][j]="[]"+dp[i+1][j];
      else if(s[i]==')')dp[i][j]="()"+dp[i+1][j];
      else
      {
        if(s[i]=='(')
        {
          s1=")";c=')';
        }
        else
        {
          s1="]";c=']';
        }
        dp[i][j]=s.substr(i,1)+s1+dp[i+1][j];
        for(int k=i+1;k<=j;k++)
        {
          if(s[k]==c)
          {
            r=s.substr(i,1)+dp[i+1][k-1]+s1+dp[k+1][j];
            if(r.size()<dp[i][j].size())dp[i][j]=r;
          }
          r=s.substr(i,1)+dp[i+1][k]+s1+dp[k+1][j];
          if(r.size()<dp[i][j].size())dp[i][j]=r;
        }
      }
    }
  }
  cout<<dp[0][n]<<endl;
  return 0;
}
