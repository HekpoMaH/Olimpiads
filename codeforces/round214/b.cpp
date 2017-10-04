#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100009],s[100009];
long long mn=100009*1009,mni;
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        //s[i%k]+=a[i];
    }
    for(int i=k;i<n;i++)a[i%k]+=a[i];
    for(int i=0;i<k;i++)
    {
        if(mn>a[i])
        {
            mn=a[i];
            mni=i;
        }
    }
    cout<<mni+1<<endl;
}
