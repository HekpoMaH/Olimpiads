#include<bits/stdc++.h>
using namespace std;
int a[1000];
int n,c,pr=0;
int main()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        //cin>>a[i];
        if(i<n)
        {
            //cout<<a[i]<<" "<<a[i+1]<<" "<<c<<endl;
            if(a[i]-a[i+1]-c>pr)pr=a[i]-a[i+1]-c;
        }
    }
    cout<<pr<<endl;
}
