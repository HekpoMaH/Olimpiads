#include<iostream>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

long long a[102][102],k,i,j,x,y,r,n,m,used[102][102],s,p,d[102][102];
queue<long long>q;

int main()
{
    cin>>n>>m>>r>>k;
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=m;j++)
      {
        p++;
        a[i][j]=p;
        if(a[i][j]==r){x=i;y=j;}
      }
    }
    q.push(x);
    q.push(y);
    used[x][y]=1;
    while(1==1)
    {
      x=q.front();
      q.pop();
      y=q.front();
      q.pop();


      if(x-1>=1 && y<=m)
         //if(used[x-1][y]==0)
           if(used[x][y]<=k)
           {
             if(used[x][y]<k)
             {
               q.push(x-1);
               q.push(y);
             }
             used[x-1][y]=used[x][y]+1;
             if(used[x-1][y]==k+1 && d[x-1][y]!=-1){s=s+a[x-1][y];d[x-1][y]=-1;}
           }



    if(x+1<=n && y<=m)
         //if(used[x+1][y]==0)
           if(used[x][y]<=k)
           {
             if(used[x][y]<k)
             {
               q.push(x+1);
               q.push(y);
             }
             used[x+1][y]=used[x][y]+1;
             if(used[x+1][y]==k+1 && d[x+1][y]!=-1){s=s+a[x+1][y];d[x+1][y]=-1;}
           }



    if(x<=n && y+1<=m)
         //if(used[x][y+1]==0)
           if(used[x][y]<=k)
           {
             if(used[x][y]<k)
             {
               q.push(x);
               q.push(y+1);
             }
             used[x][y+1]=used[x][y]+1;
             if(used[x][y+1]==k+1 && d[x][y+1]!=-1){s=s+a[x][y+1];d[x][y+1]=-1;}
           }





    if(x<=n && y-1>=1)
         //if(used[x][y-1]==0)
           if(used[x][y]<=k)
           {
             if(used[x][y]<k)
             {
               q.push(x);
               q.push(y-1);
             }
             used[x][y-1]=used[x][y]+1;
             if(used[x][y-1]==k+1 && d[x][y-1]!=-1){s=s+a[x][y-1];d[x][y-1]=-1;}
           }
    if(q.empty())break;
    }
    cout<<s<<endl;
    return 0;
}
