#include<bits/stdc++.h>
//n=(m+m+k-1)/2*k
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=2;i*i<2*n;i++)if((2*n)%i==0&&(2*n/i-i+1)%2==0)ans++;
    cout<<ans<<endl;
}
