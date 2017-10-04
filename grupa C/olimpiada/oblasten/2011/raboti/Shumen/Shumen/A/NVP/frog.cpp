#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
    int x,y;
};
node dir[4]={{+1,+1},{+1,-1},{-1,+1},{-1,-1}};
int a[2048][2048];
queue<node>q;
int n;
void init()
{
    int i,j;
    node tc,rc;
    for(i=0;i<1;i++)
    {
        for(j=0;j<=2047;j++) a[i][j]=a[j][i]=-1;
    }
    for(i=2046;i<=2047;i++)
    {
        for(j=0;j<2047;j++) a[i][j]=a[j][i]=-1;
    }
    tc.x=1002;
    tc.y=1002;
    a[tc.x][tc.y]=1;
    q.push(tc);
    while(!q.empty())
    {
        tc=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            rc.x=tc.x+dir[i].x;
            rc.y=tc.y+dir[i].y;
            if(!(a[rc.x][rc.y])&&a[rc.x][rc.y]!=-1)
            {
                a[rc.x][rc.y]=a[tc.x][tc.y]+1;
                q.push(rc);
            }
        }
    }
}
void read()
{
    int i,c,v;
    int asd[32];
    cin>>n;
    for(i=0;i<n*2;i++)
    {
        cin>>c>>v;
        asd[i]=a[c+1002][v+1002]-1;
    }
    sort(asd,asd+i);
    cout<<asd[n-1]<<endl;
}
int main()
{
    init();
    read();
    return 0;
}







