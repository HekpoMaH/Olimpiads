#include<cstdio>
#include<vector>
using namespace std;
int n,m,used[2001],br[2001],used1[2001];
vector<int> g[2001],next;
void read()
{
     int i,k1,k2;
     scanf("%d%d",&n,&m);
     for(i=0;i<m;i++)
     {
                     scanf("%d%d",&k1,&k2);
                     g[k1].push_back(k2);
                     
     }
}
void solve()
{
     //printf("\n");
     int i,j,k=1,o=n-1;
     for(i=0;i<g[1].size();i++)
     {
                               used[g[1][i]]=1;
     }
     while(o!=0)
     {
                         k++;
                         for(i=1;i<=n;i++)
                         {
                                         //printf("1");
                                         if(used[i]==k-1)
                                         {
                                                         o--;
                                                         //printf("%d %d\n",used[i],i);
                                                         int p=g[i].size();
                                                         for(j=0;j<p;j++)
                                                         {
                                                                         if(!used[g[i][j]])used[g[i][j]]=k;
                                                         }
                                         }
                         }
                         
     }
     int k1=0;
     for(i=1;i<=n;i++)
     {
                     br[used[i]]++;
                     if(used[i]>k1)k1=used[i];
     }
     //for(i=1;i<=k1;i++)
     //printf("%d ",br[i]);
     //printf("\n");
     int maxo=1;
     
     for(i=1;i<=k1;i++)
                      maxo=max(br[i],maxo);
     printf("%d\n",maxo);
}                 
int main()
{
    read();
    solve();
    return 0;
}
