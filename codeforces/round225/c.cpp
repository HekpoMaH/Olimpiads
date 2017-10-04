#include<bits/stdc++.h>
using namespace std;
int a[200009];
int br;
long long ans;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)br++;
        else ans+=br;
    }
    cout<<ans<<endl;
}
