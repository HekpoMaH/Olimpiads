#include<iostream>
using namespace std;
int x,y,n,m,st[5000],p[105],g[105][105],br,b,e;
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        g[x][y]=1;g[y][x]=1;
        st[x]++;st[y]++;
    }
    b=1;e=m+1;
    p[b]=1;
    for(int i=1;i<=n;i++)
    {
        if(st[i]%2!=0)
        {
            br++;
            if(br==1)p[b]=i;
        }
    }
    if(br!=0&&br!=2){cout<<"No way."<<endl;}
    
    while(b!=e)
    {
        if(st[p[b]]==0)
        {
            p[e]=p[b];
            e--;b--;
        }
        if(st[p[b]]>0)
        {
            for(int i=1;i<=n;i++)
            {
                if(g[p[b]][i]==1)
                {
                    st[i]--;st[p[b]]--;
                    p[b+1]=i;
                    g[p[b]][i]=0;
                    g[i][p[b]]=0;
                    b++;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=m+1;i++)cout<<p[i]<<" ";
    cout<<endl;
    return 0;
}