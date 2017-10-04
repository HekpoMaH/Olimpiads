#include<iostream>
using namespace std;
int n;
int mem[100][100];
int go(int x,int x1)
{
    if(mem[x][x1]!=0)return mem[x][x1];
    if(x==0&&x1<2)return mem[x][x1]=-1;
    if((!x&&x1==2)||(x1==0&&x==2))return mem[x][x1]=1;
    if(x>=2&&go(x-2,x1)==-1)return mem[x][x1]=1;
    if(x1>=2&&go(x,x1-2)==-1)return mem[x][x1]=1;
    if(x>=1&&x1>=1&&go(x-1,x1-1)==-1)return mem[x][x1]=1;
    if(x>0&&go(x-1,x1+2)==-1)return mem[x][x1]=1;
    return mem[x][x1]=-1;
}
int main()
{
    for(int i=1;i<=30;i++)cout<<go(i,0)<<" ";cout<<endl;
}
