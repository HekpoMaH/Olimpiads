#include<iostream>
using namespace std;
int a[100006],n,k,l,r,mn=999999,ml=-1,mr=0,used[100006],br,la;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    l=0;r=0;
    while(r<n&&br<k)
    {
        r++;
        //cout<<r<<endl;
        if(used[a[r]]==0)br++;
        used[a[r]]++;
    }
    //cout<<br<<endl;
    if(br<k){cout<<-1<<" "<<-1<<endl;return 0;}
    while(l<r&&br==k)
    {
        l++;
        if(used[a[l]]==1)break;
        used[a[l]]--;
    }
    //cout<<l<<" "<<r<<" "<<br<<endl;
    cout<<l<<" "<<r<<endl;
    return 0;
}