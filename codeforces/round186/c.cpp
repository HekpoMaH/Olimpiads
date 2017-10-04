#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
long long n;
string s;
long long kur[2000009],sums[2000009];
vector<long long> pedal;
long long logg(long long dad)
{
    long long br=0;
    while((1<<br)<dad)br++;
    return br;
}
int main()
{
    //cout<<logg(1)<<" "<<logg(2)<<" "<<logg(4)<<" "<<logg(16)<<" "<<logg(64)<<endl;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>kur[i];
    if(n==1){cout<<kur[1]<<endl;return 0;}
    sort(kur+1,kur+n+1);
    long long bn,sum=0;bn=n/4;
    for(int i=n;i>=1;i/=4)
    {
        for(int j=n;j>=n-i+1;j--)
        sums[i]+=kur[j];
    }
    //for(int i=n;i>=1;i/=4)cout<<i<<" "<<sums[i]<<endl;
    for(int i=n;i>=1;i/=4)
    {
        sum+=sums[i]*logg(i)/4;
        //cout<<i<<" "<<sums[i]<<" "<<logg(i)/2<<endl;
        bn--;
    }
    sum+=sums[1];
    cout<<sum<<endl;
}
