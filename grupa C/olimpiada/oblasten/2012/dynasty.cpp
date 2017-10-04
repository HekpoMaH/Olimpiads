#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
struct karton
{
    string f,s;
};
karton k[10003];
int ns,n,nb[20000][20000],vl[24000],x,y,md,cd;
string num[24000],smd;
int findnum(string given)
{
    int l=0;
    for(int i=1;i<=ns;i++)if(num[i]==given){l=i;break;}
    if(l!=0)return l;
    ns++;
    num[ns]=given;
    return ns;
}
void dfs(int node,int dept)
{
    if(cd<dept)cd=dept;
    for(int i=1;i<=ns;i++)
    {
        if(nb[node][i]==1)dfs(i,dept+1);
    }
}
bool srav(string a,string b)
{
    if(a.size()>b.size())return true;
    if(a.size()<b.size())return false;
    if(a>b)return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>k[i].f>>k[i].s;
        x=findnum(k[i].s);
        y=findnum(k[i].f);
        nb[y][x]=1;
    }
    for(int i=1;i<=ns;i++)
    {
        for(int j=1;j<=ns;j++)
        {
            if(nb[i][j]==1)vl[j]++;
        }
    }
    for(int i=1;i<=ns;i++)
    {
        if(vl[i]>1){cout<<num[i]<<endl;return 0;}
    }
    for(int i=1;i<=ns;i++)
    {
        cd=0;
        dfs(i,0);
        //cout<<"i="<<i<<endl;
        //cout<<"cd="<<cd<<" "<<"md="<<md<<endl;
        //cout<<"num[i]="<<num[i]<<" "<<"smd="<<smd<<" "<<"srav="<<srav(num[i],smd)<<endl;
        if(cd>md||(cd==md&&srav(num[i],smd)==true))
        {
            md=cd;
            smd=num[i];
        }
    }
    cout<<smd<<endl;
    return 0;
}