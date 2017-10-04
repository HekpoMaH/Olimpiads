#include<iostream>
#include<string>
using namespace std;
string s;
long long mn=1<<63;
/////
long long calc(int beg,int end)
{
    long long ret=0;
    int i;
    ret=s[beg]-'0';
    
    if(s[beg+1]=='-')
        ret-=s[beg+2]-'0';
    else
    if(s[beg+1]=='+')
        ret+=s[beg+2]-'0';
    else
    if(s[beg+1]=='*')
        ret*=s[beg+2]-'0';
      
    for(i=beg+4;i<end;i+=2)
    {
        if(s[i-1]=='-')
            ret-=s[i]-'0';
        else
        if(s[i-1]=='+')
            ret+=s[i]-'0';
        else
        if(s[i-1]=='*')
        {
            if(s[i-3]=='-')
            {
                ret+=s[i-2]-'0';
                ret-=(s[i-2]-'0')*(s[i]-'0');
            }else
            if(s[i-3]=='+')
            {
                ret-=s[i-2]-'0';
                ret+=(s[i-2]-'0')*(s[i]-'0');
            }else
            if(s[i-3]=='*')
                ret*=s[i]; 
        }
    }
    return ret;
}
long long big(int beg,int end)
{
    int i,l=0;
    long long x=-1*(1<<63);
    long long a,b;
    for(i=beg;i<end;i++)
        if(s[i]=='*')
        {
        }
    x=calc(beg,end);
    //cout<<"^"<<x<<endl;
        return x;
}
long long tiny(int beg,int end)
{
    int i,l=0;
    long long x=1<<63;
    long long a,b;
    for(i=beg;i<end;i++)
        if(s[i]=='-')
        {
            l=1;
            a=tiny(beg,i);
            b=big(i+1,end);
            if(a-b<x)
                x=a-b;
        }
    if(l)
    {
        //cout<<x<<endl;
        return x;
    }
    return calc(beg,end);
}
int main()
{
    cin>>s;
    int sz;
    sz=s.size();
    cout<<tiny(0,sz)<<endl;
    return 0;
}
