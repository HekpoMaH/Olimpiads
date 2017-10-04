#include<bits/stdc++.h>
using namespace std;
int k,x,n,m;
string a,b,c;
int cntac(string x)
{
    int re=0;
    for(int i=1;i<x.size();i++)if(x[i]=='C'&&x[i-1]=='A')re++;
    return re;
}
int main()
{
    cin>>k>>x>>n>>m;
    cin>>a>>b;
    for(int i=3;i<=k;i++)
    {
        c=a;a=a+b;b=c;
        //cout<<a<<endl;
        cout<<"i="<<i<<" -> "<<cntac(a)<<endl;
    }
    //cout<<a<<endl;
}
//5 6 2 2
