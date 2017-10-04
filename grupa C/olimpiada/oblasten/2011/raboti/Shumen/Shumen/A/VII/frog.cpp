#include<iostream>
using namespace std;

struct point 
{
   int x,y;
};

point a[16];
int d[16][16];

int n;
int used[16];
int m;
void read()
{
   int i,j,k,l;
   a[0].x=0;
   a[0].y=0;
   cin>>n;
   m=n*2;
   for(i=1;i<=m;i++)
   {
      cin>>k>>l;
      a[i].x=k;
      a[i].y=l;
   }


}

int ans=999999;

int dfs(int k,int dist, int lvl)
{
//   cout<<lvl<<" ";
   int i,j;
   if(lvl==n)
   {
      if(dist<ans) ans=dist;
      return 0;
   }
   for(i=1;i<=m;i++)
   {
      if(used[i]==0)
      {
         used[i]=1;
         dfs(i,dist+d[k][i],lvl+1);
         used[i]=0;
      }
   }


}

void slove()
{
   int i,j,k,l;
   for(i=0;i<m;i++)
   {
      for(j=i+1;j<=m;j++)
      {
         d[i][j]=max(abs(a[i].x-a[j].x),abs(a[i].y-a[j].y));
         d[j][i]=max(abs(a[i].x-a[j].x),abs(a[i].y-a[j].y));
      }
   }
//   for(i=0;i<m;i++)
  // {
    //  for(j=i+1;j<=m;j++)
      //{
        // cout<<i<<" | "<<j<<" || "<<d[i][j]<<endl;
      //}
   //}
   dfs(0,0,0);
   cout<<ans<<endl;

}

int main()
{
   read();
   slove();
}
