#include<bits/stdc++.h>
using namespace std;
long long n,a,b;
long long arr[100009],money1,money2;
int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        money1=arr[i]*a/b;
        long long l=0,r=arr[i];
        long long mid;
        money2=0;
        while(l<=r)
        {
            //cout<<l<<" "<<r<<endl;
            mid=(l+r)/2;//cout<<i<<" "<<mid<<" "<<l<<" "<<r<<endl;
            if(mid*a/b>=money1)
            {
                r=mid-1;
                money2=max(money2,arr[i]-mid);
            }
            else l=mid+1;
        }
        cout<<money2<<" ";
    }
    cout<<endl;
}
