#include<iostream>
#include<algorithm>
using namespace std;
long long g[1004][1004],br;
int n,m;
bool used[1009];
long long v[1009];
int pred[1009];
int mn,i0,j0,a,b,c,cena[108];
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      g[i][j]=999999999;

    }
  }
  for(int i=1;i<=n;i++)cin>>cena[i];
  cin>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>a>>b;
    g[a][b]=cena[a];
    g[b][a]=cena[b];
  }
  used[1]=1;
  pred[1]=-1;
 //for(int i=0;i<n;i++)
  //{
    //for(int j=0;j<n;j++)cout<<g[i][j]<<" ";
    //cout<<endl;
  //}
  do
  {
    mn=999999999;
    for(int i=1;i<=n;i++)
    {
      if(used[i]==0)
      {
        for(int j=1;j<=n;j++)
        {
          if(used[j]==1)
          {
            if(v[j]+g[i][j]<mn)
            {
              mn=v[j]+g[i][j];
              i0=i;j0=j;
            }
          }
        }
      }
    }
    if(mn<999999999)
    {
      used[i0]=1;
      v[i0]=mn;
      pred[i0]=j0;
      //cout<<"aaaaa"<<endl;
    }

  }while(mn<999999999);
  if(v[n-1]>0)cout<<v[n]+cena[1]-cena[n]<<endl;
  else cout<<-1<<endl;
  return 0;
}
