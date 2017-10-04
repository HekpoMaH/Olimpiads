#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long sum;
long long a[3000006],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum+=abs(a[i]-i);
    cout<<sum<<endl;
}
