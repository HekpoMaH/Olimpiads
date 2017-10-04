#include<iostream>
#include<cmath>
using namespace std;
long long n,a,b,c,x,xx,s,d;
int main()
{
    cin>>n;a=1;
    for(int i=1;i<=9*18;i++)
    {
        b=i;
        c=-n;
        d=sqrt(b*b-4*a*c);
        if(d*d==b*b-4*a*c)
        {
            x=-b+d;x/=2*a;xx=x;
            while(x!=0)
            {
                s+=x%10;
                x/=10;
            }
            if(s==i){cout<<xx<<endl;return 0;}
            x=-b-d;x/=2*a;xx=x;
            while(x!=0)
            {
                s+=x%10;
                x/=10;
            }
            if(s==i){cout<<xx<<endl;return 0;}
        }
    }
    cout<<"-1"<<endl;
    return 0;
}
