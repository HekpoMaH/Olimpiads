#include<bits/stdc++.h>
using namespace std;
int n;
int k,t,c,at=0;
int a[109],b[109],br;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<(1<<n);i++)
    {
        t=0;c=0;
        //br=0;
        for(int j=1;j<=n;j++)
        {
            if(i&(1<<(j-1)))
            {
                //br++;
                t+=a[j];
                c+=b[j];
            }
        }
        //cout<<i<<" "<<t<<" "<<c<<endl;
        if(t/c==k&&t%c==0&&t!=0)
        {
            if(t>at)
            {
                at=t;
                //cout<<t<<" "<<c<<" "<<i<<endl;
            }
        }
    }
    if(at!=0)cout<<at<<endl;
    else cout<<-1<<endl;
}
