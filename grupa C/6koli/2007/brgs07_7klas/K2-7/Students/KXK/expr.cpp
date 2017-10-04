#include<iostream>
#include<string>
using namespace std;
string a,b;
int c,d,n,m;
void eq()
{
    int o,i;
    if(m>n)
    {
        o=m-n;
        n=m;
        string r2="";
        for(i=0;i<o;i++)
        r2+='0';
        r2+=a;
        a=r2;
    }
    else
    {
        o=n-m;
        m=n;
        string r2="";
        for(i=0;i<o;i++)
        r2+='0';
        r2+=b;
        b=r2;
    }
}
int main()
{
    cin>>a>>c>>b>>d;
    n=a.size();
    m=b.size();
    int i,ost;
    if(c==0)
    {
        a="0";
        n=1;
    }
    else
    {
    ost=0;
    for(i=n-1;i>=0;i--)
    {
        int x=((int)a[i]-48)*c+ost;
        ost=x/10;
        x=x%10;
        a[i]=(char)x+48;
    }
    if(ost)
    {
        string r="";
        char f=(char)ost+48;
        r+=f;
        r+=a;
        a=r;
        n++;
    }
    }
    ost=0;
    if(d==0)
    {
        m=1;
        b="0";
    }
    else
    {
    if(d==10)
    {
        b+='0';
        m++;
    }
    else
    {
       for(i=m-1;i>=0;i--)
       {
            int x=((int)b[i]-48)*d+ost;
            ost=x/10;
            x=x%10;
            b[i]=(char)x+48;
        } 
        if(ost)
        {
            string r="";
            char f=(char)ost+48;
            r+=f;
            r+=b;
            b=r;
            m++;
        }
    }
    }
    if(n!=m) eq();
    ost=0;
    for(i=n-1;i>=0;i--)
    {
        int ra,rb,rty;
        ra=(int)a[i]-48;
        rb=(int)b[i]-48;
        rty=ra+rb+ost;
        ost=rty/10;
        rty%=10;
        a[i]=(char)rty+48;
    }
    if(ost) cout<<1;
    cout<<a<<'\n';
    return 0;
}

    
