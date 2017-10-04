#include<bits/stdc++.h>
using namespace std;
int n,a[1009];
int br;
long long sum1,sum2;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int lef=1,righ=n;
    while(lef<=righ)
    {
        if(br%2==0)
        {
            if(a[lef]>a[righ])
            {
                sum1+=a[lef];
                lef++;
            }
            else sum1+=a[righ],righ--;
        }
        else
        {
            if(a[lef]>a[righ])
            {
                sum2+=a[lef];
                lef++;
            }
            else sum2+=a[righ],righ--;
        }
        br++;
    }
    cout<<sum1<<" "<<sum2<<endl;
    return 0;
}
