#include<iostream>
#include<cstring>
using namespace std;
long long n;
short int mem[1000000000],mov[100000000];
int go(long long x)
{
    /*cout<<x<<endl;
    if(x<=1000000000&&mem[x]!=0)return mem[x];
    if(go(x/2)==-1&&x<=1000000000){mov[x]=1;return mem[x]=1;}
    if(go(x/10)==-1&&x<=1000000000){mov[x]=2;return mem[x]=1;}
    if(x<=1000000000)return mem[x]=-1;*/
    if(x==0)return -1;
    if(go(x/2)==-1)return 1;
    if(go(x/10)==-1)return 1;
    return -1;
}
int main()
{
    for(int i=1;i<=4;i++){cin>>n;memset(mov,0,sizeof(mov));memset(mem,0,sizeof(mem));mem[0]=-1;if(go(n/2)==-1){cout<<1;}else if(go(n/10)==-1){cout<<2;}else cout<<0;}
}
