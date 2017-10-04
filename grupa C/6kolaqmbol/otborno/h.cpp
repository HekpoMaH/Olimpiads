#include<iostream>
#include<memory>
using namespace std;
int dp[201][201][201],used[603],x,y,z,k,ans;
void Dp(int a,int b,int c)
{
  if(used[a]==0){ans++;used[a]=1;}
  if(used[b]==0){ans++;used[b]=1;}
  if(used[c]==0){ans++;used[c]=1;}
  if(used[a+b]==0){ans++;used[a+b]=1;}
  if(used[a+c]==0){ans++;used[a+c]=1;}
  if(used[b+c]==0){ans++;used[b+c]=1;}
  if(used[a+b+c]==0){ans++;used[a+b+c]=1;}
  if(dp[x][b][c]==0){dp[x][b][c]=1;Dp(x,b,c);}
  if(dp[a][y][c]==0){dp[a][y][c]=1;Dp(a,y,c);}
  if(dp[a][b][z]==0){dp[a][y][c]=1;Dp(a,b,z);}
  int r;

  r=a+b;
  if(r>x)r=x;
  //cout<<r<<endl;
  if(b-r+a>=0&&!dp[r][b-r+a][c]==0){dp[r][b-r+a][c]=1;cout<<r<<" "<<b-r+a<<" "<<c<<endl;Dp(r,b-r+a,c);}
  r=a+b;
  if(r>y)r=y;
  //cout<<r<<endl;
  if(a-r+b>=0&&!dp[a-r+b][r][c]==0){dp[a-r+b][r][c]=1;cout<<a-r+b<<" "<<r<<" "<<c<<endl;Dp(a-r+b,r,c);}
  r=a+c;
  if(r>x)r=x;
  //cout<<r<<endl;
  if(c-r+a>=0&&!dp[r][b][c-r+a]){dp[r][b][c-r+a]=1;cout<<r<<" "<<b<<" "<<c-r+a<<endl;Dp(r,b,c-r+a);}
  r=a+c;
  if(r>z)r=z;
  //cout<<r<<endl;
  if(a-r+c>=0&&!dp[a-r+c][b][r]){dp[a-r+c][b][r]=1;cout<<a-r+c<<" "<<b<<" "<<r<<endl;Dp(a-r+c,b,r);}
  r=b+c;
  if(r>y)r=y;
  //cout<<r<<endl;
  if(c-r+b>=0&&!dp[a][r][c-r+b]){dp[a][r][c-r+b]=1;cout<<a<<" "<<r<<" "<<c-r+b<<endl;Dp(a,r,c-r+b);}
  r=b+c;
  if(r>z)r=z;
  //cout<<r<<endl;
  if(b-r+c>=0&&!dp[a][b-r+c][r]){dp[a][b-r+c][r]=1;cout<<a<<" "<<b-r+c<<" "<<r<<endl;Dp(a,b-r+c,r);}
  return;
}
int main()
{
  cin>>k;
  for(int i=0;i<k;i++)
  {
      memset(dp,0,sizeof(dp));
      memset(used,0,sizeof(used));
      ans=0;
      cin>>x>>y>>z;
      dp[0][0][0]=1;
      Dp(0,0,0);
      cout<<ans-1<<endl;
  }
  return 0;
}
