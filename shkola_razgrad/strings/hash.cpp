#include<iostream>
#include<string>
using namespace std;
unsigned long long h1[100005],h2[100005],p=29,mod=122345540;
string a,b;
unsigned long long pp,br;
int main()
{
    cin>>a>>b;
    h1[0]=(int)(a[0]-'a'+1);
    for(int i=1;i<a.size();i++)
    {
        h1[i]=h1[i-1]*p;
        h1[i]+=(int)(a[i]-'a'+1);
        h1[i]%=mod;
    }
    h2[0]=(int)(b[0]-'a'+1);
    for(int i=1;i<b.size();i++) 
    {
        h2[i]=h2[i-1]*p;
        h2[i]+=(int)(b[i]-'a'+1);
        h2[i]%=mod;
    }
    for(int i=0;i<a.size();i++)cout<<h1[i]<<" ";
    cout<<endl;
    for(int i=0;i<b.size();i++)cout<<h2[i]<<" ";
    cout<<endl;
    for(int i=0;i<=a.size()-b.size()+1;i++)
    {
        pp=1;
        for(int j=0;j<b.size();j++)pp*=p,pp%=mod;
        if(h2[b.size()-1]==(h1[i+b.size()-1]+mod-(h1[i-1]*pp%mod))%mod)br++;
    }
    cout<<br<<endl;
    return 0;
}