#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100009],s[100009];
long long mn=100009*1009,mni;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=k;i++)
    {
        int sum=0;
        for(int j=i;j<=n;j+=k)
        {
            sum+=a[j];
            //cout<<j<<" "<<sum<<endl;
        }
        //cout<<"----"<<endl;
        if(mn>sum)mn=sum,mni=i;
    }
    cout<<mni<<endl;
}
