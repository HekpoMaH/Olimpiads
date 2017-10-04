#include<iostream>
#include<string>
using namespace std;
string s;
int br0,br1;
string ff;
bool cmp(string x,string y)
{
    if(x.size()>y.size())return true;
    if(x.sise()<y.size())return false;
    for(int i=0;i<x.size();i++)
    {
        if(x[i]<y[i])return true;
        if(x[i]>y[i]) return false;
    }
}
int substr(string &x,string y)
{
    int u1=x.size(),u2=y.size();
    while(u1>=0&&u2>=0)
    {

        if(x[u1]=='1'&&y[u2]=='0')ff+='1';
        if(x[u1]=='1'&&y[u2]=='1')ff+='0';
        if(x[u1]=='0'&&y[u2]=='0')ff+='0';
        if(x[u1]=='0'&&y[u2]=='1')
        {
            ff+='1';
            for(int i=u1;i>=0;i--)
            {
                if(x[i]=='0')x[i]='1';
                else {x[i]='0';break;}
            }
        }
        u1--;u2--;
    }
    int brr=0;
    //cout<<ff<<endl;
    for(int i=0;i<ff.size();i++)if(ff[i]=='1')brr++;
    x=ff;
    return brr+1
}
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++){if(s[i]=='0')br0++;else br1++;}
    if(br0==0){cout<<2<<endl;return 0;}
    if(br1==1){cout<<1<<endl;return 0;}
    string s1="1";
    for(int i=0;i<s.size();i++)s1+='0';
    while(cmp(s1,s)==true)
    {

    }
}
