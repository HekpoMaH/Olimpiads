#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
x - broi ^
y - broi * i /
z - broi + i -
v - broi nezavisimi ()
*/
string inp,st,ft,gt;
unsigned long long ans=1;
unsigned long long fact(int n)
{
    int i;
    unsigned long long res=1;
    for(i=2;i<=n;++i)res*=i;
    return res;
}
unsigned long long solve(string u)
{
    unsigned long long p=1;
    int i,x=0,y=0,z=0;
    for(i=0;i<u.length();++i)
    {
        if(u[i]=='^')++x;
        if(u[i]=='*'||u[i]=='/')++y;
        if(u[i]=='+'||u[i]=='-')++z;
    }
    return p*fact(x)*fact(y)*fact(z);
}
int main()
{
    int i,j,k;
    int x=0,y=0,z=0,v=0;
    bool gts;
    cin>>inp;
    for(i=0;i<inp.length();++i)if(inp[i]=='^'||inp[i]=='+'||inp[i]=='-'||inp[i]=='*'||inp[i]=='/'||inp[i]=='('||inp[i]==')')st.push_back(inp[i]);
    for(i=0;i<st.length();++i)
    {
        for(j=i+1;j<st.length();++j)
        {
            if(st[i]=='('&&st[j]==')')
            {
                gts=true;
                for(k=i+1;k<j;++k)if(st[k]=='('||st[k]==')')gts=false;
            }
            if(gts)
            {
                ++v;
                ans*=solve(st.substr(i+1,j));
                st.erase(st.begin()+i,st.begin()+j+1);
            }
        }   
    }
    for(i=0;i<st.length();++i)
    {
        char e=st[i];
        if(e=='('||e==')')continue;
        for(j=i+1;j<st.length();++j)if(st[j]!=e)break;
        i=j-1;
        ft.push_back(e);
    }
    gt=ft;
    for(i=0;i<gt.length();++i)
    {
        if(gt[i]=='^')++x;
        if(gt[i]=='*'||gt[i]=='/')++y;
        if(gt[i]=='+'||gt[i]=='-')++z;
    }
    ans*=fact(x)*fact(y)*fact(z)*fact(v);
    cout<<ans<<'\n';
    return 0;
}
