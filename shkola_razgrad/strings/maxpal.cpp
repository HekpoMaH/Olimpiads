#include<iostream>
#include<string>
using namespace std;
string s;
long long h1[100],h2[100],pr=29,mod=1000000009,pw[102],ms;
long long gth1(int l,int r)
{
    if(l==0)return h1[r];
    return (h1[r]+mod-(h1[l-1]*pw[r-l+1])%mod)%mod;
}
long long gth2(int l,int r)
{
    if(r==s.size()-1)return h2[l];
    return (h2[l]+mod-(h2[r+1]*pw[r-l+1])%mod)%mod;
}
bool check1(int ans,int id)
{
    long long a=gth1(id+1,id+ans);
    long long d=gth2(id-ans+1,id);
    if(a==d)return true;
    return false;
}
bool check2(int ans,int id)
{
    long long a=gth1(id+1,id+ans);
    long long d=gth2(id-ans,id-1);
    if(a==d)return true;
    return false;
}
void bs1(int idx)
{
    int lef=0,righ=min(idx+1,(int)(s.size()-1-idx)),mid;
    bool b;
    while(lef<=righ)
    {
        mid=(lef+righ)/2;
        b=check1(mid,idx);
        if(b==true&&mid*2>ms)ms=mid*2;
        if(b==true)lef=mid+1;
        else righ=mid-1;
    }
}
void bs2(int idx)
{
    int lef=0,righ=min(idx,(int)s.size()-idx-1),mid;
    bool b;
    while(lef<=righ)
    {
        mid=lef+righ;mid/=2;
        b=check2(mid,idx);
        if(b==true&&mid*2+1>ms)ms=mid*2+1;
        if(b==true)lef=mid+1;
        else righ=mid-1;
    }
}
int main()
{
    pw[0]=1;
    for(int i=1;i<=100;i++)pw[i]=(pw[i-1]*pr)%mod;
    cin>>s;
    h1[0]=(int)(s[0]-'a');
    h2[s.size()-1]=(int)(s[s.size()-1]-'a');
    for(int i=1;i<s.size();i++)
    {
        h1[i]=(h1[i-1]*pr+(int)(s[i]-'a'))%mod;
    }
    for(int i=s.size()-2;i>=0;i--)
    {
        h2[i]=(h2[i+1]*pr+(int)(s[i]-'a'))%mod;
    }
    for(int i=0;i<s.size()-1;i++)bs1(i);
    for(int i=0;i<s.size();i++)bs2(i);
    cout<<ms<<endl;
    return 0;
}