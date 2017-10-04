#include<iostream>
using namespace std;
int mem[1000][1000],mov[1000][1000];
int n,p,q;
int go(int x,int x1)
{
    //cout<<x<<" "<<x1<<endl;
    if(mem[x][x1]!=0)return mem[x][x1];
    for(int i=q;i>=p;i--)
    {
        if(i!=x1&&x-i>=0&&go(x-i,i)==-1){mov[x][x1]=i;return mem[x][x1]=1;}
    }
    return mem[x][x1]=-1;
}
int main()
{
    cin>>n>>p>>q;for(int i=0;i<=n;i++)mem[0][n]=-1;
    if(go(n,0)==1)
    {
        cout<<"I win "<<mov[n][0]<<endl;
    }
    else cout<<0<<endl;
}
