#include<iostream>
#include<queue>
using namespace std;
int used[2048],a[2048][2048],n,m,v[2048];                                                                 
queue<int> q;
void read  ()
{
    int x,y,i;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        a[x][y]=a[y][x]=1;
    }
}
void bfs(int i)
{
    int k,j,max=0,tek=0,;
    q.push(i);
    used[i]=1;
    v[i]=1;
    do
    {
        
        k=q.front();
        q.pop();
        used[k]=0;
        for(j=1;j<=n;j++)
        {
            if(a[k][j]==1&&v[j]==0)
            {
                q.push(j);
                used[j]=1;
                v[j]=1;
            }
        }
        for(j=1;j<=n;j++)
        {
            if(used[j]==1) tek++;
        }
        if(tek>max)max=tek;
        tek=0;
    }
    while(q.front());
    cout<<max<<endl;
}

int main()
{
    read();
    bfs(1);
    
    return 0;
}
