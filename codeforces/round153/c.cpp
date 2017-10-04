#include<iostream>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;
long long a[100003],n,r,d,br,hh=1;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>d;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }r=0;long long x;
    for(int i=0;i<n;i++) {
		while(r<n&&a[r]-a[i]<=d)r++;
		x=r-i-1;
		if(x)br+=x*(x-1)/2;
	}
    cout<<br<<endl;
    return 0;
}
