#include <iostream>

using namespace std;
int a[2000][2000],b[2000],used[2000],l[2000],l2[2000],n;
void pred(int i)
{
  if(l[i]==0) return ;
  l2[i]=l2[l[i]]+1;
  
}

/****************************************/
void bfs(int m)
{
 used[m]=1;
 int k=1,i,j;
 b[k]=1;
 for(i=1;i<=k;i++)
 {
    for(j=1;j<=n;j++)
    {
      if(a[b[i]][j]==1){if(used[j]!=1){k++;b[k]=j;l[k]=b[i];used[j]=1;}}
      
        }
       
}

}
int main() {
  int m,x,y,i;
  cin>>n>>m;
  for(i=0;i<m;i++){
  cin>>x>>y;
  a[x][y]=1;
  a[x][0]++;
  }
  bfs(1);
    for(i=1;i<=n;i++)
  cout<<l2[i]<<" ";
  for(i=2;i<=n;i++)
  pred(i);
  cout<<endl;
  return 0;
}
