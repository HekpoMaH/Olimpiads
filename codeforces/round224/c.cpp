#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[100009],dif[100009];
set<ll> ndif;
set<ll> ans;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int l=1;
    for(int i=1;i<n;i++)
    {
        dif[i]=a[i+1]-a[i];
        ndif.insert(dif[i]);
    }
    if(ndif.size()==0)
    {
        cout<<-1<<"\n";
        return 0;
    }
    if(ndif.size()==1)
    {
        ans.insert(a[1]-dif[1]);
        ans.insert(a[n]+dif[1]);
        if(n==2)
        {
            if((a[n]-a[1])%2==0)ans.insert(a[n]-(a[n]-a[1])/2);
        }
        cout<<ans.size()<<"\n";
        for(set<ll>::iterator i=ans.begin();i!=ans.end();i++)cout<<*i<<" ";cout<<"\n";
        return 0;
    }
    if(ndif.size()>=3)
    {
        cout<<0<<"\n";
        return 0;
    }
    //cout<<ndif.size()<<endl;
    if(ndif.size()==2)
    {
        l=1;
        for(int i=1;i<n-1;i++)
        {//cout<<"dif="<<dif[i]<<endl;
            if(i>1&&dif[i]!=dif[i-1]&&dif[i]!=dif[i+1])
            {

                if(dif[i]%2==0&&dif[i]!=0)
                {
                    ans.insert(dif[i]/2+a[i]);

                }
                l=0;
            }

        }
        //cout<<l<<endl;
        //cout<<"dif1="<<dif[1]<<endl;
        if(dif[1]!=dif[2])
        {
            if(dif[1]%2==0&&dif[1]!=0)
                {   //cout<<"d="<<dif[1]<<"\n";
                    if(ndif.find(dif[1]/2)!=ndif.end())ans.insert(dif[1]/2+a[1]);
                    l=0;
                }
        }
        //cout<<"D="<<dif[n-1]<<endl;
        if(dif[n-1]!=dif[n-2])
        {
            if(dif[n-1]%2==0&&dif[n-1]!=0)
                {//cout<<"d="<<dif[n-1]<<endl;
                    if(ndif.find(dif[n-1]/2)!=ndif.end())ans.insert(dif[n-1]/2+a[n-1]);

                    l=0;
                }
        }
        if(ans.size()==1)
        {cout<<ans.size()<<"\n";
        for(set<ll>::iterator i=ans.begin();i!=ans.end();i++)cout<<*i<<" ";if(ans.size()!=0)cout<<"\n";}
        else cout<<0<<endl;
        return 0;
    }
}
