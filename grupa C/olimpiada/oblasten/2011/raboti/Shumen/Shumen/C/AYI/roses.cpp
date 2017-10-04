#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstdio>
using namespace std;
struct pok
{
    int x;
    int y;
    int osx;
    int osy;
};

queue <pok> v;
int garden[1240][1240],m,n,k,maxa,rez[1240][1240],ooo;
int main()
{
    int i,j,o,g;
    pok v1;
    cin>>m>>n>>k;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++) {scanf("%d",&garden[i][j]);ooo+=garden[i][j];}
    for(i=0;i<=m+1;i++) garden[0][i]=garden[n+1][i]=-10000000;
    for(i=0;i<=n+1;i++) garden[i][0]=garden[i][n+1]=-10000000;

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(o=0;o<k;o++)
            {
                for(g=0;g<k;g++)
                {
                    rez[i][j]=garden[i+o][j+g]+rez[i][j];
                    if(rez[i][j]>maxa) maxa=rez[i][j];
                }
        }
    }
    }
    cout<<ooo-maxa<<endl;
}








