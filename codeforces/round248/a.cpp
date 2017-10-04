#include<bits/stdc++.h>
using namespace std;
const int nmax=100009;
int n,a[nmax],m;
long long ans,mx,ii,sum;
map<pair<int,int>, long long> mp;
map<int,long long> mp2,mp3;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<m;i++)
    {
        mp2[a[i]]+=abs(a[i]-a[i+1]);
        mp2[a[i+1]]+=abs(a[i]-a[i+1]);
       // sum+=abs(a[i]-a[i+1]);
    }
    for(int i=1;i<=n;i++)
    {
        if(mp2[i]>mx)mx=mp2[i],ii=i;
        cout<<mp2[i]<<" ";
    }cout<<"\n";
    for(int i=1;i<m;i++)
    {
        if(a[i]==ii)mp3[a[i+1]]+=abs(a[i]-a[i+1]);
        if(a[i+1]==ii)mp3[a[i]]+=abs(a[i]-a[i+1]);
    }
    for(int i=1;i<=n;i++)cout<<mp3[i]<<" ";cout<<"\n";
    cout<<sum<<"\n";
}
/*
1000 5
1 1000 2 1 2
merge 1 2
999

3 9
1 2 3 3 3 2 1 3 3 3
*/
