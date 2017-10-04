#include<iostream>
using namespace std;
int vis[105],g[400][400],n,m,a,b,v[105],c,na,kr,used[105],pred[105],mn=3055,i0,j0;
int main()
{
  cin>>n>>m>>na>>kr;
  for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)g[i][j]=3055;
  for(int i=1;i<=n;i++)cin>>vis[i];
  for(int i=1;i<=m;i++)
  {
    cin>>a>>b;
    c=abs(a-b);
    g[a][b]=c;
    g[b][a]=c;
  }
  used[na]=1;
  pred[na]=-1;
  do
  {
     mn=3055;
     for(int i=1;i<=n;i++)
     {
       if(used[i]==0)
       {
         for(int j=1;j<=n;j++)
         {
           if(used[j]==1)
           {
             if(g[i][j]+v[j]<mn)
             {
               mn=g[i][j]+v[j];
               i0=i;j0=j;
             }
           }
         }
       }
     }
     if(mn!=3055)
     {
       used[i0]=1;
       v[i0]=mn;
       pred[i0]=j0;
     }
  }while(mn!=3055);
  int k,pat[106],br=0;
  k=kr;
  while(k!=-1)
  {
    pat[br]=k;//cout<<k<<" ";
    br++;
    k=pred[k];
  }
  cout<<pat[br-1];
  for(int i=br-2;i>=0;i--)cout<<" "<<pat[i];
  cout<<endl;
  return 0;
}
