#include<iostream>
#include<queue>
#include<set>
#include<cstring>
using namespace std;
int dx[5]={0,-1,1,0,0};
int dy[5]={0,0,0,1,-1};
int a[122][122];
int n,m,mx;
struct mf
{
    int x,y,g;
};
int gg;
queue<mf> q;
void solve()
{
    while(!q.empty())
    {
        // cout<<"A"<<endl;
        gg++;int i1,j1;
        queue<pair<int,int> >q1;
        while(!q.empty())
        {
            mf milf;
            milf=q.front();q.pop();
            i1=milf.x;j1=milf.y;
            if(milf.g!=a[i1][j1])continue;
            a[i1][j1]++;
            q1.push(make_pair(i1,j1));
        }
        while(!q1.empty())
        {
            i1=q1.front().first;
            j1=q1.front().second;q1.pop();
            for(int k=1;k<=4;k++)
            {//cout<<"what about "<<i<<" "<<j<<" cus of "<<i+dx[k]<<" "<<j+dy[k]<<endl;
                if(a[i1][j1]==a[i1+dx[k]][j1+dy[k]]+1)
                {
                    mf ee;
                    ee.x=i1+dx[k];ee.y=j1+dy[k];ee.g=a[i1+dx[k]][j1+dy[k]];
                    //a[ee.x][ee.y]++;
                    //s.insert(ee);
                    q.push(ee);//break;
                }
                else if(a[i1][j1]+1==a[i1+dx[k]][j1+dy[k]])
                {
                    mf ee;
                    ee.x=i1;ee.y=j1;ee.g=a[i1][j1];
                    //a[ee.x][ee.y]++;
                    //s.insert(ee);
                    q.push(ee);//break;
                }
            }
        }
    }
}
int main()
{
    cin>>n>>m;dx[0]=0;dx[1]=1;dx[2]=-1;dx[3]=0;dx[4]=0;
              dy[0]=0;dy[1]=0;dy[2]=0;dy[3]=1;dy[4]=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];

        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            //cin>>a[i][j];
            for(int k=1;k<=4;k++)
            {//cout<<"what about "<<i<<" "<<j<<" cus of "<<i+dx[k]<<" "<<j+dy[k]<<endl;
                if(a[i][j]+1==a[i+dx[k]][j+dy[k]])
                {
                    mf ee;
                    ee.x=i;ee.y=j;ee.g=a[i][j];
                    //a[ee.x][ee.y]++;
                    //s.insert(ee);
                    q.push(ee);break;
                }
            }
        }
    }
    //cout<<"D"<<q.size()<<endl;
    solve();
    cout<<gg<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
