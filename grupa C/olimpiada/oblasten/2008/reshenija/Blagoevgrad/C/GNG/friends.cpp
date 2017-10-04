#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n,m,sz[2048],ans,used[1024];
 int br[2048];
vector <int> a[1024];
void scan()
{
    int x,y;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        a[x].push_back(y);sz[x]++;
    }
  
}
void BFS(int i)
{
    queue <int> q;
    q.push(i);
    used[i]=1;
    while(!q.empty())
    {
        i=q.front();
        int sz=a[i].size();
        for(int j=0;j<sz;j++)
        {
            if(!used[a[i][j]]){used[a[i][j]]=used[i]+1;q.push(a[i][j]);}
        }
        q.pop();
    }
} 
int main()
{
    scan();
    BFS(1);
   
    for(int i=0;i<=n;i++)
    {
        br[used[i]]++;
    }
    for(int i=0;i<=2048;i++)
    ans=max(ans,br[i]);
    cout<<ans<<endl;
    
    return 0;
}
