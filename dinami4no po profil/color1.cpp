#include<bits/stdc++.h>
using namespace std;
int d[3][3];
int a[3][3];
long long m;
int ost;
void umn(int x1[][3],int x2[][3])
{
    //cout<<x2<<endl;
    int x3[3][3];
    memset(x3,0,sizeof(x3));
    x3[1][1]=(x1[1][1]*x2[1][1]+x1[1][2]*x2[2][1])%ost;
    x3[1][2]=(x1[1][1]*x2[1][2]+x1[1][2]*x2[2][2])%ost;
    x3[2][1]=(x1[2][1]*x2[1][1]+x1[2][2]*x2[2][1])%ost;
    x3[2][2]=(x1[2][1]*x2[1][2]+x1[2][2]*x2[2][2])%ost;
    for(int i=1;i<=2;i++)for(int j=1;j<=2;j++)x1[i][j]=x3[i][j];
}
void stepen(int x[][3],long long p)
{
    int ans[3][3];
    for(int i=1;i<=2;i++)for(int j=1;j<=2;j++)
    {
        if(i==j)ans[i][j]=1;
        else ans[i][j]=0;
    }
    while(p!=0)
    {
        if(p&1)umn(ans,x);
        umn(x,x);
        p>>=1;
    }
    for(int i=1;i<=2;i++)for(int j=1;j<=2;j++)x[i][j]=ans[i][j];
}
int main()
{
    cin>>m>>ost;
    d[1][1]=1;d[1][2]=2;d[2][1]=1;d[2][2]=1;
    //umn(d,d);
    //cout<<d[1][1]<<endl;
    stepen(d,m);
    a[1][1]=1;a[1][2]=2;
    umn(a,d);
    cout<<a[1][1]<<endl;

}
