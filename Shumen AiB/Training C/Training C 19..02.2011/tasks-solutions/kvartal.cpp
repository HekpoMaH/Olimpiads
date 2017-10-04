#include<iostream>
using namespace std;
int n,a[1024][1024],used[1024],cn,mcn;

void DFS(int i)
{
 int i2;
 used[i]=1;
 for(i2=0;i2<n;i2++)if(!used[i2]&&a[i][i2])DFS(i2);
}

void DFS2(int i)
{
 int i2;
 used[i]=2;
 cn++;
 for(i2=0;i2<n;i2++)if(used[i2]==1&&a[i2][i])DFS2(i2);
}

int main()
{
 int m,x,y,i,i2;
 cin>>n>>m;
 for(i=0;i<m;i++)
 {
  cin>>x>>y;
  a[x-1][y-1]=1;
 }
 for(i=0;i<n;i++)
 {
   DFS(i);
   DFS2(i);
   if(cn>mcn)mcn=cn;
   cn=0;
   for(i2=0;i2<n;i2++)used[i2]=0;
 }
 cout<<mcn<<endl;
 return 0;
}
