#include<iostream>
#include<algorithm>
using namespace std;
long long a[100002],n,k,b[100005],l,r,m,mx,mn;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        l=1;r=i;
        while(l<=r)
        {
            m=(l+r)/2;
            if(a[i]*(i-m)+b[m-1]-b[i-1]<=k)
            {
                if(i-m+1>mx)
                {
                    mx=i-m+1;
                    mn=a[i];
                }
                r=m-1;
            }
            else l=m+1;
        }
    }
    cout<<mx<<" "<<mn<<endl;
    return 0;
}
