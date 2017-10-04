#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int t;
int a[202][202],n;
void change(int &a,int &b)
{
    if(a==0&&b==1)a=1,b=0;
    else if(a==1&&b==0)a=0,b=-1;
    else if(a==0&&b==-1)a=-1,b=0;
    else a=0,b=1;
}
void solve()
{
    scanf("%d",&n);
    int xx=0,yy=1;
    int x=1,y=1,br=1;
    memset(a,0,sizeof(a));
    while(1)
    {
        //cout<<a[x][y]<<" "<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
        if(a[x][y]==0)a[x][y]=br;
        br++;x+=xx;y+=yy;
        if(a[x+xx][y+yy]!=0||x+xx>n||yy+y>n||x+xx<1||y+yy<1)change(xx,yy);
        //cout<<"AS "<<a[x+xx][y+yy]<<endl;
        if(a[x+xx][y+yy]!=0||x+xx>n||yy+y>n||x+xx<1||y+yy<1){break;}
    }
    a[x][y]=br;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }printf("%d",a[i][n]);
        printf("\n");
    }
    printf("\n");
}
int main()
{
    scanf("%d",&t);
    while(t--)solve();
}
