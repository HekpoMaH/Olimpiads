#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
int n,k;
int l,r;
int s;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>r;s+=r-l+1;
    }
    if(s%k==0)cout<<0<<endl;
    else cout<<k-s%k<<endl;
}
