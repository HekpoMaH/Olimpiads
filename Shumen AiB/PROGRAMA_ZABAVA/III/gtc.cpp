//guestthatcar
#include<iostream>
using namespace std;
long long a[1002][1002];
int n,m;
long long sumrow[1002],sumcol[1002],md=996419992332268928,mx,my,md2=996419233299268928;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            sumrow[i]+=a[i][j];
            sumcol[j]+=a[i][j];
        }
    }
    for(int i=1;i<=n+1;i++)
    {
        long long ss=0;
        for(int j=1;j<=n;j++)
        {
            ss+=((j-1)*4+2-(i-1)*4)*((j-1)*4+2-(i-1)*4)*sumrow[j];
        }
        if(ss<md)
        {
            md=ss;mx=i;
        }
    }
    //cout<<endl;
    for(int i=1;i<=m+1;i++)
    {
        long long ss=0;
        for(int j=1;j<=m;j++)
        {
            ss+=((j-1)*4+2-(i-1)*4)*((j-1)*4+2-(i-1)*4)*sumcol[j];
        }
        if(ss<md2)
        {
            md2=ss;my=i;
        }
    }
    //cout<<endl;
    cout<<md+md2<<endl;
    cout<<mx-1<<" "<<my-1<<endl;//WTF
}