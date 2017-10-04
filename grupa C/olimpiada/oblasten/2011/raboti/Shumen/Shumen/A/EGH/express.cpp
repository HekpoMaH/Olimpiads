#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s;
int q[50];
void solve()
{
    int n,i,j=0,a,b,c,d,e,g,h;
    cin>>s;
    n=s.size();
    for(i=0;i<n;i+=2)
    {
        q[j]=s[i]-48;
        j++;
    }
    for(i=n-1;i>0;i--)
    {
        if(s[i-1]=='*')
        {
            if(s[i-3]=='+')
            {
                a=q[i/2];
                b=q[(i-2)/2];
                c=q[(i-4)/2];
                if(((c+b)*a)>(c+(a*b))) { d=c+(a*b); q[(i-4)/2]=d;
                q[(i-2)/2]=q[i/2]=0; i-=3;}
                else {d=(c+b)*a; q[(i-4)/2]=d;
                q[(i-2)/2]=q[i/2]=0; i-=3;}
            }
            if(s[i-3]=='-')
            {
                a=q[i/2];
                b=q[(i-2)/2];
                c=q[(i-4)/2];
                if(((c-b)*a)>(c-(a*b))) { d=c-(a*b); q[(i-4)/2]=d;
                q[(i-2)/2]=q[i/2]=0;
                i-=3;}
                else {d=(c-b)*a; q[(i-4)/2]=d;
                q[(i-2)/2]=q[i/2]=0; i-=3;}
            }
        }
        else
        {
            if(s[i-1]=='+')
            if(s[i-3]=='+'||s[i-3]=='-'||i-3<0)
            {
                a=q[(i-2)/2];
                b=q[i/2];
                d=a+b;
                q[(i-2)/2]=d;
                q[i/2]=0;
                i--;
            }
            if(s[i-1]=='-')
            if(s[i-3]=='+'||s[i-3]=='-'||i-3<0)
            {
                a=q[(i-2)/2];
                b=q[i/2];
                d=a-b;
                q[(i-2)/2]=d;
                q[i/2]=0;
                i--;

            }
        }
        if(s[i-1]=='+'&&s[i-3]=='*')
        {
            if(s[i-5]=='+')
            {
                a=q[i/2];
                b=q[(i-2)/2];
                c=q[(i-4)/2];
                e=q[(i-6)/2];
                g=min(e+(c*b)+a,(e+c)*(b+a));
                h=min(((e+c)*b)+a,e+(c*(b+a)));
                d=min(g,h);
                q[(i-6)/2]=d;
                q[i/2]=q[(i-2)/2]=q[(i-4)/2]=0;
                i-=5;
            }
            else if(s[i-5]=='-')
            {
                a=q[i/2];
                b=q[(i-2)/2];
                c=q[(i-4)/2];
                e=q[(i-6)/2];
                g=min(e-(c*b)+a,(e-c)*(b+a));
                h=min(((e-c)*b)+a,e-(c*(b+a)));
                d=min(g,h);
                q[(i-6)/2]=d;
                q[i/2]=q[(i-2)/2]=q[(i-4)/2]=0;
                i-=5;
            }
            else
            {
                a=q[i/2];
                b=q[(i-2)/2];
                c=q[(i-4)/2];
                d=min((c*b)+a,c*(b+a));
                q[(i-4)/2]=d;
                q[i/2]=q[(i-2)/2]=0;
                i-=3;
            }
        }
        if(s[i-1]=='-'&&s[i-3]=='*')
        {
            if(s[i-5]=='+')
            {
                a=q[i/2];
                b=q[(i-2)/2];
                c=q[(i-4)/2];
                e=q[(i-6)/2];
                g=min(e+(c*b)-a,(e+c)*(b-a));
                h=min(((e+c)*b)-a,e+(c*(b-a)));
                d=min(g,h);
                q[(i-6)/2]=d;
                q[i/2]=q[(i-2)/2]=q[(i-4)/2]=0;
                i-=5;
            }
            else if(s[i-5]=='-')
            {
                a=q[i/2];
                b=q[(i-2)/2];
                c=q[(i-4)/2];
                e=q[(i-6)/2];
                g=min(e-(c*b)-a,(e-c)*(b-a));
                h=min(((e-c)*b)-a,e-(c*(b-a)));
                d=min(g,h);
                q[(i-6)/2]=d;
                q[i/2]=q[(i-2)/2]=q[(i-4)/2]=0;
                i-=5;
            }
            else
            {
                a=q[i/2];
                b=q[(i-2)/2];
                c=q[(i-4)/2];
                d=min((c*b)-a,c*(b-a));
                q[(i-4)/2]=d;
                q[i/2]=q[(i-2)/2]=0;
                i-=3;
            }
        }
        if(s[i-1]=='*')
            if(s[i-3]=='*'||i-3<0)
            {
                a=q[(i-2)/2];
                b=q[i/2];
                d=a*b;
                q[(i-2)/2]=d;
                q[i/2]=0;
                i--;
            }
    }
    cout<<q[0]<<endl;
}
int main()
{
    solve();

return 0;
}