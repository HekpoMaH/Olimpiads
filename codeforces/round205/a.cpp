#include<bits/stdc++.h>
using namespace std;
int n,s1,s2,a,b,br;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        s1+=a;s2+=b;
        if(a%2+b%2==1)br++;
    }
    if(s1%2+s2%2==0){cout<<0<<endl;return 0;}
    if(br==0||n==1){cout<<-1<<endl;return 0;}
    if(s1%2+s2%2==1){cout<<-1<<endl;return 0;}
    cout<<1<<endl;
}
