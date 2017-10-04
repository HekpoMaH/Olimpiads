#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;long long score=0;
void incs()
{
    if(a>=b&&a>=c)
    {
        score+=a;
        if(a>=1)a--;
    }
    else if(b>=a&&b>=c)
    {
        score+=b;
        if(b>=1)b--;
    }
    else if(c>=a&&c>=b)
    {
        score+=c;
        if(c>=1)c--;
    }
}
int main()
{

    cin>>a>>b>>c>>n;
    while(n--)incs();
    cout<<score<<endl;
}
