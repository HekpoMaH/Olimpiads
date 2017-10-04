#include<iostream>
#include<algorithm>
using namespace std;
int a[10000];
long long n,i1,i2,br,sum;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        i1=i+1;i2=n;
        while(i1<i2)
        {
            sum=a[i]+a[i1]+a[i2];
            //cout<<sum<<endl;
            if(sum==0)br++,i1++;
            if(sum<0)i1++;
            if(sum>0)i2--;
        }
    }
    cout<<br<<endl;
}
//10
//2 -5 2 3 -4 7 -4 0 1 -6
