#include<bits/stdc++.h>
using namespace std;
int n,m;
int k;
int x2[1009],y2[1009],x1[1009],y11[1009];
void readsolve()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    cin>>m>>n;
    cin>>k;
    //cout<<k<<endl;
    memset(x1,0,sizeof(x1));memset(x2,0,sizeof(x2));
    memset(y11,0,sizeof(y11));memset(y2,0,sizeof(y2));
    char ch;
    int x,y;
    //monster wrk;
    for(int i=1;i<=k;i++)
    {
        scanf("%d %d %c",&x,&y,&ch);
        //wrk.i=x;wrk.j=y;wrk.pos=ch;
        //cout<<x<<"   "<<y<<" "<<ch<<endl;
        //6
        if(ch=='N')x1[i]=x,x2[i]=x,y11[i]=y,y2[i]=n;
        if(ch=='S')x1[i]=x,x2[i]=x,y11[i]=1,y2[i]=y;
        if(ch=='W')x1[i]=1,x2[i]=x,y11[i]=y,y2[i]=y;
        if(ch=='E')x1[i]=x,x2[i]=m,y11[i]=y,y2[i]=y;
        //monst.push_back(wrk);
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i!=j)
            {
                if(x1[i]==x2[i]&&x1[j]==x2[j]&&x1[i]==x1[j]&&y11[i]==1&&y2[j]==n&&y2[i]>=y11[j])y2[i]=n;
                if(y11[i]==y2[i]&&y11[j]==y2[j]&&y11[i]==y11[j]&&x1[i]==1&&x2[j]==m&&x2[i]>=x1[j])x2[i]=m;
            }
        }
    }
    int z[1009];memset(z,0,sizeof(z));
    for(int i=1;i<=k;i++)if(!z[i])
    {
        for(int j=1;j<=k;j++)if(!z[j]&&i!=j)
        {
            if(x1[j]>=x1[i]&&x2[j]<=x2[i]&&y11[j]>=y11[i]&&y2[j]<=y2[i])z[j]=1;
        }
    }
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        if(!z[i])ans+=(x2[i]-x1[i]+1)*(y2[i]-y11[i]+1);
    }
    for(int i=1;i<=k;i++)if(!z[i])
    {
        for(int j=1;j<=k;j++)
        {
            if(i!=j&&!z[j]&&x1[j]>=x1[i]&&x2[j]<=x2[i]&&y11[i]>=y11[j]&&y2[i]<=y2[j])ans--;
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    readsolve();
}
