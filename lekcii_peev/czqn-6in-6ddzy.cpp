#include<iostream>
#include<cstring>
using namespace std;
int n;
int x,y,z;
int mem[303][303];
int go(int a,int b)
{
    //cout<<a<<" "<<b<<endl;
    if(mem[a][b]!=-1)return mem[a][b];
    for(int da=1;da<=a;da++)
    {
        if(!go(a-da,b))return mem[a][b]=1;
    }
    for(int db=1;db<=b;db++)
    {
        if(!go(a,b-db))return mem[a][b]=1;
    }
    for(int d=1;d<=min(a,b);d++)
    {
        if(!go(a-d,b-d))return mem[a][b]=1;
    }
    return mem[a][b]=0;
}
int main()
{
    cin>>n;

    memset(mem,-1,sizeof(mem));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=100;j++)if(go(i,j)==0){cout<<i<<" "<<j<<endl;break;}
    }
}
