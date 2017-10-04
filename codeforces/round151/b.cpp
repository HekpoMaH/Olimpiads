#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100009],used[200009],mx;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int sum=0;
    for(int i=1;i<=n;i++)sum+=a[i];
    sum/=n;
    int l=1,r=n,mm;
    while(l<r)
    {
        //cout<<l<<" "<<r<<endl;
        if(l>=1&&l<=n&&r>=1&&r<=n){mm=min(sum-a[l],a[r]-sum);
        a[l]+=mm;a[r]-=mm;
        if(a[l]==sum)l++;
        if(a[r]==sum)r--;}//for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
        //used[a[l]]++;used[a[l]]--;
    }
    for(int i=1;i<=n;i++)used[a[i]+100000]++;
    for(int i=0;i<=200000;i++)mx=max(mx,used[i]);
    cout<<mx<<endl;
}
