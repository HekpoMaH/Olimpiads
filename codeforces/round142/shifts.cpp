#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int n,m;
const int inf=1<<29;
string s[105];
int f[111][10012],k,br;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        fill(f[i],f[i]+m,inf);
    }
    for(int i=0;i<n;i++)
    {
        k=-1;
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='1')
            {
                k=j;
                break;
            }
        }
        if(k!=-1)
        {
            f[i][k]=0;
            br=0;
            for(int j=(k+1)%m;j!=k;j=(j+1)%m)
            {
                
                if(s[i][j]=='1')br=0;
                else br++;
                f[i][j]=min(f[i][j],br);
            }
            br=0;
            for(int j=(k-1+m)%m;j!=k;j=(j-1+m)%m)
            {
                //cout<<j<<endl;
                if(s[i][j]=='1')br=0;
                else br++;
                f[i][j]=min(f[i][j],br);
            }
        }
    }
    int ans=inf;long long sum;
    for(int i=0;i<m;i++)
    {
        sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=f[j][i];
        }
        if(sum<ans)ans=sum;
    }
    if(ans==inf)cout<<"-1"<<endl;
    else cout<<ans<<endl;
}