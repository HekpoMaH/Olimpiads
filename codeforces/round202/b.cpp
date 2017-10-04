#include<bits/stdc++.h>
using namespace std;
int v,a[19],ma=9999999,p,q,t,w,ans[1000009];
int main()
{
    cin>>v;
    for(int i=1;i<=9;i++)
    {
        cin>>a[i];
        if(a[i]<=ma)
        {
            ma=a[i];
            p=i;
        }
    }
    t=0;
    w=0;
    if(v<ma){cout<<-1<<endl;return 0;}
    for(int i=1;i<=v/ma;i++)ans[i]=p;
    q=v%ma;
    for(int i=9;i>p;i--)
    {
        for(int j=1;j<=v/ma;j++)
        {
            if(a[i]<=ma+q&&i>ans[j])
            {
                ans[j]=i;
                q=(ma+q)-a[i];
                if(q==0)break;
            }
        }
    }
    for(int i=1;i<=v/ma;i++)
    cout<<ans[i];cout<<endl;
}
