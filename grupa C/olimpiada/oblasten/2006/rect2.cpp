#include<iostream>
using namespace std;
int n,a[8011],b[8011];
long long mxs,sum,mn;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        mn=b[i];
        sum=a[i];
        if(mn*sum>mxs)mxs=mn*sum;
        for(int j=i+1;j<=n;j++)
        {
            if(b[j]<mn)mn=b[j];
            sum+=a[j];
            if(mn*sum>mxs)mxs=mn*sum;
        }
    }
    cout<<mxs<<endl;
    return 0;
}