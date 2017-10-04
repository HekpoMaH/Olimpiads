#include<iostream>
#include<string>
#include<vector>
using namespace std;
long int nom[102][102],br;
string s[102];
vector<int>g[103];
int ms[102][102],m,n;
struct sr
{
  int ba;
  int na;
};
int main()
{
  cin>>m>>n;
  //for(int i=0;i<=m+1;i++)
  //{
    //if(i==0||i==m+1)for(int j=0;j<=n+1;j++)s[i][j]='#';
    //s[i][0]='#';s[i][n+1]='#';
  //}
  for(int i=0;i<m;i++)cin>>s[i];
  sr sas[102];
  //for(int i=0;i<=m+1;i++)
  //{
    //cout<<s[i];
    //cout<<endl;
  //}
  for(int i=0;i<m;i++)for(int j=0;j<n;j++)
  {
    nom[i][j]=br;
    br++;
  }
  //for(int i=0;i<m;i++)
  //{
    //for(int j=0;j<n;j++)
    //cout<<nom[i][j];
    //cout<<endl;
  //}
  int br2=br;
  br=0;//cout<<s[0][1]<<endl;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(s[i][j]!='#')
      {
        //cout<<i<<" "<<j<<endl;
        if(i<m-1&&s[i+1][j]!='#')
        {
          //cout<<i+1<<" "<<j<<endl;
          g[nom[i][j]].push_back(nom[i+1][j]);
          //g[nom[i+1][j]].push_back(nom[i][j]);
          //cout<<nom[i][j]<<" "<<nom[i+1][j]<<endl;
          ms[nom[i+1][j]][nom[i][j]]=1;
          ms[nom[i][j]][nom[i+1][j]]=1;
          br++;
          sas[br].ba=nom[i][j];
          sas[br].na=nom[i+1][j];
        }
        if(i>0&&s[i-1][j]!='#')
        {
          //cout<<i+1<<" "<<j<<endl;
          g[nom[i][j]].push_back(nom[i-1][j]);
          //g[nom[i-1][j]].push_back(nom[i][j]);
          //cout<<nom[i][j]<<" "<<nom[i+1][j]<<endl;
          ms[nom[i-1][j]][nom[i][j]]=1;
          ms[nom[i][j]][nom[i-1][j]]=1;
          br++;
          sas[br].ba=nom[i][j];
          sas[br].na=nom[i-1][j];
        }
        if(j<n-1&&s[i][j+1]!='#')
        {
          //cout<<i+1<<" "<<j<<endl;
          g[nom[i][j]].push_back(nom[i][j+1]);
          //g[nom[i][j]].push_back(nom[i][j+1]);
          //cout<<nom[i][j]<<" "<<nom[i+1][j]<<endl;
          ms[nom[i][j+1]][nom[i][j]]=1;
          ms[nom[i][j]][nom[i][j+1]]=1;
          br++;
          sas[br].ba=nom[i][j];
          sas[br].na=nom[i][j+1];
        }
        if(j>0&&s[i][j-1]!='#')
        {
          //cout<<i+1<<" "<<j<<endl;
          g[nom[i][j]].push_back(nom[i][j-1]);
          //g[nom[i][j]].push_back(nom[i][j-1]);
          //cout<<nom[i][j]<<" "<<nom[i+1][j]<<endl;
          ms[nom[i][j-1]][nom[i][j]]=1;
          ms[nom[i][j]][nom[i][j-1]]=1;
          br++;
          sas[br].ba=nom[i][j];
          sas[br].na=nom[i][j-1];
        }
        }
      }
    }
  for(int i=0;i<br2;i++)
  {
    for(int j=0;j<br2;j++)
    {
      cout<<ms[i][j];
    }
    cout<<endl;
  }
  for(int i=0;i<br2;i++)
  {

    for(int j=0;j<g[i].size();j++)
    { if(j==0)cout<<i<<"->";
      cout<<g[i][j]<<" ";
      if(j==g[i].size()-1)cout<<endl;
    }
  }
  for(int i=1;i<br;i++)
  {
    cout<<sas[i].ba<<" "<<sas[i].na<<endl;
  }
  return 0;
}
