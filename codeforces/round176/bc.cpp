#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
ll n,k;
ll l=2,r,br, sum,n1,k1;
ll idx;
ll sss(ll fi,ll se)
{
    ll broi=se-fi+1;//cout<<fi<<" "<<se<<" "<<broi<<endl;
    if(broi%2==0)
    {
        return (fi+se)*broi/2-(broi-1);
    }

    return (fi+se-1)*(broi-1)/2+se-(broi-1);
}
int main()
{
    cin>>n>>k;if(n==1){cout<<0<<endl;return 0;}n1=n;
    if(k>=n){cout<<1<<endl;return 0;}k1=k;
    //sum/=k-1;
    r=k1;
    //cout<<sss(2,k1)<<" "<<sss(3,k1)<<" "<<sss(k-5,k1)<<endl;
    ll mid;
    ll ans=-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        //cout<<mid<<" "<<sss(mid,k1)<<endl;
        //if(sss(mid,k1)<0){cout<<"ERR"<<endl;return 0;}
        if(sss(mid,k1)>=n1){ans=k1-mid+1;l=mid+1;}
        else r=mid-1;
    }
    cout<<ans<<endl;;

}
//499999999500000001 1000000000

