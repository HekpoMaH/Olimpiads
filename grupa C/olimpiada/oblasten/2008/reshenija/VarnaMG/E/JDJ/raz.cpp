#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int N,a,b,c,d,i,r;
    cin>>N;
    a=1;
    b=N;
    r=b-a;
    for(i=2;i<=N/2;i++)
    {
                    if(N%i==0)
                    {
                                 c=i;
                                 d=N/i;
                    } 
                    if(fabs(c-d)<r) r=fabs(c-d);
                    
    }
    
    if(b-a>fabs(c-d))
    {
                     if(c>d) cout<<d<<" "<<c<<endl;
                     else cout<<d<<" "<<c<<endl;
    }
    else cout<<a<<" "<<b;
    return 0;
}
