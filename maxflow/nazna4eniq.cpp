#include<bits/stdc++.h>
using namespace std;
const int inf=999999;
int n;
int a[109][109],flow[109][109],pred[109],used[109];
bool fl;
void bfs()
{
    queue<int> q;
    memset(used,0,sizeof(used));
    used[0]=1;
    int fr;
    pred[0]=-1;
    q.push(0);
    while(!q.empty())
    {
        fr=q.front();
        q.pop();
        //cout<<"fr="<<fr<<endl;
        for(int i=0;i<=2*n+1;i++)
        {
            if(a[fr][i]<0&&used[i]==0)
            {
                //cout<<"going to "<<i<<" cuz "<<a[fr][i]<<endl;
                q.push(i);
                used[i]=1;
                pred[i]=fr;
            }
        }
    }
    if(used[2*n+1]==1)fl=true;
}
void read()
{
    cin>>n;
    int y;
    for(int i=1;i<=n;i++)
    {
        a[0][i]=-inf;
        a[n+i][2*n+1]=-inf;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>y;a[i][n+j]=-y;
        }
    }
}
int main()
{
    read();
    fl=true;
    int i,mxfl=0;
    while(fl)
    {
        fl=false;
        memset(used,0,sizeof(used));
        bfs();
        if(fl==false)break;
        int mnf=-inf;
        for(i=n+1;i!=0;i=pred[i])
        {
            cout<<pred[i]<<" "<<i<<" "<<a[pred[i]][i]<<endl;
            mnf=max(mnf,a[pred[i]][i]);
        }
        for(i=n+1;i!=0;i=pred[i])
        {

            a[pred[i]][i]+=mnf;
            a[i][pred[i]]-=mnf;
            flow[pred[i]][i]+=mnf;
            flow[i][pred[i]]-=mnf;
        }
        mxfl+=-mnf;
        cout<<"mnf="<<mnf<<endl;
    }
}
/*
4
14 5 8 7
2 12 6 5
7 8 3 9
2 4 6 10
*/
