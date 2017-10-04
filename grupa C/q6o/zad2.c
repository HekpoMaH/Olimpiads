#include<iostream>
#include<string>
using namespace std;
string s[102];
int m,n,l,st;
int main()
{

  cin>>m>>n;
  for(int i=0;i<=m+1;i++)
  {
    if(i==0||i==m+1)for(int j=0;j<=n+1;j++)s[i][j]='#';
    s[i][0]='#';s[i][n+1]='#';
  }
  for(int i=1;i<=m;i++)cin>>s[i];
  //cout<<7<<endl;
  l=1;
  while(l==1)
  {
    l=0;
  for(int i=1;i<=m;i++)for(int j=0;j<n;j++)
  {
    if(s[i][j]-'0'>=0&&s[i][j]-'0'<=9)
    {
      st=s[i][j]-'0';
      if(s[i+1][j]=='_'){s[i+1][j]=st+'0'+1;l=1;/*cout<<i+1<<" "<<j<<endl;*/}
      if(s[i-1][j]=='_'){s[i-1][j]=st+'0'+1;l=1;/*cout<<i-1<<" "<<j<<endl;*/}
      if(s[i][j+1]=='_'){s[i][j+1]=st+'0'+1;l=1;/*cout<<i<<" "<<j+1<<endl;*/}
      if(s[i][j-1]=='_'){s[i][j-1]=st+'0'+1;l=1;/*cout<<i<<" "<<j-1<<endl;*/}
    }
  }
  }
  for(int i=1;i<=m;i++)
  {
    cout<<s[i];
    cout<<endl;
  }
  cout<<endl;
  return 0;
}
