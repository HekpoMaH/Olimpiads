#include<bits/stdc++.h>
using namespace std;
int a[10009],uk1,uk2,luk,sum;
int n;
long long br;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        uk1=i+1,uk2=n;luk=n+1;
        while(uk1<uk2)
        {
            sum=a[i]+a[uk1]+a[uk2];
            if(sum==0)
            {
                if(a[uk1]==a[uk2])
                {
                    br+=uk2-uk1;
                    uk1++;
                }
                else
                {
                    if(luk>uk2)
                    {
                        luk=uk2;
                        while(luk-1>=1&&a[luk-1]==a[uk2])luk--;
                    }
                    br+=uk2-luk+1;
                    uk1++;
                }
            }
            else if(sum<0)uk1++;
            else if(sum>0)uk2--;

        }
    }
    cout<<br<<endl;
}
