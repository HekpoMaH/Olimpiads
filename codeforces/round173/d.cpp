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
    if(n==1)
    {
        cin>>x;
        if(x!=0)cout<<"BitLGM"<<endl;
        else cout<<"BitAryo"<<endl;
        return 0;
    }
    if(n==3)
    {
        cin>>x>>y>>z;
        if(x^y^z)
        {
        cout<<"BitLGM"<<endl;
        }
        else cout<<"BitAryo"<<endl;
        return 0;
    }
    cin>>x>>y;
    memset(mem,-1,sizeof(mem));
    if(go(x,y))cout<<"BitLGM"<<endl;
    else cout<<"BitAryo"<<endl;
}
